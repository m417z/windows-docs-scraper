# IExtractIconA::Extract

## Description

Extracts an icon image from the specified location.

## Parameters

### `pszFile` [in]

Type: **PCTSTR**

A pointer to a null-terminated string that specifies the icon location.

### `nIconIndex`

Type: **UINT**

The index of the icon in the file pointed to by *pszFile*.

### `phiconLarge` [out, optional]

Type: **HICON***

A pointer to an **HICON** value that receives the handle to the large icon. This parameter may be **NULL**.

### `phiconSmall` [out, optional]

Type: **HICON***

A pointer to an **HICON** value that receives the handle to the small icon. This parameter may be **NULL**.

### `nIconSize`

Type: **UINT**

The desired size of the icon, in pixels. The low word contains the size of the large icon, and the high word contains the size of the small icon. The size specified can be the width or height. The width of an icon always equals its height.

## Return value

Type: **HRESULT**

Returns S_OK if the function extracted the icon, or S_FALSE if the calling application should extract the icon.

## Remarks

The icon location and index are the same values returned by the [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation) method. If **IExtractIcon::Extract** function returns S_FALSE, these values must specify an icon file name and index that form legal parameters for a call to [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona). If **IExtractIcon::Extract** does not return S_FALSE, no assumptions should be made about the meanings of the *pszFile* and *nIconIndex* parameters.

## See also

[IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona)