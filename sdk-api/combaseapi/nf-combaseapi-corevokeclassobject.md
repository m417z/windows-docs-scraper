# CoRevokeClassObject function

## Description

Informs OLE that a class object, previously registered with the [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) function, is no longer available for use.

## Parameters

### `dwRegister` [in]

A token previously returned from the [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) function.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The class object was revoked successfully. |

## Remarks

A successful call to **CoRevokeClassObject** means that the class object has been removed from the global class object table (although it does not release the class object). If other clients still have pointers to the class object and have caused the reference count to be incremented by calls to [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), the reference count will not be zero. When this occurs, applications may benefit if subsequent calls (with the obvious exceptions of **AddRef** and [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release)) to the class object fail. Note that [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) calls **AddRef** and **CoRevokeClassObject** calls **Release**, so the two functions form an **AddRef**/**Release** pair.

An object application must call **CoRevokeClassObject** to revoke registered class objects before exiting the program. Class object implementers should call **CoRevokeClassObject** as part of the release sequence. You must specifically revoke the class object even when you have specified the flags value REGCLS_SINGLEUSE in a call to [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject), indicating that only one application can connect to the class object.

## See also

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)