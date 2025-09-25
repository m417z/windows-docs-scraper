# SHUpdateImageW function

## Description

Notifies the Shell that an image in the system image list has changed.

## Parameters

### `pszHashItem` [in]

Type: **LPCTSTR**

A pointer to a string value that specifies the fully qualified path of the file that contains the icon. Use the path that is returned in the buffer pointed to by the *szIconFile* parameter of [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation).

### `iIndex` [in]

Type: **int**

An integer that specifies the zero-based index of the icon in the file specified by *pszHashItem*. Use the value that is pointed to by the *piIndex* parameter of [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation).

### `uFlags` [in]

Type: **UINT**

An unsigned integer that specifies the flags that determine the icon attributes. Set *uFlags* to the value that is pointed to by the *pwFlags* parameter of [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation). The flags that are relevant to **SHUpdateImage** are **GIL_NOTFILENAME** and **GIL_SIMULATEDOC**.

### `iImageIndex` [in]

Type: **int**

An integer that specifies the index in the system image list of the icon that is being updated.

## Remarks

If you do not know the index in the system image list of the icon that you want to update, use [SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa) with the *uFlags* parameter set to **SHGFI_SYSICONINDEX**.

You must use [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation) with the parameters of the old icon that needs to be updated, not those of the new icon you want to replace it with.

> [!NOTE]
> The shlobj_core.h header defines SHUpdateImage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify)