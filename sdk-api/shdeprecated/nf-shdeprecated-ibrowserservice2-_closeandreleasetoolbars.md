# IBrowserService2::_CloseAndReleaseToolbars

## Description

Deprecated. Requests the closing of the browser toolbars hosted by the derived class.

## Parameters

### `fClose` [in]

Type: **BOOL**

**TRUE** to close the toolbar through [IDockingWindow::CloseDW](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idockingwindow-closedw); **FALSE** to release the toolbar.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.