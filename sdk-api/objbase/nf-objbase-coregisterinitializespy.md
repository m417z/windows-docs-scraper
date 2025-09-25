## Description

Registers an implementation of the [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) interface. The **IInitializeSpy** interface is defined to allow developers to perform initialization and cleanup on COM apartments.

## Parameters

### `pSpy` [in]

A pointer to an instance of the [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) implementation.

### `puliCookie` [out]

The address at which to store a cookie that identifies this registration.

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was successfully registered. |
| **E_NOINTERFACE** | The object does not support [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy). |

## Remarks

The **CoRegisterInitializeSpy** function registers an implementation of the [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) interface, which defines methods to be called when [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) (or [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize)) or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) is invoked.

**CoRegisterInitializeSpy** calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for IID_InitializeSpy on *pSpy*. It stores the address of the returned interface pointer in thread-specific storage that is independent of the COM initialization state for this thread. On success, it stores in *puliCookie* a [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1) cookie that represents this registration. Pass this cookie to [CoRevokeInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-corevokeinitializespy) to revoke the registration.

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) implementations must deal with nesting issues caused by calling [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) from within a notification method. Notifications occur only after the registration happens on this thread. For example, if **CoInitializeEx** is called before **CoRegisterInitializeSpy**, then the [PreInitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iinitializespy-preinitialize) and [PostInitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iinitializespy-postinitialize) notification methods will not be called.

Notification methods must not cause the failure of [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) by throwing exceptions. Implementations of [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) must not propagate exceptions to code that calls **CoInitializeEx** or **CoUninitialize**.

It is unpredictable whether a call to **CoRegisterInitializeSpy** from within an [IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy) method call will be effective during the current top-level (non-nested) call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize). A registered implementation of **IInitializeSpy** will always be effective for future top-level calls to **CoInitializeEx** or **CoUninitialize**.

## See also

[CoRevokeInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-corevokeinitializespy)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)