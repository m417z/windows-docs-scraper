# SHDestroyPropSheetExtArray function

## Description

[**SHDestroyPropSheetExtArray** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Frees property sheet handlers that are pointed to an array created by [SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray).

## Parameters

### `hpsxa` [in]

Type: **HPSXA**

The handle of the array that contains pointers to the property sheet handlers to destroy.

## See also

[SHAddFromPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddfrompropsheetextarray)

[SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray)

[SHReplaceFromPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shreplacefrompropsheetextarray)