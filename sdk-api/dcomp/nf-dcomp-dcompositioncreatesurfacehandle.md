# DCompositionCreateSurfaceHandle function

## Description

Creates a new composition surface object that can be bound to a
Microsoft DirectX swap chain or swap buffer and associated
with a visual.

## Parameters

### `desiredAccess` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The requested access to the composition surface object. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| 0x0000L | No access. |
| **COMPOSITIONOBJECT_READ**<br><br>0x0001L | Read access. For internal use only. |
| **COMPOSITIONOBJECT_WRITE**<br><br>0x0002L | Write access. For internal use only. |
| **COMPOSITIONOBJECT_ALL_ACCESS**<br><br>0x0003L | Read/write access. Always specify this flag except when duplicating a surface in another process, in which case set *desiredAccess* to 0. |

### `securityAttributes` [in, optional]

Type: **[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)***

Contains the security descriptor for the composition surface object, and specifies whether the handle of the composition surface object is inheritable when a child process is created. If this parameter is NULL, the composition surface object is created with default security attributes that grant read and write access to the current process, but do not enable child processes to inherit the handle.

### `surfaceHandle` [out]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The handle of the new composition surface object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.