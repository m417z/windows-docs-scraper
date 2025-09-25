# IAzClientContext::GetProperty

## Description

The **GetProperty** method returns the [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value will always be **FALSE** because this object cannot have child objects. |
| **AZ_PROP_CLIENT_CONTEXT_ROLE_FOR_ACCESS_CHECK** | Also accessed through the [RoleForAccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_roleforaccesscheck) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_CANONICAL** | Also accessed through the [UserCanonical](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_usercanonical) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_DISPLAY** | Also accessed through the [UserDisplay](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_userdisplay) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_DN** | Also accessed through the [UserDn](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_userdn) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_DNS_SAM_COMPAT** | Also accessed through the [UserDnsSamCompat](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_userdnssamcompat) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_GUID** | Also accessed through the [UserGuid](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_userguid) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_SAM_COMPAT** | Also accessed through the [UserSamCompat](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_usersamcompat) property |
| **AZ_PROP_CLIENT_CONTEXT_USER_UPN** | Also accessed through the [UserUpn](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-get_userupn) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object property.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.