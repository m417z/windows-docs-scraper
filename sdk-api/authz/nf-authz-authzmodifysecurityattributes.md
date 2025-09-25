# AuthzModifySecurityAttributes function

## Description

The **AuthzModifySecurityAttributes** function modifies the security attribute information in the specified client context.

## Parameters

### `hAuthzClientContext` [in]

A handle to the client context to be modified.

### `pOperations` [in]

A pointer to an array of [AUTHZ_SECURITY_ATTRIBUTE_OPERATION](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_security_attribute_operation) enumeration values that specify the types of modifications to make.

This array must have only one element if the value of that element is **AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE_ALL**. Otherwise, the array has the same number of elements as the *pAttributes* array.

### `pAttributes` [in]

A pointer to an [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure that specifies the attributes to modify.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).