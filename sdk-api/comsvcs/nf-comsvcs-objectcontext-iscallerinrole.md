# ObjectContext::IsCallerInRole

## Description

Indicates whether the object's direct caller is in a specified role (either directly or as part of a group).

## Parameters

### `bstrRole` [in]

The name of the role.

### `pbInRole` [out]

**TRUE** if the caller is in the specified role; **FALSE** otherwise. This parameter is also set to **TRUE** if security is not enabled.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The role specified in the *bstrRole* parameter is a recognized role, and the Boolean result returned in the *pbIsInRole* parameter indicates whether the caller is in that role. |
| **CONTEXT_E_ROLENOTFOUND** | The role specified in the bstrRole parameter does not exist. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [IsCallerInRole](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-iscallerinrole) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

Use this method to determine whether the direct caller of the currently executing method is associated with a specific role. A role is a symbolic name that represents a user or group of users who have specific access permissions to all components in a given COM+ application. Developers define roles when they create a component, and roles are mapped to individual users or groups at deployment time.

**IsCallerInRole** applies only to the direct caller of the currently executing method. (The direct caller is the process calling into the current server process. It can be either a base client process or a server process.) **IsCallerInRole** does not apply to the process that initiated the call sequence from which the current method was called or to any other callers in that sequence.

Because **IsCallerInRole** returns **TRUE** when the object that invokes it is executing in a client's process, it is a good idea to call [IsSecurityEnabled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-issecurityenabled) before calling **IsCallerInRole**. If security isn't enabled, **IsCallerInRole** will not return an accurate result.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)