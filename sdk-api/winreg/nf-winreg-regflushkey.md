# RegFlushKey function

## Description

Writes all the attributes of the specified open registry key into the registry.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_PERFORMANCE_DATA**

**HKEY_USERS**

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

Calling **RegFlushKey** is an expensive operation that significantly affects system-wide performance as it consumes disk bandwidth and blocks modifications to all keys by all processes in the registry hive that is being flushed until the flush operation completes. **RegFlushKey** should only be called explicitly when an application must guarantee that registry changes are persisted to disk immediately after modification. All modifications made to keys are visible to other processes without the need to flush them to disk.

Alternatively, the registry has a 'lazy flush' mechanism that flushes registry modifications to disk at regular intervals of time. In addition to this regular flush operation, registry changes are also flushed to disk at system shutdown. Allowing the 'lazy flush' to flush registry changes is the most efficient way to manage registry writes to the registry store on disk.

The
**RegFlushKey** function returns only when all the data for the hive that contains the specified key has been written to the registry store on disk.

The
**RegFlushKey** function writes out the data for other keys in the hive that have been modified since the last lazy flush or system start.

 After **RegFlushKey** returns, use [RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) to close the handle to the registry key.

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)