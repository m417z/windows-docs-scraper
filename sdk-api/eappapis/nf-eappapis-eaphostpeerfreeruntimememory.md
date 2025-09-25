# EapHostPeerFreeRuntimeMemory function

## Description

Releases the memory space used during run-time.

## Parameters

### `pData` [in]

A pointer to a buffer returned by any EapHost peer run-time API.

## Remarks

This method is called to release a specified memory buffer returned by any EAPHost peer run-time APIs.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Supplicant Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerInvokeIdentityUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeidentityui)