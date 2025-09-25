# SHOpenPropSheetW function

## Description

[**SHOpenPropSheet** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a property sheet from a list of registry keys that contain the **CLSID**s of the individual sheets, then opens the property sheet.

## Parameters

### `pszCaption` [in, optional]

Type: **LPCTSTR**

A pointer to a string that contains the caption for the property sheet. This value can be **NULL** if no caption is needed.

### `ahkeys` [in, optional]

Type: **HKEY[]**

An array of registry keys that represent the **CLSID**s of the individual property sheets.

### `ckeys`

Type: **UINT**

**UINT** value that specifies the number of property sheets in the array specified by *ahkeys*.

### `pclsidDefault` [in, optional]

Type: **const CLSID***

A pointer to the default **CLSID**. This value can be **NULL**.

### `pdtobj` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), an OLE object that can be used to carry out actions on the property sheet(s).

### `psb` [in, optional]

Type: **[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)***

Not used.

### `pStartPage` [in, optional]

Type: **LPCTSTR**

A pointer to a string that specifies the start page. This value can be **NULL**.

## Return value

Type: **BOOL**

Returns **TRUE** if the property sheet was successfully created; otherwise, **FALSE**.

## Remarks

> [!NOTE]
> The shlobj.h header defines SHOpenPropSheet as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).