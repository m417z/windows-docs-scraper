# SHExtractIconsW function

Creates an array of handles to icons extracted from a specified file.

> [!NOTE]
> This function is available through Windows XP Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions. Use [SHDefExtractIcon](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shdefextracticonw) function instead.

## Parameters

*pszFileName* \[in\]

Type: **LPCWSTR**

A pointer to the file name from which to extract the icons.

*nIconIndex* \[in\]

Type: **int**

The index of the first icon to extract from the resource named in *pszFileName*.

*cxIcon* \[in\]

Type: **int**

The desired width of the icon. See Remarks.

*cyIcon* \[in\]

Type: **int**

The desired height of the icon. See Remarks.

*phIcon* \[out\]

Type: **HICON\***

When this function returns, contains a pointer to the array of icon handles.

*pIconId* \[out\]

Type: **UINT\***

When this function returns, contains a pointer to the resource identifier of the extracted icon that best fits the current display device. If there is no identifier available for this format, it contains 0xFFFFFFFF. If no identifier can be obtained for any other reason, returns zero.

*nIcons* \[in\]

Type: **UINT**

The number of icons to extract from the resource named in *pszFileName*. This parameter is valid only when the resource is a .exe or .dll file.

*flags* \[in\]

Type: **UINT**

The flags that control this function. For possible values, see the *fuLoad* parameter of the [**LoadImage**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadimagea) function.

## Return value

Type: **UINT**

A nonzero value if successful; otherwise, zero.

## Remarks

**SHExtractIconsW** extracts from the following file types.

- Executable (.exe)
- DLL (.dll)
- Icon (.ico)
- Cursor (.cur)
- Animated cursor (.ani)
- Bitmap (.bmp)

Extractions from Windows 3.*x* 16-bit executable files (.exe or .dll) are also supported.

The *cxIcon* and *cyIcon* parameters specify the size of the icons to extract. Two sizes can be extracted through each parameter by splitting the value between its LOWORD and HIWORD. Put the first desired size in the LOWORD of the parameter and the second size in the HIWORD. For example, [**MAKELONG**](https://learn.microsoft.com/windows/win32/winmsg/makelong)(24, 48) for both *cxIcon* and *cyIcon* extracts both 24 and 48 sized icons.

The calling process is responsible for destroying all icons extracted through this function by calling the [**DestroyIcon**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) function.

**SHExtractIconsW** is not exported by name or declared in a public header file. To use it, you must declare a matching prototype and use [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to request a function pointer from Shell32.dll that can be used to call this function.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **SHExtractIconsW** (Unicode)<br> |

