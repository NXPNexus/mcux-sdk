/**************************************************************************//**
 * @file     timer_armv8a.h
 * @brief    CMSIS Cortex-Axx Generic Timer API header file
 * @version  V1.0.0
 * @date     05. october 2021
 ******************************************************************************/
/*
 * Copyright (c) 2021 Arm Limited. All rights reserved.
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TIMER_ARMV8A_H
#define __TIMER_ARMV8A_H

#ifdef __cplusplus
 extern "C" {
#endif

/*******************************************************************************
 *                 Timer Data Types
 ******************************************************************************/

/** \brief  ARMv8-A Generic Timer types */
typedef enum _ARM_TIMER_TYPE {
    ARM_TIMER_PHYSICAL,               /** Physical Timer */
    ARM_TIMER_VIRTUAL,                /** Virtual Timer */
    ARM_TIMER_HYPERVISOR_PHYSICAL,    /** Hypervisor Physical Timer */
    ARM_TIMER_PHYSICAL_SECURE,        /** Physical Secure Timer */
} ARM_TIMER_type_t;


/*******************************************************************************
 *                 Timer Functions
 ******************************************************************************/

__STATIC_INLINE void ARM_TIMER_Initialize(ARM_TIMER_type_t timer)
{
}

__STATIC_INLINE void ARM_TIMER_GetFreq(ARM_TIMER_type_t timer, uint32_t *pVal)
{
    __MRS(CNTFRQ_EL0, pVal);
}

__STATIC_INLINE void ARM_TIMER_EnableIRQ(ARM_TIMER_type_t timer)
{
    switch (timer) {
    case ARM_TIMER_PHYSICAL:
        __MSR(CNTP_CTL_EL0, 0L << 1);
        break;
    case ARM_TIMER_VIRTUAL:
        __MSR(CNTV_CTL_EL0, 0L << 1);
        break;
    case ARM_TIMER_HYPERVISOR_PHYSICAL:
        __MSR(CNTHP_CTL_EL2, 0L << 1);
        break;
    case ARM_TIMER_PHYSICAL_SECURE:
        __MSR(CNTPS_CTL_EL1, 0L << 1);
        break;
    default:
        break;
    }
}

__STATIC_INLINE void ARM_TIMER_SetInterval(ARM_TIMER_type_t timer, uint32_t val)
{
    switch (timer) {
    case ARM_TIMER_PHYSICAL:
        __MSR(CNTP_TVAL_EL0, val);
        break;
    case ARM_TIMER_VIRTUAL:
        __MSR(CNTV_TVAL_EL0, val);
        break;
    case ARM_TIMER_HYPERVISOR_PHYSICAL:
        __MSR(CNTHP_TVAL_EL2, val);
        break;
    case ARM_TIMER_PHYSICAL_SECURE:
        __MSR(CNTPS_TVAL_EL1, val);
        break;
    default:
        break;
    }

    __DSB();
    __ISB();
}

__STATIC_INLINE void ARM_TIMER_Start(ARM_TIMER_type_t timer)
{
    switch (timer) {
    case ARM_TIMER_PHYSICAL:
        __MSR(CNTP_CTL_EL0, 1UL);
        break;
    case ARM_TIMER_VIRTUAL:
        __MSR(CNTV_CTL_EL0, 1UL);
        break;
    case ARM_TIMER_HYPERVISOR_PHYSICAL:
        __MSR(CNTHP_CTL_EL2, 1UL);
        break;
    case ARM_TIMER_PHYSICAL_SECURE:
        __MSR(CNTPS_CTL_EL1, 1UL);
        break;
    default:
        break;
    }
}

#ifdef __cplusplus
}
#endif

#endif /* __TIMER_ARMV8A_H */

