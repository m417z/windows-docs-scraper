# IShellBrowser::InsertMenusSB

## Description

Allows the container to insert its menu groups into the composite menu that is displayed when an extended namespace is being viewed or used.

## Parameters

### `hmenuShared`

Type: **HMENU**

A handle to an empty menu.

### `lpMenuWidths`

Type: **LPOLEMENUGROUPWIDTHS**

The address of an [OLEMENUGROUPWIDTHS](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-olemenugroupwidths) array of six **LONG** values. The container fills in elements 0, 2, and 4 to reflect the number of menu elements it provided in the File, View, and Window menu groups.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

This method is similar to the [IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus) method. Windows Explorer puts **File** and **Edit** drop-down menus in the File menu group, **View** and **Tools** menus in the Container menu group, and a **Help** menu in the Window menu group. Each drop-down menu will have a unique identifier, FCIDM_MENU_FILE/EDIT/VIEW/TOOLS/HELP. The view is allowed to insert menu items into those submenus by their identifiers, which is different from OLE's in-place activation mechanism. The command identifiers for menus that the view inserts into either Windows Explorer's submenus or its own submenus must be between **FCIDM_SHVIEWFIRST** and **FCIDM_SHVIEWLAST**.

### Notes to Calling Applications

This method is called by namespace extensions when they are first being activated so they can insert their menus into the frame-level user interface.

The object application asks the container to add its menus to the menu specified in the *hmenuShared* parameter and to set the group counts in the [OLEMENUGROUPWIDTHS](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-olemenugroupwidths) array pointed to by the *lpMenuWidths* parameter. The object application then adds its own menus and counts. Objects can call the [IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus) method as many times as necessary to build up the composite menus. The container should use the initial menu handle associated with the composite menu for all items in the drop-down menus.

### Notes to Implementers

For [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) implementations, the menu identifiers must be in the range of **FCIDM_BROWSERFIRST** to **FCIDM_BROWSERLAST**.