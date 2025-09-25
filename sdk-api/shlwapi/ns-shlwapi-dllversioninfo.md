# DLLVERSIONINFO structure

## Description

Receives DLL-specific version information. It is used with the [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc) function.

**Note** In place of this structure, you can use the [DLLVERSIONINFO2](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo2) structure.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. This member must be filled in before calling the function.

### `dwMajorVersion`

Type: **DWORD**

The major version of the DLL. For instance, if the DLL's version is 4.0.950, this value will be 4.

### `dwMinorVersion`

Type: **DWORD**

The minor version of the DLL. For instance, if the DLL's version is 4.0.950, this value will be 0.

### `dwBuildNumber`

Type: **DWORD**

The build number of the DLL. For instance, if the DLL's version is 4.0.950, this value will be 950.

### `dwPlatformID`

Type: **DWORD**

Identifies the platform for which the DLL was built. This can be one of the following values.

#### DLLVER_PLATFORM_WINDOWS (0x00000001)

The DLL was built for earlier Windows platforms such as Windows 95.

#### DLLVER_PLATFORM_NT (0x00000002)

The DLL was built for platforms such as Windows 2000, Windows Vista, or Windows 7.

## See also

[DLLVERSIONINFO2](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo2)

[DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc)