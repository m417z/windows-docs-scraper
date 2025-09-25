# IExplorerBrowser::SetOptions

## Description

Sets the current browser options.

## Parameters

### `dwFlag` [in]

Type: **[EXPLORER_BROWSER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options)**

One or more [EXPLORER_BROWSER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options) flags to be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This action overrides any previous options.

Frames are disabled by default. To enable frames and get the default set of panes, set the [EBO_SHOWFRAMES](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options) flag using the **SetOptions** method. The default panes, listed as [IExplorerPaneVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerpanevisibility) constants, are these:

* EP_NavPane
* EP_Commands
* EP_Commands_Organize
* EP_Commands_View
* EP_DetailsPane
* EP_PreviewPane
* EP_QueryPane
* EP_AdvQueryPane
* EP_StatusBar
* EP_Ribbon

See [IExplorerPaneVisibility::GetPaneState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerpanevisibility-getpanestate) for more information.