# IExplorerBrowser::Initialize

## Description

Prepares the browser to be navigated.

## Parameters

### `hwndParent` [in]

Type: **HWND**

A handle to the owner window or control.

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) that contains the coordinates of the bounding rectangle that the browser will occupy. The coordinates are relative to *hwndParent*.

### `pfs` [in]

Type: **const [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings)***

A pointer to a [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure that determines how the folder will be displayed in the view. If this parameter is **NULL**, then you must call [IExplorerBrowser::SetFolderSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-setfoldersettings); otherwise, the default view settings for the folder are used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After calling the **Initialize** method, it is the responsibility of the caller to call the [Destroy](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-destroy) method to destroy the browser and free any memory and windowed resources associated with the browser.