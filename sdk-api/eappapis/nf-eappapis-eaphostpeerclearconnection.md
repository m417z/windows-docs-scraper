# EapHostPeerClearConnection function

## Description

Clears the authentication session connection. After **EapHostPeerClearConnection** is called, all states associated with *pConnectionId* are deleted, and no re-authentication associated with this GUID will be initiated. In addition, all future callbacks to the [NotificationHandler](https://learn.microsoft.com/windows/desktop/api/eappapis/nc-eappapis-notificationhandler) callback function (which was passed by the calling supplicant in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession)) are halted.

## Parameters

### `pConnectionId` [in]

 A pointer to a GUID value that uniquely identifies a logical network interface for a connection to terminate between the supplicant and the EAPHost. This connection ID must have been provided in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession)

[EapHostPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerendsession)