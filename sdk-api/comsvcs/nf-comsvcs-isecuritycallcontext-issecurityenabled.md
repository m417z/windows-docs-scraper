# ISecurityCallContext::IsSecurityEnabled

## Description

Determines whether security is enabled for the object.

## Parameters

### `pfIsEnabled` [out]

**TRUE** if the application uses role-based security and role checking is currently enabled for the object; otherwise, **FALSE**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

COM+ applications can use one of two types of security: role-based security or process access permissions. If role-based security is being used by the application but is currently disabled, either at the application or component level, *pfIsEnabled* is **FALSE**. Similarly, if the COM+ application uses process access permissions instead of role-based security, *pfIsEnabled* is **FALSE**.

You can use this method to find out whether role-based security is enabled before you check role membership using [IsCallerInRole](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecuritycallcontext-iscallerinrole). The reason for doing this is that **IsCallerInRole** is **TRUE** when role-based security is not enabled.

## See also

[ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext)

[Programmatic Component Security](https://learn.microsoft.com/windows/desktop/cossdk/programmatic-component-security)

[Role-Based Security](https://learn.microsoft.com/windows/desktop/cossdk/role-based-security-administration)