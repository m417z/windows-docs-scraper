# ONEX\_CONNECTION\_PROFILE structure

The **ONEX\_CONNECTION\_PROFILE** structure contains information on the 802.1X connection profile currently used for 802.1X authentication.

## Members

**dwVersion**

The version of this **ONEX\_CONNECTION\_PROFILE** structure.

**dwTotalLen**

The length, in bytes, of this **ONEX\_CONNECTION\_PROFILE** structure.

**fOneXSupplicantFlags**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwOneXSupplicantFlags** member.

**fsupplicantMode**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **supplicantMode** member.

**fauthMode**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **authMode** member.

**fHeldPeriod**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwHeldPeriod** member.

**fAuthPeriod**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwAuthPeriod** member.

**fStartPeriod**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwStartPeriod** member.

**fMaxStart**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwMaxStart** member.

**fMaxAuthFailures**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwMaxAuthFailures** member.

**fNetworkAuthTimeout**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwNetworkAuthTimeout** member.

**fAllowLogonDialogs**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **bAllowLogonDialogs** member.

**fNetworkAuthWithUITimeout**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **dwNetworkAuthWithUITimeout** member.

**fUserBasedVLan**

Indicates if the **ONEX\_CONNECTION\_PROFILE** structure contains valid data in the **bUserBasedVLan** member.

**dwOneXSupplicantFlags**

A set of 802.1X flags that can be present in the profile. These flags are reserved for internal use by the 802.1X authentication module.

**supplicantMode**

The supplicantMode element in the 802.1X schema that specifies the method of transmission used for EAPOL-Start messages. For more information, see the [**supplicantMode (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#supplicantmode) in the 802.1X scheme.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**OneXSupplicantModeInhibitTransmission**

0

| EAPOL-Start messages are not transmitted. Valid for wired LAN profiles only.<br> |
|

**OneXSupplicantModeLearn**

1

| The client determines when to send EAPOL-Start packets based on network capability. EAPOL-Start messages are only sent when required. Valid for wired LAN profiles only.<br> |
|

**OneXSupplicantModeCompliant**

2

| EAPOL-Start messages are transmitted as specified by 802.1X. Valid for both wired and wireless LAN profiles.<br> |

**authMode**

The authMode element in the 802.1X schema that specifies the type of credentials used for 802.1X authentication. For more information, see the [**authMode (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#authmode) in the 802.1X scheme.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**OneXAuthModeMachineOrUser**

0

| Use machine or user credentials. When a user is logged on, the user's credentials are used for authentication. When no user is logged on, machine credentials are used.<br> |
|

**OneXAuthModeMachineOnly**

1

| Use machine credentials only.<br> |
|

**OneXAuthModeUserOnly**

2

| Use user credentials only.<br> |
|

**OneXAuthModeGuest**

3

| Use guest (empty) credentials only.<br> |
|

**OneXAuthModeUnspecified**

4

| Credentials to use are not specified.<br> |

**dwHeldPeriod**

The heldPeriod element in the 802.1X schema that specifies the length of time, in seconds, in which a client will not re-attempt authentication after a failed authentication attempt. For more information, see the [**heldPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#heldperiod) in the 802.1X scheme.

**dwAuthPeriod**

The authPeriod element in the 802.1X schema that specifies the maximum length of time, in seconds, in which a client waits for a response from the authenticator. If a response is not received within the specified period, the client assumes that there is no authenticator present on the network. For more information, see the [**authPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#authperiod) in the 802.1X scheme.

**dwStartPeriod**

The startPeriod element in the 802.1X schema that specifies the length of time, in seconds, to wait before an EAPOL-Start is sent. An EAPOL-Start message is sent to start the 802.1X authentication process. For more information, see the [**startPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#startperiod) in the 802.1X scheme.

**dwMaxStart**

The maxStart element in the 802.1X schema that specifies the maximum number of EAPOL-Start messages sent. After the maximum number of EAPOL-Start messages has been sent, the client assumes that there is no authenticator present on the network. For more information, see the [**maxStart (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#maxstart) in the 802.1X scheme.

**dwMaxAuthFailures**

The maxAuthFailures element in the 802.1X schema that specifies the maximum number of authentication failures allowed for a set of credentials. For more information, see the [**maxAuthFailures (OneX)**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#maxauthfailures) element in the 802.1X schema.

**dwNetworkAuthTimeout**

The time, in seconds, to wait for 802.1X authentication completion before normal logon proceeds. This value is used in single signon (SSO) scenarios. This value defaults to 10 seconds in an 802.1X profile. For more information, see the [**maxDelay (singleSignOn) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-singlesignon-onex-element#maxdelay) in the 802.1X schema.

**dwNetworkAuthWithUITimeout**

The maximum duration time, in seconds, to wait for a connection in case a user interface dialog box that requires user input is displayed during the per-logon SSO.

On Windows Vista with SP1 and later, this value is hardcoded to 10 minutes and is not configurable. On Windows Vista Release to Manufacturing, this value defaults to 60 seconds in an 802.1X profile and was controlled by the **maxDelayWithAdditionalDialogs** element in the schema.

On Windows Vista with SP1 and later, the **maxDelayWithAdditionalDialogs** element in the 802.1X schema is ignored and deprecated.

**bAllowLogonDialogs**

A value that specifies whether to allow EAP dialogs to be displayed when using pre-logon SSO. For more information, see the **allowAdditionalDialogs** element in the 802.1X schema.

**bUserBasedVLan**

The userBasedVirtualLan element in the 802.1X schema that specifies if the virtual LAN (VLAN) used by the device changes based on the user's credentials. Some network access server (NAS) devices change the VLAN after a user authenticates. When userBasedVirtualLan is TRUE, the NAS may change a device's VLAN after a user authenticates. For more information, see the [**userBasedVirtualLan (singleSignOn) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-singlesignon-onex-element#userbasedvirtuallan) in the 802.1X scheme.

## Remarks

The **ONEX\_CONNECTION\_PROFILE** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

The [**ONEX\_RESULT\_UPDATE\_DATA**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX\_RESULT\_UPDATE\_DATA** structure is returned when the **NotificationSource** member of the [**WLAN\_NOTIFICATION\_DATA**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN\_NOTIFICATION\_SOURCE\_ONEX** and the **NotificationCode** member of the **WLAN\_NOTIFICATION\_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN\_NOTIFICATION\_DATA** structure points to an **ONEX\_RESULT\_UPDATE\_DATA** structure that contains information on the 802.1X authentication status change.

If the **fOneXAuthParams** member in the [**ONEX\_RESULT\_UPDATE\_DATA**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is set, then the **authParams** member of the **ONEX\_RESULT\_UPDATE\_DATA** structure contains an [**ONEX\_VARIABLE\_BLOB**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) structure with an [**ONEX\_AUTH\_PARAMS**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params) structure embedded starting at the **dwOffset** member of the **ONEX\_VARIABLE\_BLOB**. The **oneXConnProfile** member of the **ONEX\_AUTH\_PARAMS** structure contains an **ONEX\_VARIABLE\_BLOB** structure with an **ONEX\_CONNECTION\_PROFILE** structure embedded starting at the **dwOffset** member of the **ONEX\_VARIABLE\_BLOB**.

The **ONEX\_CONNECTION\_PROFILE** structure is not defined in a public header file.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/win32/nativewifi/about-the-acm-architecture)

[OneX Schema](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-schema)

[**authMode (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#authmode)

[**authPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#authperiod)

[**heldPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#heldperiod)

[**maxAuthFailures (OneX)**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#maxauthfailures)

[**maxStart (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#maxstart)

[**startPeriod (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#startperiod)

[**supplicantMode (OneX) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element#supplicantmode)

[**userBasedVirtualLan (singleSignOn) Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-singlesignon-onex-element#userbasedvirtuallan)

[**ONEX\_AUTH\_PARAMS**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_auth_params)

[**ONEX\_NOTIFICATION\_TYPE**](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[**ONEX\_RESULT\_UPDATE\_DATA**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[**OneX Schema Element**](https://learn.microsoft.com/windows/win32/nativewifi/onexschema-onex-element)

[**ONEX\_VARIABLE\_BLOB**](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob)

[**WLAN\_NOTIFICATION\_DATA**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[**WlanRegisterNotification**](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)

