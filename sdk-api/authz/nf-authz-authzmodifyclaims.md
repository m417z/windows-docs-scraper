# AuthzModifyClaims function

## Description

The **AuthzModifyClaims** function adds, deletes, or modifies user and device claims in the Authz client context.

## Parameters

### `hAuthzClientContext` [in]

A handle to the client context to be modified.

### `ClaimClass` [in]

Type of information to be modified. The caller can specify AuthzContextInfoUserClaims or AuthzContextInfoDeviceClaims.

### `pClaimOperations` [in]

A pointer to an array of [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration values that specify the type of claim modification to make.

### `pClaims` [in, optional]

A pointer to an [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that specifies the claims to modify.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration must have only one element if
the value of that element is AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE_ALL.
Otherwise, the array has the same number of elements as the corresponding
PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION.

If the [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration is AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE and the function fails, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the error code is ERROR_ALREADY_EXISTS, the claim's values have duplicate entries.