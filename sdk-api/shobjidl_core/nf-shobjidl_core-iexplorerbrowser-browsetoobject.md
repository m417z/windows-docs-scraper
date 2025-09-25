# IExplorerBrowser::BrowseToObject

## Description

Browses to an object.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an object to browse to. If the object cannot be browsed, an error value is returned.

### `uFlags` [in]

Type: **UINT**

A flag that specifies the category of the *pidl*. This affects how navigation is accomplished. Must be the value zero, or a bitwise combination of the following values.

#### SBSP_ABSOLUTE

An absolute PIDL, relative to the desktop.

#### SBSP_RELATIVE

A relative PIDL, relative to the current folder.

#### SBSP_PARENT

Browse the parent folder, ignore the PIDL.

#### SBSP_NAVIGATEBACK

Navigate back, ignore the PIDL.

#### SBSP_NAVIGATEFORWARD

Navigate forward, ignore the PIDL.

#### SBSP_KEEPWORDWHEELTEXT

**Windows Vista and later**. This flag indicates that any search text entered by a WordWheel (the Search box in Windows Explorer) should be preserved during this navigation, so that items at the new location are filtered in the same way they were filtered at the previous location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*uFlags* may be any of the [EXPLORER_BROWSER_FILL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-explorer_browser_fill_flags) or any of the flags defined in [BrowseObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-browseobject)'s *wFlags* parameter, except for flags that indicate navigation.

This method calls [GetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistidlist-getidlist) and browses to the pidl returned. It operates in the same way as [IExplorerBrowser::BrowseToIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-browsetoidlist), except that *punk* cannot be **NULL**. Standard usage is to browse to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) or an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem). An error will be returned if the object passed in cannot be browsed through. An object that can be browsed through implements either [IPersistFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder2) or [IPersistIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistidlist).

The first navigation of [IExplorerBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowser) is synchronous. After that, all navigations are asynchronous. As a result, calls to **IExplorerBrowser::BrowseToObject** will succeed if you properly set up the pending navigation, but that does not guarantee the navigation will succeed. To be informed of success and failure, clients should implement [IExplorerBrowserEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorerbrowserevents) and respond appropriately in [OnNavigationComplete](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationcomplete) and [OnNavigationFailed](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowserevents-onnavigationfailed).