# MAKEDLLVERULL macro

## Syntax

```cpp
ULONGLONG MAKEDLLVERULL(
    WORD major,
    WORD minor,
    WORD build,
    WORD qfe
);
```

## Return value

Type: **ULONGLONG**

Returns the version information packed into a ULONGLONG value.

## Description

Used to pack DLL version information into a ULONGLONG value.

## Parameters

### `major`

The major version number.

### `minor`

The minor version number.

### `build`

The build number.

### `qfe`

The hotfix number that identifies the service pack.

## Remarks

This macro is used in conjunction with [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc) to pack version information into a form that can easily be compared to the **ullVersion** member of a [DLLVERSIONINFO2](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo2) structure. It is defined as follows.

```cpp
#define MAKEDLLVERULL(major, minor, build, qfe) \
        (((ULONGLONG)(major) << 48) | \
         ((ULONGLONG)(minor) << 32) | \
         ((ULONGLONG)(build) << 16) | \
         ((ULONGLONG)(   qfe) <<  0))

```

For most purposes, you only need to assign values to the major and minor version numbers. The remaining two parameters can be set to zero. The following code fragment illustrates how to use **MAKEDLLVERULL** to determine whether a DLL is [version 4.71](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) or later. The **VersionInfo** structure is the [DLLVERSIONINFO2](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo2) structure returned by [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc).

```cpp
if(VersionInfo.ullVersion >= MAKEDLLVERULL(4, 71, 0, 0))
{
    ...
}

```