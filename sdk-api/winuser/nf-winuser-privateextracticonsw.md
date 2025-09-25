# PrivateExtractIconsW function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Creates an array of handles to icons that are extracted from a specified file.

## Parameters

### `szFileName` [in]

Type: **LPCTSTR**

The path and name of the file
from which the icon(s) are to be extracted.

### `nIconIndex` [in]

Type: **int**

The zero-based index of the first icon to extract. For example,
if this value is zero, the function extracts the first icon in the specified
file.

### `cxIcon` [in]

Type: **int**

The horizontal icon size wanted. See Remarks.

### `cyIcon` [in]

Type: **int**

The vertical icon size wanted. See Remarks.

### `phicon` [out, optional]

Type: **HICON***

A pointer to the returned array of icon handles.

### `piconid` [out, optional]

Type: **UINT***

A pointer to a returned resource identifier for the icon that best
fits the current display device. The returned identifier is 0xFFFFFFFF if the
identifier is not available for this format. The returned identifier is 0 if
the identifier cannot otherwise be obtained.

### `nIcons` [in]

Type: **UINT**

The number of icons to extract from the file. This parameter
is only valid when extracting from .exe and .dll files.

### `flags` [in]

Type: **UINT**

Specifies flags that control this function. These flags are the LR_*
flags used by the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) function.

## Return value

Type: **UINT**

If the *phicon* parameter is **NULL** and this function succeeds, then the return
value is the number of icons in the file. If the function fails then the
return value is 0.

If the *phicon* parameter is
not **NULL** and the function succeeds, then the return value is the
number of icons extracted. Otherwise, the return value is 0xFFFFFFFF if the file
is not found.

## Remarks

This function extracts from executable (.exe), DLL (.dll),
icon (.ico), cursor (.cur), animated cursor (.ani), and bitmap (.bmp) files.
Extractions from Windows 3.x 16-bit executables (.exe or .dll) are
also supported.

The *cxIcon* and
*cyIcon* parameters specify the
size of the icons to extract. Two sizes can be extracted by putting the
first size in the LOWORD of the parameter and the second size in the HIWORD.
For example, `MAKELONG(24, 48)` for both the cxIcon and cyIcon parameters would extract
both 24 and 48 size icons.

You must destroy all icons extracted by **PrivateExtractIcons** by calling the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

This function was not included in the SDK headers and libraries until Windows XP Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

> [!NOTE]
> The winuser.h header defines PrivateExtractIcons as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon)

[ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona)

[ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

**Reference**