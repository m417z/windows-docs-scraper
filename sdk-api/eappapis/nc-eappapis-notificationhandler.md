# NotificationHandler callback function

## Description

A callback prototype that notifies the supplicant that there is a change in the Statement of Health (SoH) and re-authentication of a [Network Access Protection](https://learn.microsoft.com/windows/desktop/NAP/network-access-protection-start-page) (NAP) system connection is required. For the user to receive visual notification of a change in the SoH, the callback must remain in place until after authentication is complete.

**Note** Never cancel the callback while re-authentication is in progress and the network connection is still valid. Never attempt to use any other mechanism to notify the supplicant that the SoH has changed.

## Parameters

### `connectionId` [in]

A GUID provided by the supplicant to EAPHost. This value specifies the logical network connection to re-authenticate.

### `pContextData` [in]

Context data provided to EAPHost by the supplicant. This context data can be used by the supplicant for re-authentication.

## Remarks

A pointer to this callback function must be provided when calling [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession). The callback may be called by EAPHost at any time prior to calling [EapHostPeerClearConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerclearconnection).

## See also

[EAPHost Supplicant Callbacks](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-callbacks)