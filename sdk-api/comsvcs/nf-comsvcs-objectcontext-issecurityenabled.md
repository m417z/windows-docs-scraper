# ObjectContext::IsSecurityEnabled

## Description

Indicates whether security is enabled for the current object.

## Parameters

### `pbIsEnabled` [out]

**TRUE** if security is enabled for this object; **FALSE** otherwise.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [IsSecurityEnabled](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-issecurityenabled) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

In the COM+ environment, server and library applications can use role-based security. **IsSecurityEnabled** returns **TRUE** when an application uses role-based security, and role-based security is enabled both for the application and the specific component that called the method.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)