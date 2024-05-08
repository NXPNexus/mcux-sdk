/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** @file  mcuxClPsaDriver_Oracle_Interface_key_locations.h
 *  @brief Macros used by the Oracle, Utils functions and psa_crypto_driver */

#ifndef _MCUXCLPSADRIVER_ORACLE_INTERFACE_KEY_LOCATIONS_MACROS_
#define _MCUXCLPSADRIVER_ORACLE_INTERFACE_KEY_LOCATIONS_MACROS_


// common flags
#define PSA_KEY_LOCATION_NXP_FLAG              0x400000U
#define PSA_KEY_LOCATION_EL2GO_FLAG            0x200000U
#define PSA_KEY_LOCATION_S50_FLAG              0x000001U
#define PSA_KEY_LOCATION_COMMON_FLAG           (PSA_KEY_LOCATION_VENDOR_FLAG | PSA_KEY_LOCATION_NXP_FLAG | PSA_KEY_LOCATION_EL2GO_FLAG | PSA_KEY_LOCATION_S50_FLAG)

// key/data
#define PSA_KEY_LOCATION_KEY_FLAG              0x000000U
#define PSA_KEY_LOCATION_DATA_FLAG             0x008000U

// blob/encrypted
#define PSA_KEY_LOCATION_BLOB_STORAGE_FLAG     0x000000U
#define PSA_KEY_LOCATION_ENC_STORAGE_FLAG      0x000100U
#define PSA_KEY_LOCATION_TEMP_STORAGE_FLAG     0x000200U
#define PSA_KEY_LOCATION_KEY_GEN_STORAGE_FLAG  0x000300U

#define PSA_KEY_LOCATION_S50_ENC_STORAGE_KEY         ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_ENC_STORAGE_FLAG | PSA_KEY_LOCATION_KEY_FLAG))
#define PSA_KEY_LOCATION_S50_ENC_STORAGE_DATA         ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_ENC_STORAGE_FLAG | PSA_KEY_LOCATION_DATA_FLAG))
#define MCUXCLPSADRIVER_IS_S50_ENC_STORAGE(location) (((location) == PSA_KEY_LOCATION_S50_ENC_STORAGE_KEY) || ((location) == PSA_KEY_LOCATION_S50_ENC_STORAGE_DATA))

#define PSA_KEY_LOCATION_S50_BLOB_STORAGE             ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_BLOB_STORAGE_FLAG | PSA_KEY_LOCATION_KEY_FLAG))
#define MCUXCLPSADRIVER_IS_S50_BLOB_STORAGE(location) ((location) == PSA_KEY_LOCATION_S50_BLOB_STORAGE)

#define PSA_KEY_LOCATION_S50_TEMP_STORAGE             ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_TEMP_STORAGE_FLAG | PSA_KEY_LOCATION_KEY_FLAG))
#define MCUXCLPSADRIVER_IS_S50_TEMP_STORAGE(location) ((location) == PSA_KEY_LOCATION_S50_TEMP_STORAGE)

#define PSA_KEY_LOCATION_S50_KEY_GEN_STORAGE          ((psa_key_location_t)(PSA_KEY_LOCATION_COMMON_FLAG | PSA_KEY_LOCATION_KEY_GEN_STORAGE_FLAG | PSA_KEY_LOCATION_KEY_FLAG))
#define MCUXCLPSADRIVER_IS_S50_KEY_GEN_STORAGE(location) ((location) == PSA_KEY_LOCATION_S50_KEY_GEN_STORAGE)
#endif //_MCUXCLPSADRIVER_ORACLE_INTERFACE_KEY_LOCATIONS_MACROS_
