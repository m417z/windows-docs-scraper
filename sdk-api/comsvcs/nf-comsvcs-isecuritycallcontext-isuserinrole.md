# ISecurityCallContext::IsUserInRole

## Description

Determines whether the specified user is in the specified role.

## Parameters

### `pUser` [in]

A pointer to value holding the User ID of the user whose role membership is to be checked. If you intend to pass the security identifier (SID) to **IsUserInRole**, this parameter should meet the following requirements: `V_VT(pUser) == (VT_ARRAY|VT_UI1) && V_ARRAY(pUser)->cDims == 1`.

### `bstrRole` [in]

The name of the role.

### `pfInRole` [out]

**TRUE** if the user is in the specified role; **FALSE** if not. If the specified role is not defined for the application, **FALSE** is returned. This parameter is set to **TRUE** if role-based security is not enabled.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The role specified in the *bstrRole* parameter is a recognized role, and the Boolean result returned in the *pfIsInRole* parameter indicates whether the user is in that role. |
| **CONTEXT_E_ROLENOTFOUND** | The role specified in the *bstrRole* parameter does not exist. |

## Remarks

Use this method to limit access to sections of code that should not be executed unless the caller is a member of the specified role. Windows groups and users are assigned to an application's roles using the Component Services administration tool. For more information about roles, see [Role-Based Security](https://learn.microsoft.com/windows/desktop/cossdk/role-based-security-administration).

Because **IsUserInRole** is **TRUE** when role-based security is not enabled, it is a good idea to call [IsSecurityEnabled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecuritycallcontext-issecurityenabled) before calling **IsUserInRole** to ensure that **IsUserInRole** returns useful information.

## See also

[ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext)

[Programmatic Component Security](https://learn.microsoft.com/windows/desktop/cossdk/programmatic-component-security)