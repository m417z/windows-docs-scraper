# AuthzComputeGroupsCallback callback function

The **AuthzComputeGroupsCallback** function is an application-defined function that creates a list of [*security identifiers*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) that apply to a client. **AuthzComputeGroupsCallback** is a placeholder for the application-defined function name.

## Parameters

*hAuthzClientContext* \[in\]

A handle to a client context.

*Args* \[in\]

Data passed in the *DynamicGroupArgs* parameter of a call to the [**AuthzInitializeContextFromAuthzContext**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromauthzcontext), [**AuthzInitializeContextFromSid**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromsid), or [**AuthzInitializeContextFromToken**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromtoken) function.

*pSidAttrArray* \[out\]

A pointer to a pointer variable that receives the address of an array of [**SID\_AND\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/Winnt/ns-winnt-sid_and_attributes) structures. These structures represent the groups to which the client belongs.

*pSidCount* \[out\]

The number of structures in *pSidAttrArray*.

*pRestrictedSidAttrArray* \[out\]

A pointer to a pointer variable that receives the address of an array of [**SID\_AND\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/Winnt/ns-winnt-sid_and_attributes) structures. These structures represent the groups from which the client is restricted.

*pRestrictedSidCount* \[out\]

The number of structures in *pSidRestrictedAttrArray*.

## Return value

If the function successfully returns a list of SIDs, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

Applications can also add SIDs to the client context by calling [**AuthzAddSidsToContext**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaddsidstocontext).

Attribute variables must be in the form of an expression when used with logical operators; otherwise, they are evaluated as unknown.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Windows Server 2003 Administration Tools Pack on Windows XP<br> |

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/win32/secauthz/authorization-functions)

[**AuthzAddSidsToContext**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaddsidstocontext)

[**AuthzCachedAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzcachedaccesscheck)

[**AuthzInitializeContextFromAuthzContext**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromauthzcontext)

[**AuthzInitializeContextFromSid**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromsid)

[**AuthzInitializeContextFromToken**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializecontextfromtoken)

[**AuthzInitializeResourceManager**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzinitializeresourcemanager)

[**SID\_AND\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/Winnt/ns-winnt-sid_and_attributes)

