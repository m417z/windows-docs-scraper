# SHAddFromPropSheetExtArray function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Adds pages to a property sheet extension array created by [SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray).

## Parameters

### `hpsxa` [in]

Type: **HPSXA**

The array of property sheet handlers returned by [SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray).

### `lpfnAddPage` [in]

Type: **LPFNADDPROPSHEETPAGE**

A pointer to an [AddPropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnaddpropsheetpage) callback function. It is called once for each property sheet handler. The callback function then returns the information needed to add a page to the handler's property sheet.

### `lParam`

Type: **LPARAM**

A pointer to application-defined data. This data is passed to the callback function specified by *lpfnAddPage*.

## Return value

Type: **UINT**

Returns the number of pages actually added.

## Remarks

This function should be called only once for the property sheet extension array named in *hpsxa*.

This function calls each extension's [IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages) method. See that page for further details.

## See also

[SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray)

[SHDestroyPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shdestroypropsheetextarray)

[SHReplaceFromPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shreplacefrompropsheetextarray)