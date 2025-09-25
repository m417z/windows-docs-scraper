# IShellBrowser::QueryActiveShellView

## Description

Retrieves the currently active (displayed) Shell view object.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)****

The address of the pointer to the currently active Shell view object.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

### Notes to Calling Applications

Because the [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) interface can host several Shell views simultaneously, this method provides an easy way to determine the active Shell view object.