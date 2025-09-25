# CoRegisterClassObject function

## Description

Registers an EXE class object with OLE so other applications can connect to it.

## Parameters

### `rclsid` [in]

The CLSID to be registered.

### `pUnk` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the class object whose availability is being published.

### `dwClsContext` [in]

The context in which the executable code is to be run. For information on these context values, see the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `flags` [in]

Indicates how connections are made to the class object. For information on these flags, see the [REGCLS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-regcls) enumeration.

### `lpdwRegister` [out]

A pointer to a value that identifies the class object registered; later used by the [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) function to revoke the registration.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The class object was registered successfully. |

## Remarks

EXE object applications should call **CoRegisterClassObject** on startup. It can also be used to register internal objects for use by the same EXE or other code (such as DLLs) that the EXE uses.
Only EXE object applications call **CoRegisterClassObject**. Object handlers or DLL object applications do not call this function — instead, they must implement and export the [DllGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject) function.

At startup, a multiple-use EXE object application must create a class object (with the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface on it), and call **CoRegisterClassObject** to register the class object. Object applications that support several different classes (such as multiple types of embeddable objects) must allocate and register a different class object for each.

Multiple registrations of the same class object are independent and do not produce an error. Each subsequent registration yields a unique key in *lpdwRegister*.

Multiple document interface (MDI) applications must register their class objects. Single document interface (SDI) applications must register their class objects only if they can be started by means of the **/Embedding** switch.

The server for a class object should call [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) to revoke the class object (remove its registration) when all of the following are true:

* There are no existing instances of the object definition.
* There are no locks on the class object.
* The application providing services to the class object is not under user control (not visible to the user on the display).

After the class object is revoked, when its reference count reaches zero, the class object can be released, allowing the application to exit. Note that **CoRegisterClassObject** calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) and [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) calls [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), so the two functions form an **AddRef**/**Release** pair.

As of Windows Server 2003, if a COM object application is registered as a service, COM verifies the registration. COM makes sure the process ID of the service, in the service control manager (SCM), matches the process ID of the registering process. If not, COM fails the registration. If the COM object application runs in the system account with no registry key, COM treats the objects application identity as [Launching User](https://learn.microsoft.com/windows/desktop/com/launching-user).

## See also

[CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx)

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject)

[DllGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject)

[REGCLS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-regcls)