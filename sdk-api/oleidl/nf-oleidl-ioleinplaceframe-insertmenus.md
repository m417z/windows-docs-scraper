# IOleInPlaceFrame::InsertMenus

## Description

Enables the container to insert menu groups into the composite menu to be used during the in-place session.

## Parameters

### `hmenuShared` [in]

A handle to an empty menu.

### `lpMenuWidths` [in, out]

A pointer to an [OLEMENUGROUPWIDTHS](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-olemenugroupwidths) array with six elements. The container fills in elements 0, 2, and 4 to reflect the number of menu elements it provided in the **File**, **View**, and **Window** menu groups.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

This method is called by object applications when they are first being activated. They call it to insert their menus into the frame-level user interface.

The object application asks the container to add its menus to the menu specified in *hmenuShared* and to set the group counts in the [OLEMENUGROUPWIDTHS](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-olemenugroupwidths) array pointed to by *lpMenuWidths*. The object application then adds its own menus and counts. Objects can call **IOleInPlaceFrame::InsertMenus** as many times as necessary to build up the composite menus. The container should use the initial menu handle associated with the composite menu for all menu items in the drop-down menus.

## See also

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)