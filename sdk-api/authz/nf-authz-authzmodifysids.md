# AuthzModifySids function

## Description

The **AuthzModifySids** function adds, deletes, or modifies user and device groups in the Authz client context.

## Parameters

### `hAuthzClientContext` [in]

A handle to the client context to be modified.

### `SidClass` [in]

Type of information to be modified. The caller can specify AuthzContextInfoGroupsSids, AuthzContextInfoRestrictedSids, or AuthzContextInfoDeviceSids.

### `pSidOperations` [in]

A pointer to an array of [AUTHZ_SID_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_sid_operation) enumeration values that specify the group modifications to make.

### `pSids` [in, optional]

A pointer to a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that specifies the groups to modify.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [AUTHZ_SID_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_sid_operation) enumeration must have only one element if the value of that element is AUTHZ_SID_OPERATION_REPLACE_ALL. Otherwise, the array has the same number of elements as the corresponding
PTOKEN_GROUPS.

When you want to use **AuthzModifySids** to delete, the SIDs are matched but not the SID flags. If no matching SID is found, no modifications are done and the call fails.