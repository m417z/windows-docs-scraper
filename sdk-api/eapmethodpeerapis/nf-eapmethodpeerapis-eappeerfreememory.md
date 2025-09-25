# EapPeerFreeMemory function

## Description

Releases all memory associated with an opaque user interface context data buffer.

## Parameters

### `pUIContextData` [in]

A pointer to the user interface context data to free.

## Remarks

This method is called to release the user interface context data provided to the UI-specific EAP peer method APIs.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)

[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory)