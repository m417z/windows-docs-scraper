# IGetSecurityCallContext::GetSecurityCallContext

## Description

Retrieves a reference to an object created from the [SecurityCallContext](https://learn.microsoft.com/windows/desktop/cossdk/securitycallcontext) class that is associated with the current call.

Instead of using this method, C++ developers should use the [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext) function, supplying IID_ISecurityCallContext for the *riid* parameter.

## Parameters

### `ppObject` [out]

A reference to [ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext) on the object's context.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOCONTEXT** | The current object does not have a context associated with it because either the component wasn't imported into an application or the object was not created with one of the COM+ CreateInstance methods. This error is also returned if the GetObjectContext method was called from a constructor or from an IUnknown method. |

## Remarks

With an object's security call context, you can retrieve items in the security call context collection, such as the minimum authentication level, the direct caller, the original caller, the chain of callers, and the number of callers. You can also call the [IsSecurityEnabled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecuritycallcontext-issecurityenabled) and [IsCallerInRole](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecuritycallcontext-iscallerinrole) methods to ensure that a particular section of code is executed. However, you can call these methods only if role-based security is enabled and if the direct caller is a member of a specified role.

## See also

[COM+ Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)

[CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext)

[IGetSecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetsecuritycallcontext)

[ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext)