# DLLVERSIONINFO2 structure

## Description

Receives DLL-specific version information. It is used with the [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc) function.

## Members

### `info1`

Type: **[DLLVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo)**

A [DLLVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo) structure. This member is included to provide backward compatibility with applications that are not expecting a **DLLVERSIONINFO2** structure.

### `dwFlags`

Type: **DWORD**

Reserved.

### `ullVersion`

Type: **ULONGLONG**

A value that contains the version information. It is divided into four 16-bitfields containing the major and minor version numbers, the build number, and the hotfix version, in that order. Use the [MAKEDLLVERULL](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-makedllverull) macro to construct this value.

## Remarks

Your application must set the **cbSize** member of the structure pointed to by **info1** to **sizeof(****DLLVERSIONINFO2****)** before calling [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc). Otherwise, no value will be assigned to the **dwFlags** or **ullVersion** member of the **DLLVERSIONINFO2** structure.