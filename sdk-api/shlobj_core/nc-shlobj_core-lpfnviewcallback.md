# LPFNVIEWCALLBACK callback function

## Description

[This interface is supported through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be unsupported in subsequent versions of Windows.]

Defines the prototype for the callback function used by the system folder view object. This function essentially duplicates the functionality of [IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb).

## Parameters

### `psvOuter` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the owning instance of [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview), if applicable. This parameter can be **NULL**.

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the instance of [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) the message applies to.

### `hwndMain` [in]

Type: **HWND**

The handle of the window that contains the view that receives the message.

### `uMsg`

Type: **UINT**

One of the following notifications.

#### SFVM_ADDPROPERTYPAGES

Allows the callback object to provide a page to add to the **Properties** property sheet of the selected object.

#### SFVM_BACKGROUNDENUM

Allows the callback object to request that enumeration be done on a background thread.

#### SFVM_BACKGROUNDENUMDONE

Notifies the callback object that background enumeration is complete.

#### SFVM_COLUMNCLICK

Notifies the callback object that the user has clicked a column header to sort the list of objects in the folder view.

#### SFVM_DEFITEMCOUNT

Allows the callback object to specify the number of items in the folder view.

#### SFVM_DEFVIEWMODE

Allows the callback object to specify the view mode.

#### SFVM_DIDDRAGDROP

Notifies the callback function that a drag-and-drop operation has begun.

#### SFVM_FSNOTIFY

Notifies the callback object that an event has taken place that affects one of its items.

#### SFVM_GETANIMATION

Allows the callback object to specify that an animation be displayed while items are enumerated on a background thread.

#### SFVM_GETBUTTONINFO

Allows the callback object to add buttons to the toolbar.

#### SFVM_GETBUTTONS

Allows the callback object to specify the buttons to be added to the toolbar.

#### SFVM_GETDETAILSOF

Allows the callback object to provide the details for an item in a Shell folder. Use only if a call to [IShellFolder2::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsof) fails and there is no [IShellDetails::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishelldetails-getdetailsof) method available to call.

#### SFVM_GETHELPTEXT

Allows the callback object to specify a help text string for menu items or toolbar buttons.

#### SFVM_GETHELPTOPIC

Allows the callback object to specify a Help file and topic.

#### SFVM_GETNOTIFY

Specifies which events will generate an [SFVM_FSNOTIFY](https://learn.microsoft.com/windows/desktop/shell/sfvm-fsnotify) message for a given item.

#### SFVM_GETPANE

Allows the callback object to provide the status bar pane in which to display the Internet zone information.

#### SFVM_GETSORTDEFAULTS

Allows the callback object to specify default sorting parameters.

#### SFVM_GETTOOLTIPTEXT

Allows the callback object to specify a [tooltip](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449606(v=vs.85)) text string for menu items or toolbar buttons.

#### SFVM_GETZONE

Allows the callback object to provide Internet zone information.

#### SFVM_INITMENUPOPUP

Allows the callback object to modify an item's context menu.

#### SFVM_INVOKECOMMAND

Notifies the callback object that one of its toolbar or menu commands has been invoked.

#### SFVM_MERGEMENU

Allows the callback object to merge menu items into the Windows Explorer menus.

#### SFVM_QUERYFSNOTIFY

Allows the callback object to register a folder so that changes to that folder's view will generate notifications.

#### SFVM_SETISFV

Notifies the callback object of the container site. This is used only when [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) is not supported and [SHCreateShellFolderViewEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderviewex) is used.

#### SFVM_SIZE

Notifies the callback object that the folder view has been resized.

#### SFVM_THISIDLIST

Allows the callback object to specify the view's PIDL. This is used only when [IPersistIDList::SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistidlist-setidlist) and [IPersistFolder2::GetCurFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder2-getcurfolder) have failed.

#### SFVM_UNMERGEMENU

Notifies the callback object that a menu is being removed.

#### SFVM_UPDATESTATUSBAR

Allows the callback object to request that the status bar be updated.

#### SFVM_WINDOWCREATED

Notifies the callback object that the folder view window is being created.

### `wParam`

Type: **WPARAM**

Additional information dependent on the value in *uMsg*. See the individual notification pages for specific requirements.

### `lParam`

Type: **LPARAM**

Additional information dependent on the value in *uMsg*. See the individual notification pages for specific requirements.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb)