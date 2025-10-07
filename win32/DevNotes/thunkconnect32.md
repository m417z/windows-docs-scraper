# ThunkConnect32 function

\[This function was supported for backward compatibility, but is not present in current versions of Windows. New device drivers should be 32- or 64-bit and do not need this function.\]

The **ThunkConnect32** function is used by 16-bit device drivers (for MS-DOS) that call into the 32-bit kernel.

## Parameters

*lpThunkData32*

Ignored.

*pszThunkData16Name*

Ignored.

*pszDll16*

Ignored.

*pszDll32*

Ignored.

*hInstance*

Ignored.

*dwReason*

Ignored.

## Return value

Always returns **FALSE**.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Kernel32.dll |

