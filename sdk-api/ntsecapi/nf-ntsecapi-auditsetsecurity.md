# AuditSetSecurity function

## Description

The **AuditSetSecurity** function sets a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that delegates access to audit policy.

## Parameters

### `SecurityInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies which parts of the security descriptor this function sets. Only **SACL_SECURITY_INFORMATION** and **DACL_SECURITY_INFORMATION** are supported. Any other values are ignored. If neither **SACL_SECURITY_INFORMATION** nor **DACL_SECURITY_INFORMATION** is specified, this function fails and returns **ERROR_INVALID_PARAMETER**.

### `pSecurityDescriptor` [in]

A pointer to a well-formed [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that controls access to the [Audit security object](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). If this parameter is **NULL**, the function fails and returns **ERROR_INVALID_PARAMETER**.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes defined in WinError.h.

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | The caller does not have the privilege or access rights necessary to call this function. |
| **ERROR_INVALID_PARAMETER**<br><br>87 | One or more parameters are invalid. |

## Remarks

To successfully call this function, the caller must have **SeSecurityPrivilege**.

## See also

[AuditQuerySecurity](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysecurity)