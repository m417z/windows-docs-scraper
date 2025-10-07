# AuthzFreeGroupsCallback callback function

The **AuthzFreeGroupsCallback** function is an application-defined function that frees memory allocated by the [**AuthzComputeGroupsCallback**](https://learn.microsoft.com/windows/win32/secauthz/authzcomputegroupscallback) function. **AuthzFreeGroupsCallback** is a placeholder for the application-defined function name.

## Parameters

*pSidAttrArray* \[in\]

A pointer to memory allocated by [**AuthzComputeGroupsCallback**](https://learn.microsoft.com/windows/win32/secauthz/authzcomputegroupscallback).

## Return value

This callback function does not return a value.

## Remarks

Attribute variables must be in the form of an expression when used with logical operators; otherwise, they are evaluated as unknown.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Windows Server 2003 Administration Tools Pack on Windows XP<br> |

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/win32/secauthz/authorization-functions)

[**AuthzComputeGroupsCallback**](https://learn.microsoft.com/windows/win32/secauthz/authzcomputegroupscallback)

