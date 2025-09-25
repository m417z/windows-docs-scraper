# AuditQueryGlobalSaclW function

## Description

The **AuditQueryGlobalSacl** function retrieves a global [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) that delegates access to the audit messages. Updating the global SACL requires the **SeSecurityPrivilege** which protects the global SACL from being updated by any user without administrator privileges.

## Parameters

### `ObjectTypeName` [in]

A pointer to a null-terminated string specifying the type of object being accessed. This parameter must be either "File" or "Key", depending on whether the object is a file or registry. This string appears in any audit message that the function generates.

### `Acl` [out]

A pointer to an [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure that contains the SACL information. This should be freed later by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

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

> [!NOTE]
> The ntsecapi.h header defines AuditQueryGlobalSacl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).