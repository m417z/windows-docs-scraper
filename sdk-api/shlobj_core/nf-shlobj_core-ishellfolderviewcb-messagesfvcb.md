# IShellFolderViewCB::MessageSFVCB

## Description

Allows communication between the system folder view object and a system folder view callback object.

## Parameters

### `uMsg` [in]

Type: **UINT**

One of the following notifications.

| Notification | Usage |
| --- | --- |
| [SFVM_ADDPROPERTYPAGES](https://learn.microsoft.com/windows/desktop/shell/sfvm-addpropertypages) | Allows the callback object to provide a page to add to the **Properties** property sheet of the selected object. |
| [SFVM_BACKGROUNDENUM](https://learn.microsoft.com/windows/desktop/shell/sfvm-backgroundenum) | Allows the callback object to request that enumeration be done on a background thread. |
| [SFVM_BACKGROUNDENUMDONE](https://learn.microsoft.com/windows/desktop/shell/sfvm-backgroundenumdone) | Notifies the callback object that background enumeration is complete. |
| [SFVM_COLUMNCLICK](https://learn.microsoft.com/windows/desktop/shell/sfvm-columnclick) | Notifies the callback object that the user has clicked a column header to sort the list of objects in the folder view. |
| [SFVM_DEFITEMCOUNT](https://learn.microsoft.com/windows/desktop/shell/sfvm-defitemcount) | Allows the callback object to specify the number of items in the folder view. |
| [SFVM_DEFVIEWMODE](https://learn.microsoft.com/windows/desktop/shell/sfvm-defviewmode) | Allows the callback object to specify the view mode. |
| [SFVM_DIDDRAGDROP](https://learn.microsoft.com/windows/desktop/shell/sfvm-diddragdrop) | Notifies the callback function that a drag-and-drop operation has begun. |
| [SFVM_FSNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-fsnotify) | Notifies the callback object that an event has taken place that affects one of its items. |
| [SFVM_GETANIMATION](https://learn.microsoft.com/windows/desktop/shell/sfvm-getanimation) | Allows the callback object to specify that an animation be displayed while items are enumerated on a background thread. |
| [SFVM_GETBUTTONINFO](https://learn.microsoft.com/windows/desktop/shell/sfvm-getbuttoninfo) | Allows the callback object to add buttons to the toolbar. |
| [SFVM_GETBUTTONS](https://learn.microsoft.com/windows/desktop/shell/sfvm-getbuttons) | Allows the callback object to specify the buttons to be added to the toolbar. |
| [SFVM_GETDETAILSOF](https://learn.microsoft.com/windows/desktop/shell/sfvm-getdetailsof) | Allows the callback object to provide the details for an item in a Shell folder. Use only if a call to [GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsof) fails and there is no [GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishelldetails-getdetailsof) method available to call. |
| [SFVM_GETHELPTEXT](https://learn.microsoft.com/windows/desktop/shell/sfvm-gethelptext) | Allows the callback object to specify a help text string for menu items or toolbar buttons. |
| [SFVM_GETHELPTOPIC](https://learn.microsoft.com/windows/desktop/shell/sfvm-gethelptopic) | Allows the callback object to specify a Help file and topic. |
| [SFVM_GETNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-getnotify) | Specifies which events will generate an [SFVM_FSNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-fsnotify) message for a given item. |
| [SFVM_GETPANE](https://learn.microsoft.com/windows/desktop/shell/sfvm-getpane) | Allows the callback object to provide the status bar pane in which to display the Internet zone information. |
| [SFVM_GETSORTDEFAULTS](https://learn.microsoft.com/windows/desktop/shell/sfvm-getsortdefaults) | Allows the callback object to specify default sorting parameters. |
| [SFVM_GETTOOLTIPTEXT](https://learn.microsoft.com/windows/desktop/shell/sfvm-gettooltiptext) | Allows the callback object to specify a [tooltip](https://learn.microsoft.com/windows/desktop/Controls/tooltip-controls) text string for menu items or toolbar buttons. |
| [SFVM_GETZONE](https://learn.microsoft.com/windows/desktop/shell/sfvm-getzone) | Allows the callback object to provide Internet zone information. |
| [SFVM_INITMENUPOPUP](https://learn.microsoft.com/windows/desktop/shell/sfvm-initmenupopup) | Allows the callback object to modify an item's context menu. |
| [SFVM_INVOKECOMMAND](https://learn.microsoft.com/windows/desktop/shell/sfvm-invokecommand) | Notifies the callback object that one of its toolbar or menu commands has been invoked. |
| [SFVM_MERGEMENU](https://learn.microsoft.com/windows/desktop/shell/sfvm-mergemenu) | Allows the callback object to merge menu items into the Windows Explorer menus. |
| [SFVM_QUERYFSNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-queryfsnotify) | Allows the callback object to register a folder so that changes to that folder's view will generate notifications. |
| [SFVM_SETISFV](https://learn.microsoft.com/windows/desktop/shell/sfvm-setisfv) | Notifies the callback object of the container site. This is used only when [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) is not supported and [SHCreateShellFolderViewEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderviewex) is used. |
| [SFVM_SIZE](https://learn.microsoft.com/windows/desktop/shell/sfvm-size) | Notifies the callback object that the folder view has been resized. |
| [SFVM_THISIDLIST](https://learn.microsoft.com/windows/desktop/shell/sfvm-thisidlist) | Allows the callback object to specify the view's PIDL. This is used only when [SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistidlist-setidlist) and [IPersistFolder2::GetCurFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder2-getcurfolder) have failed. |
| [SFVM_UNMERGEMENU](https://learn.microsoft.com/windows/desktop/shell/sfvm-unmergemenu) | Notifies the callback object that a menu is being removed. |
| [SFVM_UPDATESTATUSBAR](https://learn.microsoft.com/windows/desktop/shell/sfvm-updatestatusbar) | Allows the callback object to request that the status bar be updated. |
| [SFVM_WINDOWCREATED](https://learn.microsoft.com/windows/desktop/shell/sfvm-windowcreated) | Notifies the callback object that the folder view window is being created. |

### `wParam`

Type: **WPARAM**

Additional information. See the individual notification pages for specific requirements.

### `lParam`

Type: **LPARAM**

Additional information. See the individual notification pages for specific requirements.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The notification has been handled. |
| **E_NOTIMPL** | The message has not been handled and the system folder view object should perform default processing. |