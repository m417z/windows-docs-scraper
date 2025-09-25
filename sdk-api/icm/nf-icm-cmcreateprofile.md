## Description

\[**CMCreateProfile** is no longer available for use as of Windows Vista.\]

Creates a display color profile from a [**LOGCOLORSPACEA**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logcolorspacea) structure.

## Parameters

### `lpColorSpace`

Pointer to a color logical space, of which the **lcsFilename** member will be **NULL**.

### `lpProfileData`

Pointer to a pointer to a buffer. If successful the function allocates and fills this buffer. It is the calling application's responsibility to free this buffer when it is no longer needed.

## Return value

Beginning with Windows Vista, the default CMM (Icm32.dll) will return **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will report ERROR\_NOT\_SUPPORTED.

**Windows Server 2003, Windows XP and Windows 2000:**

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error.

## Remarks

Beginning with Windows Vista, CMM Implementors are no longer required to implement this method.

**Windows Server 2003, Windows XP and Windows 2000:**

The Unicode version of this function is [**CMCreateProfileW**](https://msdn.microsoft.com/en-us/library/dd371864/(v=vs.85/)).

Only the Windows default CMM is required to export this function; it is optional for all other CMMs.

If a CMM does not support **CMCreateProfile**, Windows uses the default CMM to create the profile.

The CMM should set all header fields to sensible defaults. This profile should be usable as the input profile in a transform.

The calling application must free the buffer allocated by this function and pointed to by the *lpProfileData* parameter. Use [**GlobalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree) to free the buffer.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [CMCreateProfileW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-cmcreateprofilew)