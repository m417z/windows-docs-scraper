# EapHostPeerInitialize function

## Description

Initializes an EAPHost authentication session.

The **EapHostPeerInitialize** function must be called before any other peer or supplicant function is called. If the **EapHostPeerInitialize** function fails, do not call any other EAPHost run-time API.

**Note** The other EAPHost configuration APIs aren't affected by the failure of **EAPHostPeerInitialize.**

## Remarks

**EapHostPeerInitialize** and [EapHostPeerUninitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeeruninitialize) are always thread
safe.

The following call occurs within the **EapHostPeerInitialize** function:

`CoInitializeEx(NULL, COINIT_MULTITHREADED);`

The client should not initialize a conflicting COM environment.
If different COM environment (such as a single-threaded apartment) is required, the client should call [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) directly, and not call **EapHostPeerInitialize**. If **CoInitializeEx** is called directly, then the client must call [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) to uninitialize the session. In addition, the client must use COM functions (and not EAPHost supplicant functions) to allocate and free memory.

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerUninitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeeruninitialize)