# CoRevokeInitializeSpy function

## Description

Revokes a registered implementation of the [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) interface.

## Parameters

### `uliCookie` [in]

A [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1) cookie identifying the registration.

## Return value

This function can return the standard return value E_INVALIDARG, as well as S_OK to indicate success.

## Remarks

**CoRevokeInitializeSpy** can only revoke cookies issued by previous calls to [CoRegisterInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregisterinitializespy) that were executed on the current thread. Using a cookie from another thread, or one that corresponds to an already revoked registration, will return E_INVALIDARG.

It is unpredictable whether a call to **CoRevokeInitializeSpy** from within an [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) method call will have an effect during the current top-level (non-nested) call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize). The revocation will always have an effect after the current top-level call to **CoInitializeEx** or **CoUninitialize** returns.

## See also

[CoRegisterInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregisterinitializespy)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)