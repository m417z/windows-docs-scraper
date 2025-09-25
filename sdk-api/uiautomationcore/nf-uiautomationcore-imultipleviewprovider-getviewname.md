# IMultipleViewProvider::GetViewName

## Description

Retrieves the name of a control-specific view.

## Parameters

### `viewId` [in]

Type: **int**

A view identifier.

### `pRetVal` [out, retval]

Type: **BSTR***

Receives a localized name for the view.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

View identifiers can be retrieved by using [IMultipleViewProvider::GetSupportedViews](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-imultipleviewprovider-getsupportedviews).

The collection of view identifiers must be identical for all instances of a control.

View names must be suitable for use in text-to-speech, Braille, and other accessible applications.

## See also

[IMultipleViewProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-imultipleviewprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)