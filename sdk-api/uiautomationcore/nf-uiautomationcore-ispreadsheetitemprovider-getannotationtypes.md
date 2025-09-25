# ISpreadsheetItemProvider::GetAnnotationTypes

## Description

Retrieves an array of annotation type identifiers indicating the types of annotations that are associated with this spreadsheet cell.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives an array of annotation type identifiers, one for each type of annotation associated with the spreadsheet cell. For a list of possible values, see [Annotation Type Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-annotation-type-identifiers).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

[ISpreadsheetItemProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-ispreadsheetitemprovider)