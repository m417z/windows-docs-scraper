# IShellPropSheetExt::ReplacePage

## Description

Replaces a page in a property sheet for a Control Panel object.

## Parameters

### `uPageID`

Type: **UINT**

Not used.

**Microsoft Windows XP and earlier:** A type EXPPS identifier of the page to replace. The values for this parameter for Control Panels can be found in the Cplext.h header file.

### `pfnReplaceWith` [in]

Type: **LPFNADDPROPSHEETPAGE**

A pointer to a function that the property sheet handler calls to replace a page to the property sheet. The function takes a property sheet handle returned by the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function and the *lParam* parameter passed to the **ReplacePage** method.

### `lParam` [in]

Type: **LPARAM**

The parameter to pass to the function specified by the *pfnReplacePage* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To replace a page, a property sheet handler fills a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure, calls [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea), and then calls the function specified by *pfnReplacePage*.