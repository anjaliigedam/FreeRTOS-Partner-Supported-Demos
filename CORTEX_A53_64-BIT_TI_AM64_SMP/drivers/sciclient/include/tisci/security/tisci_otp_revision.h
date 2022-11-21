/*
 *  Copyright (C) 2017-2022 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 * \ingroup TISCI
 * \defgroup tisci_otp_revision tisci_otp_revision
 *
 * DMSC controls the power management, security and resource management
 * of the device.
 *
 *
 * @{
 */
/**
 *
 *  \brief  This file contains:
 *
 *          WARNING!!: Autogenerated file from SYSFW. DO NOT MODIFY!!
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 */
#ifndef REVISION_RD_WR_H
#define REVISION_RD_WR_H

#ifdef __cplusplus
extern "C"
{
#endif


/**
 *
 *  \brief Declarations for all message structures to read and write SWREV and
 *         KEYREV
 */


/**
 * \brief Request message to set swrev
 *
 * This message can only be sent by the host that is tied to root of trust
 * through the secure tisci_boardcfg extended otp extension
 *
 * \param hdr           Standard TISCI header
 * \param identifier    One of the entries from enum tisci_otp_revision_identifier
 * \param value            Revision value (integer) to be bit encoded, and
 *                      programmed
 */
struct tisci_msg_set_swrev_req {
    struct tisci_header    hdr;
    uint8_t            identifier;
    uint32_t            value;
} __attribute__((__packed__));

/**
 * \brief Response message after seting swrev
 *
 * \param hdr            Standard TISCI header
 */
struct tisci_msg_set_swrev_resp {
    struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request message to set keyrev
 *
 * This message can only be sent by the host that is tied to root of trust
 * through the secure tisci_boardcfg extended otp extension
 *
 * \param hdr           Standard TISCI header
 * \param value            Key Revision value (integer) to be bit encoded, and
 *                      programmed
 * \param cert_addr_lo    Lower 32 bit address (in LE format) of the Dual signed
 *                      certificate
 * \param cert_addr_hi    Higher 32 bit address (in LE format) of the Dual signed
 *                      certificate
 */
struct tisci_msg_set_keyrev_req {
    struct tisci_header    hdr;
    uint32_t            value;
    uint32_t            cert_addr_lo;
    uint32_t            cert_addr_hi;
} __attribute__((__packed__));

/**
 * \brief Response message after setting keyrev
 *
 * \param hdr            Standard TISCI header
 */
struct tisci_msg_set_keyrev_resp {
    struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request message to get swrev
 *
 * \param hdr           Standard TISCI header
 * \param identifier    One of the entries from enum tisci_otp_revision_identifier
 *                      (Current support only for OTP_REV_ID_SEC_BRDCFG)
 */
struct tisci_msg_get_swrev_req {
    struct tisci_header    hdr;
    uint8_t            identifier;
} __attribute__((__packed__));

/**
 * \brief Response message to get swrev
 *
 * \param hdr            Standard TISCI header
 * \param value         Decoded Software Revision value (integer) from efuses
 */
struct tisci_msg_get_swrev_resp {
    struct tisci_header    hdr;
    uint32_t            value;
} __attribute__((__packed__));

/**
 * \brief Request message to get keycnt, keyrev
 *
 * \param hdr           Standard TISCI header
 */
struct tisci_msg_get_keycnt_keyrev_req {
    struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response message to get keycnt, keyrev
 *
 * \param hdr            Standard TISCI header
 * \param keycnt        Keycount integer value
 * \param keyrev        Keyrevision integer value
 */
struct tisci_msg_get_keycnt_keyrev_resp {
    struct tisci_header    hdr;
    uint32_t            keycnt;
    uint32_t            keyrev;
} __attribute__((__packed__));

/**
 * \brief OTP Revision Identifiers
 */
enum tisci_otp_revision_identifier {
    /** Sofware Revision SBL */
    OTP_REV_ID_SBL        = 0,
    /** Software Revision SYSFW */
    OTP_REV_ID_SYSFW      = 1,
    /** Software Revision Secure Board Configuration */
    OTP_REV_ID_SEC_BRDCFG = 2,
};


#ifdef __cplusplus
}
#endif

#endif

/** @} */
