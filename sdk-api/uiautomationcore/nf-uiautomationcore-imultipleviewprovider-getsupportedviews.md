# IMultipleViewProvider::GetSupportedViews

## Description

Retrieves a collection of control-specific view identifiers.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a collection of control-specific integer values that identify the views available for a UI Automation element.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An empty array is returned by UIAutoCore.dll if the provider does not supply any view identifiers.

The collection of view identifiers must be identical for all instances of a control.

View identifier values can be passed to [IMultipleViewProvider::GetViewName](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-imultipleviewprovider-getviewname).

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IMultipleViewProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-imultipleviewprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)