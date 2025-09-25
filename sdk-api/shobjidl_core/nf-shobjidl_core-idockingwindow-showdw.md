# IDockingWindow::ShowDW

## Description

Instructs the docking window object to show or hide itself.

## Parameters

### `fShow`

Type: **BOOL**

**TRUE** if the docking window object should show its window. **FALSE** if the docking window object should hide its window and return its border space by calling [SetBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-setborderspacedw) with zero values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)

[IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow)

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)