# EXPLORER_BROWSER_OPTIONS enumeration

## Description

These flags are used with [IExplorerBrowser::GetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-getoptions) and [IExplorerBrowser::SetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-setoptions).

## Constants

### `EBO_NONE:0`

No options.

### `EBO_NAVIGATEONCE:0x1`

Do not navigate further than the initial navigation.

### `EBO_SHOWFRAMES:0x2`

Use the following standard panes: Commands Module pane, Navigation pane, Details pane, and Preview pane. An implementer of [IExplorerPaneVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerpanevisibility) can modify the components of the Commands Module that are shown. For more information see, [IExplorerPaneVisibility::GetPaneState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerpanevisibility-getpanestate). If EBO_SHOWFRAMES is not set, Explorer browser uses a single view object.

### `EBO_ALWAYSNAVIGATE:0x4`

Always navigate, even if you are attempting to navigate to the current folder.

### `EBO_NOTRAVELLOG:0x8`

Do not update the travel log.

### `EBO_NOWRAPPERWINDOW:0x10`

Do not use a wrapper window. This flag is used with legacy clients that need the browser parented directly on themselves.

### `EBO_HTMLSHAREPOINTVIEW:0x20`

Show WebView for sharepoint sites.

### `EBO_NOBORDER:0x40`

**Introduced in Windows Vista**. Do not draw a border around the browser window.

### `EBO_NOPERSISTVIEWSTATE:0x80`

**Introduced in Windows Vista**. Do not persist the view state.