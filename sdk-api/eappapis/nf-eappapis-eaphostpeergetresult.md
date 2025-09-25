# EapHostPeerGetResult function

## Description

Obtains the authentication result for the specified EAP authentication session.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `reason` [in]

An [EapHostPeerMethodResultReason](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeermethodresultreason) enumeration value that specifies the reason code for the authentication result returned in *ppResult*.

### `ppResult` [out]

A pointer to a [EapHostPeerMethodResultReason](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeermethodresultreason) structure that contains the authentication results. EAPHost fills this structure with authentication related information defined in [EapHostPeerMethodResult](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ns-eaphostpeertypes-eaphostpeermethodresult).

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. Supplicants must refer to this parameter to determine if the authentication was successful. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## Return value

If the function succeeds, the return value is **NO_ERROR**. The return value does not indicate if the authentication was successful. Supplicants must refer to the *ppEapError* parameter to determine the authentication result.

If the function fails, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

The supplicant calls **EapHostPeerGetResult** on completion of an authentication, which can occur in any of the following scenarios.

* A call to [EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerprocessreceivedpacket) returned the **EapHostPeerResponseResult** action code.
* The client timed out and wants to get the result based on the current
  state.
* The supplicant received an alternate result, perhaps from a packet on the
  lower layer.

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerprocessreceivedpacket)