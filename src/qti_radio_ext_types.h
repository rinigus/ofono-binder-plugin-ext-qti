/*
 *  oFono - Open Source Telephony - binder based adaptation QTI plugin
 *
 *  Copyright (C) 2024 TheKit <thekit@disroot.org>
 *  Copyright (C) 2024 Marius Gripsgard <marius@ubports.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef QTI_RADIO_EXT_TYPES_H
#define QTI_RADIO_EXT_TYPES_H

#include <ofono/types.h>

typedef enum qti_radio_interface {
    QTI_RADIO_INTERFACE_NONE = -1,
    QTI_RADIO_INTERFACE_1_0,
    QTI_RADIO_INTERFACE_1_1,
    QTI_RADIO_INTERFACE_1_2,
    QTI_RADIO_INTERFACE_AIDL,
    QTI_RADIO_INTERFACE_COUNT
} QTI_RADIO_INTERFACE;

#define QTI_RADIO_IFACE                 "IImsRadio"
#define QTI_RADIO_RESPONSE_IFACE        "IImsRadioResponse"
#define QTI_RADIO_INDICATION_IFACE      "IImsRadioIndication"
#define QTI_RADIO_IFACE_PREFIX          "vendor.qti.hardware.radio.ims"

#define QTI_RADIO_IFACE_1_0(x)          QTI_RADIO_IFACE_PREFIX "@1.0::" x
#define QTI_RADIO_IFACE_1_1(x)          QTI_RADIO_IFACE_PREFIX "@1.1::" x
#define QTI_RADIO_IFACE_1_2(x)          QTI_RADIO_IFACE_PREFIX "@1.2::" x
#define QTI_RADIO_IFACE_AIDL(x)         QTI_RADIO_IFACE_PREFIX "." x

#define QTI_RADIO_1_0                   QTI_RADIO_IFACE_1_0(QTI_RADIO_IFACE)
#define QTI_RADIO_1_1                   QTI_RADIO_IFACE_1_1(QTI_RADIO_IFACE)
#define QTI_RADIO_1_2                   QTI_RADIO_IFACE_1_2(QTI_RADIO_IFACE)
#define QTI_RADIO_AIDL                  QTI_RADIO_IFACE_AIDL(QTI_RADIO_IFACE)

#define QTI_RADIO_RESPONSE_1_0          QTI_RADIO_IFACE_1_0(QTI_RADIO_RESPONSE_IFACE)
#define QTI_RADIO_RESPONSE_1_1          QTI_RADIO_IFACE_1_1(QTI_RADIO_RESPONSE_IFACE)
#define QTI_RADIO_RESPONSE_1_2          QTI_RADIO_IFACE_1_2(QTI_RADIO_RESPONSE_IFACE)
#define QTI_RADIO_RESPONSE_AIDL         QTI_RADIO_IFACE_AIDL(QTI_RADIO_RESPONSE_IFACE)

#define QTI_RADIO_INDICATION_1_0        QTI_RADIO_IFACE_1_0(QTI_RADIO_INDICATION_IFACE)
#define QTI_RADIO_INDICATION_1_1        QTI_RADIO_IFACE_1_1(QTI_RADIO_INDICATION_IFACE)
#define QTI_RADIO_INDICATION_1_2        QTI_RADIO_IFACE_1_2(QTI_RADIO_INDICATION_IFACE)
#define QTI_RADIO_INDICATION_AIDL       QTI_RADIO_IFACE_AIDL(QTI_RADIO_INDICATION_IFACE)

#define QTI_RADIO_REQ_LAST_1_0          40
#define QTI_RADIO_REQ_LAST_1_1          41
#define QTI_RADIO_REQ_LAST_1_2          47

/* String length constants for QtiRadioCallInfo */
#define QTI_RADIO_MAX_PHONE_NUMBER_LENGTH      OFONO_MAX_PHONE_NUMBER_LENGTH
#define QTI_RADIO_MAX_CALLER_NAME_LENGTH       OFONO_MAX_CALLER_NAME_LENGTH
#define QTI_RADIO_MAX_HISTORY_INFO_LENGTH      80
#define QTI_RADIO_MAX_DIVERSION_INFO_LENGTH    80

// based on AIDL ims.apk -> vendor/qti/hardware/radio/ims/RegState
typedef enum qti_radio_reg_state {
    QTI_RADIO_REG_STATE_REGISTERED = 1,
    QTI_RADIO_REG_STATE_NOT_REGISTERED = 2,
    QTI_RADIO_REG_STATE_REGISTERING = 3,
    QTI_RADIO_REG_STATE_INVALID = 0,

    QTI_RADIO_REG_STATE_FAILED_TO_READ = -1 // extra state to tag failed read
} QTI_RADIO_REG_STATE;

// based on on AIDL ims.apk -> vendor/qti/hardware/radio/ims/StatusType.java
typedef enum qti_radio_status_type {
    QTI_RADIO_STATUS_INVALID = 0,
    QTI_RADIO_STATUS_DISABLED = 1,
    QTI_RADIO_STATUS_PARTIALLY_ENABLED = 2,
    QTI_RADIO_STATUS_ENABLED = 3,
    QTI_RADIO_STATUS_NOT_SUPPORTED = 4,
} QTI_RADIO_STATUS_TYPE;

typedef enum qti_radio_call_state {
    QTI_RADIO_CALL_STATE_ACTIVE = 1,
    QTI_RADIO_CALL_STATE_HOLDING = 2,
    QTI_RADIO_CALL_STATE_DIALING = 3,
    QTI_RADIO_CALL_STATE_ALERTING = 4,
    QTI_RADIO_CALL_STATE_INCOMING = 5,
    QTI_RADIO_CALL_STATE_WAITING = 6,
    QTI_RADIO_CALL_STATE_END = 7,
    QTI_RADIO_CALL_STATE_INVALID = 0,
} QTI_RADIO_CALL_STATE;

// Based on AIDL ims.apk -> vendor/qti/hardware/radio/ims/ErrorCode.java
typedef enum qti_radio_error_code {
    QTI_RADIO_ERROR_INVALID = 0,
    QTI_RADIO_ERROR_RADIO_NOT_AVAILABLE = 2,
    QTI_RADIO_ERROR_GENERIC_FAILURE = 3,
    QTI_RADIO_ERROR_PASSWORD_INCORRECT = 4,
    QTI_RADIO_ERROR_REQUEST_NOT_SUPPORTED = 5,
    QTI_RADIO_ERROR_CANCELLED = 6,
    QTI_RADIO_ERROR_NO_MEMORY = 7,
    QTI_RADIO_ERROR_UNUSED = 8,
    QTI_RADIO_ERROR_INVALID_PARAMETER = 9,
    QTI_RADIO_ERROR_REJECTED_BY_REMOTE = 10,
    QTI_RADIO_ERROR_IMS_DEREGISTERED = 11,
    QTI_RADIO_ERROR_NETWORK_NOT_SUPPORTED = 12,
    QTI_RADIO_ERROR_HOLD_RESUME_FAILED = 13,
    QTI_RADIO_ERROR_HOLD_RESUME_CANCELED = 14,
    QTI_RADIO_ERROR_REINVITE_COLLISION = 15,
    QTI_RADIO_ERROR_FDN_CHECK_FAILURE = 16,
    QTI_RADIO_ERROR_SS_MODIFIED_TO_DIAL = 17,
    QTI_RADIO_ERROR_SS_MODIFIED_TO_USSD = 18,
    QTI_RADIO_ERROR_SS_MODIFIED_TO_SS = 19,
    QTI_RADIO_ERROR_SS_MODIFIED_TO_DIAL_VIDEO = 20,
    QTI_RADIO_ERROR_DIAL_MODIFIED_TO_USSD = 21,
    QTI_RADIO_ERROR_DIAL_MODIFIED_TO_SS = 22,
    QTI_RADIO_ERROR_DIAL_MODIFIED_TO_DIAL = 23,
    QTI_RADIO_ERROR_DIAL_MODIFIED_TO_DIAL_VIDEO = 24,
    QTI_RADIO_ERROR_DIAL_VIDEO_MODIFIED_TO_USSD = 25,
    QTI_RADIO_ERROR_DIAL_VIDEO_MODIFIED_TO_SS = 26,
    QTI_RADIO_ERROR_DIAL_VIDEO_MODIFIED_TO_DIAL = 27,
    QTI_RADIO_ERROR_DIAL_VIDEO_MODIFIED_TO_DIAL_VIDEO = 28,
    QTI_RADIO_ERROR_USSD_CS_FALLBACK = 29,
    QTI_RADIO_ERROR_CF_SERVICE_NOT_REGISTERED = 30,
    QTI_RADIO_ERROR_SUCCESS = 1
} QTI_RADIO_ERROR_CODE;

typedef enum qti_radio_ip_presentation {
    QTI_RADIO_IP_PRESENTATION_NUM_DEFAULT = 1,
    QTI_RADIO_IP_PRESENTATION_NUM_INVOCATION = 2,
    QTI_RADIO_IP_PRESENTATION_NUM_SUPRESSION = 3,
    QTI_RADIO_IP_PRESENTATION_INVALID = 0,
} QTI_RADIO_IP_PRESENTATION;

typedef enum qti_radio_call_type {
    QTI_RADIO_CALL_TYPE_VOICE = 1,
    QTI_RADIO_CALL_TYPE_VT_TX = 2,
    QTI_RADIO_CALL_TYPE_VT_RX = 3,
    QTI_RADIO_CALL_TYPE_VT = 4,
    QTI_RADIO_CALL_TYPE_VT_NODIR = 5,
    QTI_RADIO_CALL_TYPE_CS_VS_TX = 6,
    QTI_RADIO_CALL_TYPE_CS_VS_RX = 7,
    QTI_RADIO_CALL_TYPE_PS_VS_TX = 8,
    QTI_RADIO_CALL_TYPE_PS_VS_RX = 9,
    QTI_RADIO_CALL_TYPE_UNKNOWN = 0,
    QTI_RADIO_CALL_TYPE_SMS = 0xa,
    QTI_RADIO_CALL_TYPE_UT = 0xb,
    QTI_RADIO_CALL_TYPE_USSD = 0xc,
    QTI_RADIO_CALL_TYPE_CALLCOMPOSER = 0xd,
} QTI_RADIO_CALL_TYPE;

typedef enum qti_radio_call_domain {
    QTI_RADIO_CALL_DOMAIN_UNKNOWN = 1,
    QTI_RADIO_CALL_DOMAIN_CS = 2,
    QTI_RADIO_CALL_DOMAIN_PS = 3,
    QTI_RADIO_CALL_DOMAIN_AUTOMATIC = 4,
    QTI_RADIO_CALL_DOMAIN_NOT_SET = 5,
    QTI_RADIO_CALL_DOMAIN_INVALID = 0,
} QTI_RADIO_CALL_DOMAIN;

typedef enum qti_radio_rtt_mode {
    QTI_RADIO_RTT_MODE_DISABLED = 1,
    QTI_RADIO_RTT_MODE_FULL = 2,
    QTI_RADIO_RTT_MODE_INVALID = 0,
} QTI_RADIO_RTT_MODE;

typedef enum qti_radio_tech_type {
    QTI_RADIO_TECH_INVALID   = 0,
    QTI_RADIO_TECH_ANY       = 1,
    QTI_RADIO_TECH_UNKNOWN   = 2,
    QTI_RADIO_TECH_GPRS      = 3,
    QTI_RADIO_TECH_EDGE      = 4,
    QTI_RADIO_TECH_UMTS      = 5,
    QTI_RADIO_TECH_IS95A     = 6,
    QTI_RADIO_TECH_IS95B     = 7,
    QTI_RADIO_TECH_RTT_1X    = 8,
    QTI_RADIO_TECH_EVDO_0    = 9,
    QTI_RADIO_TECH_EVDO_A    = 10,
    QTI_RADIO_TECH_HSDPA     = 11,
    QTI_RADIO_TECH_HSUPA     = 12,
    QTI_RADIO_TECH_HSPA      = 13,
    QTI_RADIO_TECH_EVDO_B    = 14,
    QTI_RADIO_TECH_EHRPD     = 15,
    QTI_RADIO_TECH_LTE       = 16,
    QTI_RADIO_TECH_HSPAP     = 17,
    QTI_RADIO_TECH_GSM       = 18,
    QTI_RADIO_TECH_TD_SCDMA  = 19,
    QTI_RADIO_TECH_WIFI      = 20,
    QTI_RADIO_TECH_IWLAN     = 21,
    QTI_RADIO_TECH_NR5G      = 22,
    QTI_RADIO_TECH_C_IWLAN   = 23,
} QTI_RADIO_TECH_TYPE;

typedef enum qti_radio_handover_type {
    QTI_RADIO_HANDOVER_INVALID                    = 0,
    QTI_RADIO_HANDOVER_START                      = 1,
    QTI_RADIO_HANDOVER_COMPLETE_SUCCESS           = 2,
    QTI_RADIO_HANDOVER_COMPLETE_FAIL              = 3,
    QTI_RADIO_HANDOVER_CANCEL                     = 4,
    QTI_RADIO_HANDOVER_NOT_TRIGGERED              = 5,
    QTI_RADIO_HANDOVER_NOT_TRIGGERED_MOBILE_DATA_OFF = 6,
} QTI_RADIO_HANDOVER_TYPE;

typedef enum qti_radio_ims_sms_send_status_result {
    QTI_RADIO_SEND_STATUS_OK = 1,
    QTI_RADIO_SEND_STATUS_ERROR = 2,
    QTI_RADIO_SEND_STATUS_ERROR_RETRY = 3,
    QTI_RADIO_SEND_STATUS_ERROR_FALLBACK = 4,
    QTI_RADIO_SEND_STATUS_INVALID = 0,
} QTI_RADIO_IMS_SMS_SEND_STATUS_RESULT;

typedef enum qti_radio_ims_sms_send_failure_reason {
    QTI_RADIO_RESULT_ERROR_INVALID = 0,
    QTI_RADIO_RESULT_ERROR_NONE = 1,
    QTI_RADIO_RESULT_ERROR_GENERIC_FAILURE = 2,
    QTI_RADIO_RESULT_ERROR_RADIO_OFF = 3,
    QTI_RADIO_RESULT_ERROR_NULL_PDU = 4,
    QTI_RADIO_RESULT_ERROR_NO_SERVICE = 5,
    QTI_RADIO_RESULT_ERROR_LIMIT_EXCEEDED = 6,
    QTI_RADIO_RESULT_ERROR_SHORT_CODE_NOT_ALLOWED = 7,
    QTI_RADIO_RESULT_ERROR_SHORT_CODE_NEVER_ALLOWED = 8,
    QTI_RADIO_RESULT_ERROR_FDN_CHECK_FAILURE = 9,
    QTI_RADIO_RESULT_ERROR_RADIO_NOT_AVAILABLE = 0xa,
    QTI_RADIO_RESULT_ERROR_NETWORK_REJECT = 0xb,
    QTI_RADIO_RESULT_ERROR_INVALID_ARGUMENTS = 0xc,
    QTI_RADIO_RESULT_ERROR_INVALID_STATE = 0xd,
    QTI_RADIO_RESULT_ERROR_NO_MEMORY = 0xe,
    QTI_RADIO_RESULT_ERROR_INVALID_SMS_FORMAT = 0xf,
    QTI_RADIO_RESULT_ERROR_SYSTEM_ERROR = 0x10,
    QTI_RADIO_RESULT_ERROR_MODEM_ERROR = 0x11,
    QTI_RADIO_RESULT_ERROR_NETWORK_ERROR = 0x12,
    QTI_RADIO_RESULT_ERROR_ENCODING_ERROR = 0x13,
    QTI_RADIO_RESULT_ERROR_INVALID_SMSC_ADDRESS = 0x14,
    QTI_RADIO_RESULT_ERROR_OPERATION_NOT_ALLOWED = 0x15,
    QTI_RADIO_RESULT_ERROR_INTERNAL_ERROR = 0x16,
    QTI_RADIO_RESULT_ERROR_NO_RESOURCES = 0x17,
    QTI_RADIO_RESULT_ERROR_CANCELLED = 0x18,
    QTI_RADIO_RESULT_ERROR_REQUEST_NOT_SUPPORTED = 0x19,
} QTI_RADIO_IMS_SMS_SEND_FAILURE_REASON;

typedef enum qti_radio_ims_sms_deliver_status_result {
    QTI_RADIO_DELIVER_STATUS_INVALID = 0,
    QTI_RADIO_DELIVER_STATUS_ERROR = 1,
    QTI_RADIO_DELIVER_STATUS_OK = 2,
    QTI_RADIO_DELIVER_STATUS_ERROR_NO_MEMORY = 3,
    QTI_RADIO_DELIVER_STATUS_ERROR_REQUEST_NOT_SUPPORTED = 4,
} QTI_RADIO_IMS_SMS_DELIVER_STATUS_RESULT;

typedef enum qti_radio_ims_sms_status_report_result {
    QTI_RADIO_STATUS_REPORT_INVALID = 0,
    QTI_RADIO_STATUS_REPORT_OK = 1,
    QTI_RADIO_STATUS_REPORT_ERROR = 2,
} QTI_RADIO_IMS_SMS_STATUS_REPORT_RESULT;

typedef enum qti_radio_verification_status {
    QTI_RADIO_VALIDATION_NONE = 0,
    QTI_RADIO_VALIDATION_PASS = 1,
    QTI_RADIO_VALIDATION_FAIL = 2,
} QTI_RADIO_VERIFICATION_STATUS;


// based on IImsRadio and IImsRadioResponse stubs from ims.apk
// requests with missing response are set to zero and are probably
// for sync calls
/* c(req, resp, callName, CALL_NAME) */
#define QTI_RADIO_EXT_IMS_CALL_AIDL(c) \
    c(1, 0, setCallback, SET_CALLBACK) \
    c(2, 1, dial, DIAL) \
    c(3, 31, addParticipant, ADD_PARTICIPANT) \
    c(4, 11, getImsRegistrationState, GET_IMS_REG_STATE) \
    c(5, 2, answer, ANSWER) \
    c(6, 3, hangup, HANGUP) \
    c(7, 4, requestRegistrationChange, REQ_REG_CHANGE) \
    c(8, 5, queryServiceStatus, QUERY_SERVICE_STATUS) \
    c(9, 6, setServiceStatus, SET_SERVICE_STATUS) \
    c(10, 7, hold, HOLD) \
    c(11, 8, resume, RESUME) \
    c(12, 9, setConfig, SET_CONFIG) \
    c(13, 10, getConfig, GET_CONFIG) \
    c(14, 13, conference, CONFERENCE) \
    c(15, 14, getClip, GET_CLIP) \
    c(16, 15, getClir, GET_CLIR) \
    c(17, 16, setClir, SET_CLIR) \
    c(18, 17, getColr, GET_COLR) \
    c(19, 0, setColr, SET_COLR) \
    c(20, 18, exitEmergencyCallbackMode, EXIT_EMERGENCY_CALLBACK_MODE) \
    c(21, 19, sendDtmf, SEND_DTMF) \
    c(22, 20, startDtmf, START_DTMF) \
    c(23, 21, stopDtmf, STOP_DTMF) \
    c(24, 0, setUiTtyMode, SET_UI_TTY_MODE) \
    c(25, 23, modifyCallInitiate, MODIFY_CALL_INITIATE) \
    c(26, 24, modifyCallConfirm, MODIFY_CALL_CONFIRM) \
    c(27, 25, queryCallForwardStatus, QUERY_CALL_FORWARD_STATUS) \
    c(28, 40, setCallForwardStatus, SET_CALL_FORWARD_STATUS) \
    c(29, 26, getCallWaiting, GET_CALL_WAITING) \
    c(30, 0, setCallWaiting, SET_CALL_WAITING) \
    c(31, 28, setSuppServiceNotification, SET_SUPP_SERVICE_NOTIFICATION) \
    c(32, 27, explicitCallTransfer, EXPLICIT_CALL_TRANSFER) \
    c(33, 12, suppServiceStatus, SUPP_SERVICE_STATUS) \
    c(34, 29, getRtpStatistics, GET_RTP_STATISTICS) \
    c(35, 30, getRtpErrorStatistics, GET_RTP_ERROR_STATISTICS) \
    c(36, 32, deflectCall, DEFLECT_CALL) \
    c(37, 33, sendGeolocationInfo, SEND_GEOLOCATION_INFO) \
    c(38, 34, getImsSubConfig, GET_IMS_SUB_CONFIG) \
    c(39, 35, sendRttMessage, SEND_RTT_MESSAGE) \
    c(40, 36, cancelModifyCall, CANCEL_MODIFY_CALL) \
    c(41, 37, sendSms, SEND_IMS_SMS) \
    c(42, 0, acknowledgeSms, ACK_SMS) \
    c(43, 0, acknowledgeSmsReport, ACK_SMS_REPORT) \
    c(44, 0, getSmsFormat, GET_SMS_FORMAT) \
    c(45, 38, registerMultiIdentityLines, REGISTER_MULTI_IDENTITY_LINES) \
    c(46, 39, queryVirtualLineInfo, QUERY_VIRTUAL_LINE_INFO) \
    c(47, 0, emergencyDial, EMERGENCY_DIAL) \
    c(48, 41, sendUssd, SEND_USSD) \
    c(49, 42, cancelPendingUssd, CANCEL_PENDING_USSD) \
    c(50, 0, callComposerDial, CALL_COMPOSER_DIAL) \
    c(51, 43, sendSipDtmf, SEND_SIP_DTMF) \
    c(52, 44, setMediaConfiguration, SET_MEDIA_CONFIGURATION) \
    c(53, 45, queryMultiSimVoiceCapability, QUERY_MULTI_SIM_VOICE_CAPABILITY) \
    c(54, 46, exitSmsCallBackMode, EXIT_SMS_CALL_BACK_MODE) \
    c(55, 47, sendVosSupportStatus, SEND_VOS_SUPPORT_STATUS) \
    c(56, 48, sendVosActionInfo, SEND_VOS_ACTION_INFO) \
    c(16777214, 0, getInterfaceHash, GET_INTERFACE_HASH) \
    c(16777215, 0, getInterfaceVersion, GET_INTERFACE_VERSION)

typedef enum qti_radio_req {
#define QTI_RADIO_REQ_(req,resp,Name,NAME) QTI_RADIO_REQ_##NAME = req,
    QTI_RADIO_EXT_IMS_CALL_AIDL(QTI_RADIO_REQ_)
#undef QTI_RADIO_REQ_
} QTI_RADIO_REQ;

typedef enum ims_radio_resp {
#define QTI_RADIO_RESP_(req,resp,Name,NAME) QTI_RADIO_RESP_##NAME = resp,
    QTI_RADIO_EXT_IMS_CALL_AIDL(QTI_RADIO_RESP_)
#undef QTI_RADIO_RESP_
} IMS_RADIO_RESP;

#define QTI_RADIO_IND_AIDL(e) \
    e(0x1, onCallStateChanged, CALL_STATE_INDICATION) \
    e(0x2, onRing, RING_INDICATION) \
    e(0x3, onRingbackTone, RINGBACK_TONE_INDICATION) \
    e(0x4, onRegistrationChanged, REG_STATE_INDICATION) \
    e(0x5, onHandover, HANDOVER_INDICATION) \
    e(0x6, onServiceStatusChanged, SVC_STATUS_INDICATION) \
    e(0x7, radioStateChanged, RADIO_STATE_CHANGED) \
    e(0x8, onEmergencyCallBackModeChanged, ECBM_CHANGED) \
    e(0x9, onTtyNotification, TTY_NOTIFICATION_INDICATION) \
    e(0xa, onRefreshConferenceInfo, REFRESH_CONF_INFO_INDICATION) \
    e(0xb, onRefreshViceInfo, REFRESH_VICE_INFO_INDICATION) \
    e(0xc, onModifyCall, MODIFY_CALL_INDICATION) \
    e(0xd, onSuppServiceNotification, SUPP_SVC_NOTIFICATION) \
    e(0xe, onMessageWaiting, MSG_WAITING_INDICATION) \
    e(0xf, onGeolocationInfoRequested, GEOLOCATION_REQUESTED) \
    e(0x10, onImsSubConfigChanged, SUB_CONFIG_CHANGED) \
    e(0x11, onParticipantStatusInfo, PARTICIPANT_STATUS_INFO) \
    e(0x12, onRegistrationBlockStatus, REG_BLOCK_STATUS) \
    e(0x13, onRttMessageReceived, RTT_MSG_RECEIVED) \
    e(0x14, onVoWiFiCallQuality, VOWIFI_CALL_QUALITY) \
    e(0x15, onSupplementaryServiceIndication, SUPP_SVC_INDICATION) \
    e(0x16, onSmsSendStatusReport, SMS_SEND_STATUS) \
    e(0x17, onIncomingSms, INCOMING_SMS) \
    e(0x18, onVopsChanged, VOPS_INDICATION) \
    e(0x19, onIncomingCallAutoRejected, AUTO_REJECTED_CALL) \
    e(0x1a, onVoiceInfoChanged, VOICE_INFO_CHANGED) \
    e(0x1b, onMultiIdentityRegistrationStatusChange, MULTI_ID_REG_STATUS_CHANGED) \
    e(0x1c, onMultiIdentityInfoPending, MULTI_ID_INFO_PENDING) \
    e(0x1d, onModemSupportsWfcRoamingModeConfiguration, MODEM_SUPP_WFC_ROAMING) \
    e(0x1e, onUssdMessageFailed, USSD_MSG_FAILED) \
    e(0x1f, onUssdReceived, USSD_RECEIVED) \
    e(0x20, onCallComposerInfoAvailable, CALL_COMPOSER_INFO) \
    e(0x21, onIncomingCallComposerCallAutoRejected, COMPOSER_CALL_AUTO_REJECTED) \
    e(0x22, onRetrievingGeoLocationDataStatus, GEOLOCATION_STATUS) \
    e(0x23, onSipDtmfReceived, SIP_DTMF_RECEIVED) \
    e(0x24, onServiceDomainChanged, SERVICE_DOMAIN_CHANGED) \
    e(0x25, onSmsCallBackModeChanged, SMS_CB_MODE_CHANGED) \
    e(0x26, onConferenceCallStateCompleted, CONF_CALL_STATE_COMPLETED) \
    e(0x27, onIncomingDtmfStart, INCOMING_DTMF_START) \
    e(0x28, onIncomingDtmfStop, INCOMING_DTMF_STOP) \
    e(0x29, onMultiSimVoiceCapabilityChanged, MULTISIM_VOICE_CAPABILITY_CHANGED) \
    e(0x2a, onPreAlertingCallInfoAvailable, PRE_ALERTING_CALL_INFO) \
    e(0x2b, onIncomingCallAutoRejected2, AUTO_REJECTED_CALL_2) \
    e(0x2c, onCiWlanNotification, CI_WLAN_NOTIFICATION) \
    e(0x2d, onSrtpEncryptionStatusChanged, SRTP_ENCRYPTION_STATUS) \
    e(0xffffff, getInterfaceVersion, GET_INTERFACE_VERSION) \
    e(0xfffffe, getInterfaceHash, GET_INTERFACE_HASH)


typedef enum ims_radio_ind {
#define QTI_RADIO_IND_(code, name, NAME) QTI_RADIO_IND_##NAME = code,
    QTI_RADIO_IND_AIDL(QTI_RADIO_IND_)
#undef QTI_RADIO_IND_
} IMS_RADIO_IND;

////////////////
// Struct below

typedef struct qti_radio_ims_sms_message {
    guint32 message_ref RADIO_ALIGNED(4);
    GBinderHidlString format RADIO_ALIGNED(8);
    GBinderHidlString smsc RADIO_ALIGNED(8);
    guint8 shall_retry RADIO_ALIGNED(1);
    GBinderHidlVec pdu RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioImsSmsMessage;

typedef struct qti_radio_ims_sms_send_status_report {
    guint32 message_ref RADIO_ALIGNED(4);
    GBinderHidlString format RADIO_ALIGNED(8);
    GBinderHidlVec pdu RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioImsSmsSendStatusReport;

typedef struct qti_radio_reg_info {
    QTI_RADIO_REG_STATE state RADIO_ALIGNED(4);
    guint32 error_code RADIO_ALIGNED(4);
    GBinderHidlString error_message RADIO_ALIGNED(8);
    guint32 radio_tech RADIO_ALIGNED(4);
    GBinderHidlString uri RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioRegInfo;

typedef struct qti_radio_sip_error_info {
    guint32 error_code RADIO_ALIGNED(4);
    GBinderHidlString error_string RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioSipErrorInfo;

typedef struct qti_radio_call_fail_cause_response {
    guint32 fail_cause RADIO_ALIGNED(4);
    GBinderHidlVec errorinfo RADIO_ALIGNED(8);
    GBinderHidlString network_error_string RADIO_ALIGNED(8);
    guint8 has_error_details RADIO_ALIGNED(1);
    QtiRadioSipErrorInfo error_details RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioCallFailCauseResponse;

typedef struct qti_radio_service_status_info {
    gboolean has_is_valid RADIO_ALIGNED(4);
    gboolean is_valid RADIO_ALIGNED(4);
    guint32 type RADIO_ALIGNED(4);
    guint32 call_type RADIO_ALIGNED(4);
    guint32 status RADIO_ALIGNED(4);
    GBinderHidlVec userdata RADIO_ALIGNED(8);
    guint32 restrict_cause RADIO_ALIGNED(4);
    GBinderHidlVec acc_tech_status RADIO_ALIGNED(8);
    guint32 rtt_mode RADIO_ALIGNED(4);
} QtiRadioServiceStatusInfo;

typedef struct qti_radio_call_details {
    guint32 call_type RADIO_ALIGNED(4);
    guint32 call_domain RADIO_ALIGNED(4);
    guint32 extras_length RADIO_ALIGNED(4);

    GBinderHidlVec extras RADIO_ALIGNED(8);
    GBinderHidlVec local_ability RADIO_ALIGNED(8);
    GBinderHidlVec peer_ability RADIO_ALIGNED(8);

    guint32 call_substate RADIO_ALIGNED(4);
    guint32 media_id RADIO_ALIGNED(4);
    guint32 cause_code RADIO_ALIGNED(4);
    guint32 rtt_mode RADIO_ALIGNED(4);
    GBinderHidlString sip_alternate_uri RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioCallDetails;

typedef struct qti_radio_call_info {
    gint32 state;
    gint32 index;
    gint32 toa;
    gboolean isMpty;
    gboolean isMT;
    //MultiIdentityLineInfo* mtMultiLineInfo; // Parcelable
    gint32 als;
    gboolean isVoice;
    gboolean isVoicePrivacy;
    char number[QTI_RADIO_MAX_PHONE_NUMBER_LENGTH + 1];
    gint32 numberPresentation;
    char name[QTI_RADIO_MAX_CALLER_NAME_LENGTH + 1];
    gint32 namePresentation;
    //CallDetails* callDetails; // Parcelable
    //CallFailCauseResponse* failCause; // Parcelable
    gboolean isEncrypted;
    gboolean isCalledPartyRinging;
    char historyInfo[QTI_RADIO_MAX_HISTORY_INFO_LENGTH + 1];
    gboolean isVideoConfSupported;
    //VerstatInfo* verstatInfo; // Parcelable
    gint32 tirMode;
    gboolean isPreparatory;
    //CrsData* crsData; // Parcelable
    //CallProgressInfo* callProgInfo; // Parcelable
    char diversionInfo[QTI_RADIO_MAX_DIVERSION_INFO_LENGTH + 1];
    //MsimAdditionalCallInfo* additionalCallInfo; // Parcelable
    //AudioQuality* audioQuality; // Parcelable
    //gint32 modemCallId; // not in the data
} QtiRadioCallInfo;

typedef struct qti_radio_dial_request {
    GBinderHidlString address RADIO_ALIGNED(8);
    guint32 clir_mode RADIO_ALIGNED(4);
    guint32 presentation RADIO_ALIGNED(4);
    guint8 has_call_details RADIO_ALIGNED(1);
    QtiRadioCallDetails call_details RADIO_ALIGNED(8);
    guint8 has_is_conference_uri RADIO_ALIGNED(1);
    guint8 is_conference_uri RADIO_ALIGNED(1);
    guint8 has_is_call_pull RADIO_ALIGNED(1);
    guint8 is_call_pull RADIO_ALIGNED(1);
    guint8 has_is_encrypted RADIO_ALIGNED(1);
    guint8 is_encrypted RADIO_ALIGNED(1);
} RADIO_ALIGNED(8) QtiRadioDialRequest;

typedef struct qti_radio_hangup_request_info {
    guint32 conn_index RADIO_ALIGNED(4);
    guint8 has_multi_party RADIO_ALIGNED(1);
    guint8 multi_party RADIO_ALIGNED(1);
    GBinderHidlString conn_uri RADIO_ALIGNED(8);
    guint32 conf_id RADIO_ALIGNED(4);
    guint8 has_fail_cause_response RADIO_ALIGNED(1);
    QtiRadioCallFailCauseResponse fail_cause_response RADIO_ALIGNED(8);
} RADIO_ALIGNED(8) QtiRadioHangupRequestInfo;



#endif /* QTI_RADIO_EXT_TYPES_H */

/*
 * Local Variables:
 * mode: C
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
