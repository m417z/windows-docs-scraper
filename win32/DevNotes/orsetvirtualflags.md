# ORSetVirtualFlags function

Sets virtualization flags on the specified open registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*dwFlags* \[in\]

This parameter controls the behavior of the registry when a Create or Open operation fails on a key in a virtualized hive. This parameter can be one or more of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **REG\_KEY\_DONT\_SILENT\_FAIL**<br>4 | If this flag is set and an Open operation fails on a key for which virtualization is enabled, the registry does not attempt to reopen the key. If this flag is clear, the registry attempts to reopen the key with the MAXIMUM\_ALLOWED access.<br> |
| **REG\_KEY\_DONT\_VIRTUALIZE**<br>2 | If this flag is set and a Create Key operation fails because the caller does not have the KEY\_CREATE\_SUB\_KEY right on the parent key, the registry fails the Create operation. If this flag is clear, the registry attempts to create the key in the virtual store. The caller must have the KEY\_READ right on the parent key.<br> |
| **REG\_KEY\_RECURSE\_FLAG**<br>8 | If this flag is set, registry virtualization flags are propagated from the parent key. If this flag is clear, registry virtualization flags are not propagated.<br> |

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

## Remarks

Registry virtualization is an interim application compatibility technology that enables registry write operations that have global impact to be redirected to per-user locations. This redirection is transparent to applications reading from or writing to the registry.

Registry virtualization is supported starting with Windows Vista. However, Microsoft intends to remove it from future versions of the Windows operating system as more applications are made compatible with Windows Vista. Therefore, applications should not depend on the behavior of registry virtualization in the system.

Registry virtualization is enabled only for the following:

- 32-bit interactive processes
- Keys in **HKEY\_LOCAL\_MACHINE\\Software**
- Keys that an administrator can write to

For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/win32/sysinfo/registry-virtualization).

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORGetVirtualFlags**](https://learn.microsoft.com/windows/win32/devnotes/orgetvirtualflags)

[Registry Virtualization](https://learn.microsoft.com/windows/win32/sysinfo/registry-virtualization)

