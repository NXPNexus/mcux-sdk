/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
/*                                                                          */
/* NXP Confidential. This software is owned or controlled by NXP and may    */
/* only be used strictly in accordance with the applicable license terms.   */
/* By expressly accepting such terms or by downloading, installing,         */
/* activating and/or otherwise using the software, you are agreeing that    */
/* you have read, and that you agree to comply with and are bound by, such  */
/* license terms. If you do not agree to be bound by the applicable license */
/* terms, then you may not retain, install, activate or otherwise use the   */
/* software.                                                                */
/*--------------------------------------------------------------------------*/

/**
 * @file  mcuxClRsa_sign_pss_sha2_256_example.c
 * @brief Example of using function mcuxClRsa_sign to perform the RSA signature generation with
 *      EMSA-PSS-SIGN padding scheme according to PKCS #1 v2.2.
 *
 * @example mcuxClRsa_sign_pss_sha2_256_example.c
 * @brief Example of using function mcuxClRsa_sign to perform the RSA signature generation with
 *      EMSA-PSS-SIGN padding scheme according to PKCS #1 v2.2.
 */

#include <mcuxClSession.h>          // Interface to the entire mcuxClSession component
#include <mcuxClExample_Session_Helper.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection
#include <mcuxClRandom.h>           // Interface to the entire mcuxClRandom component
#include <mcuxClRsa.h>              // Interface to the entire mcuxClRsa component
#include <mcuxClCore_Examples.h>
#include <mcuxClEls.h> // Interface to the entire mcuxClEls component
#include <mcuxClExample_ELS_Helper.h>

/**********************************************************/
/* Example test vectors                                   */
/**********************************************************/

#define RSA_KEY_BIT_LENGTH         (2048u)                   ///< The example uses a 2048-bit key
#define RSA_KEY_BYTE_LENGTH        (RSA_KEY_BIT_LENGTH / 8u) ///< Converting the key-bitlength to bytelength
#define RSA_MESSAGE_DIGEST_LENGTH  (32u)                     ///< The example uses a Sha2-256 digest, which is 32 bytes long
#define RSA_PSS_SALT_LENGTH        (0u)                      ///< The salt length is set to 0 in this example

/**
 * @brief Example value for public RSA modulus N.
 */
static const uint8_t modulus[RSA_KEY_BYTE_LENGTH] __attribute__ ((aligned (4))) = {
    0xd3U, 0x24U, 0x96U, 0xe6U, 0x2dU, 0x16U, 0x34U, 0x6eU, 0x06U, 0xe7U, 0xa3U, 0x1cU, 0x12U, 0x0aU, 0x21U, 0xb5U,
    0x45U, 0x32U, 0x32U, 0x35U, 0xeeU, 0x1dU, 0x90U, 0x72U, 0x1dU, 0xceU, 0xaaU, 0xd4U, 0x6dU, 0xc4U, 0xceU, 0xbdU,
    0x80U, 0xc1U, 0x34U, 0x5aU, 0xffU, 0x95U, 0xb1U, 0xddU, 0xf8U, 0x71U, 0xebU, 0xb7U, 0xf2U, 0x0fU, 0xedU, 0xb6U,
    0xe4U, 0x2eU, 0x67U, 0xa0U, 0xccU, 0x59U, 0xb3U, 0x9fU, 0xfdU, 0x31U, 0xe9U, 0x83U, 0x42U, 0xf4U, 0x0aU, 0xd9U,
    0xafU, 0xf9U, 0x3cU, 0x3cU, 0x51U, 0xcfU, 0x5fU, 0x3cU, 0x8aU, 0xd0U, 0x64U, 0xb8U, 0x33U, 0xf9U, 0xacU, 0x34U,
    0x22U, 0x9aU, 0x3eU, 0xd3U, 0xddU, 0x29U, 0x41U, 0xbeU, 0x12U, 0x5bU, 0xc5U, 0xa2U, 0x0cU, 0xb6U, 0xd2U, 0x31U,
    0xb6U, 0xd1U, 0x84U, 0x7eU, 0xc4U, 0xfeU, 0xaeU, 0x2bU, 0x88U, 0x46U, 0xcfU, 0x00U, 0xc4U, 0xc6U, 0xe7U, 0x5aU,
    0x51U, 0x32U, 0x65U, 0x7aU, 0x68U, 0xecU, 0x04U, 0x38U, 0x36U, 0x46U, 0x34U, 0xeaU, 0xf8U, 0x27U, 0xf9U, 0xbbU,
    0x51U, 0x6cU, 0x93U, 0x27U, 0x48U, 0x1dU, 0x58U, 0xb8U, 0xffU, 0x1eU, 0xa4U, 0xc0U, 0x1fU, 0xa1U, 0xa2U, 0x57U,
    0xa9U, 0x4eU, 0xa6U, 0xd4U, 0x72U, 0x60U, 0x3bU, 0x3fU, 0xb3U, 0x24U, 0x53U, 0x22U, 0x88U, 0xeaU, 0x3aU, 0x97U,
    0x43U, 0x53U, 0x59U, 0x15U, 0x33U, 0xa0U, 0xebU, 0xbeU, 0xf2U, 0x9dU, 0xf4U, 0xf8U, 0xbcU, 0x4dU, 0xdbU, 0xf8U,
    0x8eU, 0x47U, 0x1fU, 0x1dU, 0xa5U, 0x00U, 0xb8U, 0xf5U, 0x7bU, 0xb8U, 0xc3U, 0x7cU, 0xa5U, 0xeaU, 0x17U, 0x7cU,
    0x4eU, 0x8aU, 0x39U, 0x06U, 0xb7U, 0xc1U, 0x42U, 0xf7U, 0x78U, 0x8cU, 0x45U, 0xeaU, 0xd0U, 0xc9U, 0xbcU, 0x36U,
    0x92U, 0x48U, 0x3aU, 0xd8U, 0x13U, 0x61U, 0x11U, 0x45U, 0xb4U, 0x1fU, 0x9cU, 0x01U, 0x2eU, 0xf2U, 0x87U, 0xbeU,
    0x8bU, 0xbfU, 0x93U, 0x19U, 0xcfU, 0x4bU, 0x91U, 0x84U, 0xdcU, 0x8eU, 0xffU, 0x83U, 0x58U, 0x9bU, 0xe9U, 0x0cU,
    0x54U, 0x81U, 0x14U, 0xacU, 0xfaU, 0x5aU, 0xbfU, 0x79U, 0x54U, 0xbfU, 0x9fU, 0x7aU, 0xe5U, 0xb4U, 0x38U, 0xb5U
 };

/**
 * @brief Example value for private RSA exponent d.
 */
static const uint8_t exponent[RSA_KEY_BYTE_LENGTH] __attribute__ ((aligned (4))) = {
    0x15U, 0x5fU, 0xe6U, 0x60U, 0xcdU, 0xdeU, 0xaaU, 0x17U, 0x1bU, 0x5eU, 0xd6U, 0xbdU, 0xd0U, 0x3bU, 0xb3U, 0x56U,
    0xe0U, 0xf6U, 0xe8U, 0x6bU, 0x5aU, 0x3cU, 0x26U, 0xf3U, 0xceU, 0x7dU, 0xaeU, 0x00U, 0x8cU, 0x4eU, 0x38U, 0xa9U,
    0xa9U, 0x7fU, 0xa5U, 0x97U, 0xb2U, 0xb9U, 0x0aU, 0x45U, 0x10U, 0xd2U, 0x23U, 0x8dU, 0x3fU, 0x15U, 0x8aU, 0xb8U,
    0x91U, 0x97U, 0xfbU, 0x08U, 0xa5U, 0xb7U, 0x4cU, 0xfeU, 0x5cU, 0xc8U, 0xf1U, 0x3dU, 0x47U, 0x09U, 0x62U, 0x91U,
    0xd0U, 0x05U, 0x38U, 0xaaU, 0x58U, 0x93U, 0xd8U, 0x2dU, 0xceU, 0x55U, 0xb3U, 0x64U, 0x8cU, 0x6aU, 0x71U, 0x9aU,
    0xe3U, 0x87U, 0xdeU, 0xe5U, 0x5eU, 0xc5U, 0xbeU, 0xf0U, 0x89U, 0x76U, 0x3dU, 0xe7U, 0x1eU, 0x47U, 0x61U, 0xb7U,
    0x03U, 0xadU, 0x69U, 0x2eU, 0xd6U, 0x2dU, 0x7cU, 0x1fU, 0x4fU, 0x0fU, 0xf0U, 0x03U, 0xc1U, 0x67U, 0xebU, 0x62U,
    0xd2U, 0xc6U, 0x79U, 0xccU, 0x6fU, 0x13U, 0xb9U, 0x87U, 0xa1U, 0x42U, 0xf1U, 0x37U, 0x7aU, 0x40U, 0xbdU, 0xc0U,
    0xa0U, 0x36U, 0x60U, 0x72U, 0x94U, 0x40U, 0x14U, 0x63U, 0xa3U, 0x0eU, 0x82U, 0x91U, 0x2bU, 0x42U, 0x8aU, 0x1dU,
    0x3fU, 0x80U, 0xb5U, 0xd0U, 0xd3U, 0x3eU, 0xa8U, 0x4eU, 0x8bU, 0xb6U, 0x4cU, 0x36U, 0x22U, 0xb9U, 0xbeU, 0xe3U,
    0x56U, 0xf1U, 0x2cU, 0x6aU, 0x19U, 0x0eU, 0x55U, 0x7bU, 0xbfU, 0x25U, 0xe1U, 0x10U, 0x80U, 0x7bU, 0x85U, 0xcaU,
    0xd5U, 0x1bU, 0x39U, 0x87U, 0x57U, 0x08U, 0x06U, 0xbeU, 0x81U, 0xf3U, 0x71U, 0x3fU, 0x5dU, 0x17U, 0x40U, 0x74U,
    0x99U, 0xa5U, 0xdeU, 0xdaU, 0xc0U, 0xf3U, 0xe3U, 0xbcU, 0x79U, 0x96U, 0x35U, 0x95U, 0xf8U, 0xe0U, 0xcfU, 0x01U,
    0x29U, 0x1dU, 0xc1U, 0x02U, 0x09U, 0xc0U, 0x6eU, 0xb6U, 0x0eU, 0x2eU, 0x9cU, 0x47U, 0xecU, 0x91U, 0x42U, 0xedU,
    0xa5U, 0xf3U, 0xb7U, 0x0aU, 0xc6U, 0x7fU, 0x72U, 0xbfU, 0x52U, 0xb3U, 0x31U, 0x37U, 0xd1U, 0x49U, 0xb6U, 0xf6U,
    0x06U, 0xe4U, 0x59U, 0x61U, 0x7dU, 0xaaU, 0x8eU, 0x10U, 0x18U, 0xa8U, 0x14U, 0x1dU, 0x89U, 0x4eU, 0xcaU, 0xffU
};

/**
 * @brief Example value for Sha2-256 message digest.
 */
static const uint8_t message[RSA_MESSAGE_DIGEST_LENGTH] __attribute__ ((aligned (4))) = {
    0xf4U, 0x45U, 0x80U, 0x1eU, 0x0cU, 0xb8U, 0x99U, 0x26U, 0x2cU, 0x9bU, 0x9eU, 0x21U, 0x98U, 0x36U, 0x88U, 0x0dU,
    0x73U, 0xcaU, 0x2dU, 0x1bU, 0x0bU, 0x9cU, 0x15U, 0xfbU, 0x95U, 0x9cU, 0x90U, 0xebU, 0x12U, 0x12U, 0x34U, 0xe3U
};

/**
 * @brief Expected signature
 */
static const uint8_t referenceSignature[RSA_KEY_BYTE_LENGTH] __attribute__ ((aligned (4))) = {
    0x89U, 0x01U, 0x41U, 0x9fU, 0x26U, 0x14U, 0xc9U, 0x42U, 0xc9U, 0xeeU, 0x5eU, 0xfbU, 0xdfU, 0xbaU, 0x0cU, 0xcaU,
    0x70U, 0x6bU, 0x3aU, 0x4eU, 0xd1U, 0xa8U, 0x5fU, 0x69U, 0x28U, 0xb7U, 0x60U, 0xffU, 0x1bU, 0xbaU, 0xb0U, 0xe7U,
    0xb0U, 0x4cU, 0xbdU, 0xe6U, 0xb5U, 0x9fU, 0xc8U, 0x44U, 0x4fU, 0x4eU, 0xd1U, 0x0bU, 0xceU, 0xbeU, 0x30U, 0x75U,
    0x47U, 0xb4U, 0xc6U, 0x34U, 0x35U, 0xd9U, 0xaaU, 0x4fU, 0x7dU, 0xf9U, 0x37U, 0x97U, 0xf6U, 0x27U, 0x0aU, 0x20U,
    0x23U, 0x8aU, 0x42U, 0x36U, 0xb1U, 0x6fU, 0x47U, 0x72U, 0xb9U, 0x02U, 0x2fU, 0xadU, 0x11U, 0x9cU, 0x54U, 0x38U,
    0xd7U, 0x08U, 0x17U, 0x45U, 0xe2U, 0xa7U, 0xe3U, 0x2bU, 0x55U, 0x63U, 0x0eU, 0x37U, 0x49U, 0xabU, 0x51U, 0x05U,
    0x3eU, 0x1cU, 0x9cU, 0x77U, 0xf6U, 0x77U, 0xddU, 0x12U, 0x92U, 0x96U, 0x19U, 0xe7U, 0x80U, 0x22U, 0xbdU, 0xfdU,
    0xcbU, 0x4bU, 0x8dU, 0x4eU, 0x47U, 0xbcU, 0x80U, 0xacU, 0x91U, 0xcfU, 0xe7U, 0x5fU, 0x11U, 0x91U, 0xa7U, 0x2dU,
    0xfdU, 0x61U, 0x88U, 0xfdU, 0x28U, 0x9cU, 0xd5U, 0xb3U, 0x44U, 0xd4U, 0x33U, 0x4fU, 0xc1U, 0x5bU, 0xa7U, 0x64U,
    0x1dU, 0xf6U, 0x9fU, 0xc5U, 0x73U, 0xa7U, 0x2fU, 0x08U, 0x46U, 0xd5U, 0x32U, 0x7eU, 0x24U, 0x03U, 0x17U, 0xc6U,
    0x8eU, 0x02U, 0xbfU, 0x5dU, 0xe0U, 0x8cU, 0x40U, 0xbeU, 0x7eU, 0x2cU, 0xc1U, 0xa4U, 0x04U, 0xc0U, 0x6bU, 0xbfU,
    0x56U, 0xf3U, 0x09U, 0x5aU, 0x8cU, 0x34U, 0x8fU, 0x7bU, 0x50U, 0xabU, 0x65U, 0x48U, 0x02U, 0x11U, 0x02U, 0x4bU,
    0xacU, 0x3cU, 0xa5U, 0x93U, 0xa5U, 0xd4U, 0x4aU, 0x7dU, 0xa7U, 0xb8U, 0x69U, 0x6eU, 0xb6U, 0xe2U, 0xa1U, 0xd2U,
    0xfcU, 0xa1U, 0x89U, 0x44U, 0x50U, 0xc9U, 0x01U, 0x5eU, 0xbdU, 0xafU, 0x25U, 0xadU, 0xd0U, 0x0cU, 0xb4U, 0x4fU,
    0xb3U, 0x99U, 0x44U, 0x28U, 0xb2U, 0x45U, 0x1cU, 0x92U, 0x6bU, 0xbfU, 0xfcU, 0xfdU, 0x72U, 0xecU, 0x44U, 0xdaU,
    0xaaU, 0xdaU, 0x65U, 0x19U, 0xc3U, 0x41U, 0x46U, 0xb6U, 0x01U, 0x67U, 0xdeU, 0x98U, 0xd8U, 0x1bU, 0x15U, 0x94U
};


/** Performs a session set-up; a call to function mcuxClRsa_sign using mode mcuxClRsa_Mode_Sign_Pss_Sha2_256; a session clean-up
 * @retval MCUXCLEXAMPLE_STATUS_OK    The example code completed successfully
 * @retval MCUXCLEXAMPLE_STATUS_ERROR The example code failed */
MCUXCLEXAMPLE_FUNCTION(mcuxClRsa_sign_pss_sha2_256_example)
{
    /**************************************************************************/
    /* Preparation                                                            */
    /**************************************************************************/

    /** Initialize ELS, Enable the ELS **/
    if(!mcuxClExample_Els_Init(MCUXCLELS_RESET_DO_NOT_CANCEL))
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }

    /* Create session handle to be used by mcuxClRsa_sign */
    mcuxClSession_Descriptor_t sessionDesc;
    mcuxClSession_Handle_t session = &sessionDesc;

    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                 MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE,
                                                 MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE);

    /* Initialize the PRNG */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(session));
    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result)) 
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Create key struct of type MCUXCLRSA_KEY_PRIVATEPLAIN */
    const mcuxClRsa_KeyEntry_t Mod1 = {
                       .pKeyEntryData = (uint8_t *)modulus,
                       .keyEntryLength = RSA_KEY_BYTE_LENGTH };

    const mcuxClRsa_KeyEntry_t Exp1 = {
                       .pKeyEntryData = (uint8_t *)exponent,
                       .keyEntryLength = sizeof(exponent) };

    const mcuxClRsa_Key private_key = {
                       .keytype = MCUXCLRSA_KEY_PRIVATEPLAIN,
                       .pMod1 = (mcuxClRsa_KeyEntry_t *)&Mod1,
                       .pMod2 = NULL,
                       .pQInv = NULL,
                       .pExp1 = (mcuxClRsa_KeyEntry_t *)&Exp1,
                       .pExp2 = NULL,
                       .pExp3 = NULL };


    /* Prepare buffer to store the result */
    uint8_t signature[RSA_KEY_BYTE_LENGTH];

    /**************************************************************************/
    /* RSA signature generation call                                          */
    /**************************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(sign_result, sign_token, mcuxClRsa_sign(
                /* mcuxClSession_Handle_t           pSession: */           session,
                /* const mcuxClRsa_Key * const      pKey: */               &private_key,
                /* mcuxCl_InputBuffer_t             pMessageOrDigest: */   message,
                /* const uint32_t                  messageLength: */      RSA_MESSAGE_DIGEST_LENGTH,
                /* const mcuxClRsa_SignVerifyMode   pPaddingMode: */       (mcuxClRsa_SignVerifyMode_t *)&mcuxClRsa_Mode_Sign_Pss_Sha2_256,
                /* const uint32_t                  saltLength: */         RSA_PSS_SALT_LENGTH,
                /* uint32_t                        options: */            MCUXCLRSA_OPTION_MESSAGE_DIGEST,
                /* mcuxCl_Buffer_t                  pSignature: */         signature));

    if(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_sign) != sign_token || MCUXCLRSA_STATUS_SIGN_OK != sign_result)
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /**************************************************************************/
    /* Verification of the result                                             */
    /**************************************************************************/
    for(size_t i = 0U; i < RSA_KEY_BYTE_LENGTH; i++)
    {
        if(referenceSignature[i] != signature[i])
        {
            return MCUXCLEXAMPLE_STATUS_ERROR;
        }
    }

    /**************************************************************************/
    /* Session clean-up                                                       */
    /**************************************************************************/
    /** Destroy Session and cleanup Session **/
    if(!mcuxClExample_Session_Clean(session))
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }

    /** Disable the ELS **/
    if(!mcuxClExample_Els_Disable())
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }
    return MCUXCLEXAMPLE_STATUS_OK;
}
