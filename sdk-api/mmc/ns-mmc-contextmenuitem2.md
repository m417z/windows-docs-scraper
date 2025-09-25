# CONTEXTMENUITEM2 structure

## Description

The **CONTEXTMENUITEM2** structure is introduced in MMC
2.0.

The **CONTEXTMENUITEM2** structure is passed to the
[IContextMenuCallback2::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback2-additem) method or
the [IContextMenuProvider::AddItem](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814824(v=vs.85)) method
(inherited from [IContextMenuCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback)) to define a new
menu item, submenu, or insertion point. The context menu is built from the root down, with each new item going to
the end of the submenu or insertion point where the new item is inserted. The
**CONTEXTMENUITEM2** structure supersedes the
[CONTEXTMENUITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-contextmenuitem) structure (other than
the **strLanguageIndependentName** member, all of the members of
**CONTEXTMENUITEM2** are in
**CONTEXTMENUITEM**).

## Members

### `strName`

A pointer to a null-terminated string that contains the name of the menu item or of the submenu. This
member cannot be **NULL** except for a separator or insertion point.

### `strStatusBarText`

A pointer to a null-terminated string that contains the text that is displayed on the status bar when this
item is highlighted. This member can be **NULL**.

### `lCommandID`

A value that specifies the command identifier for menu items. If the menu item is added by
[IExtendContextMenu::AddMenuItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-addmenuitems) and
then selected, *lCommandID* is the command ID parameter that is passed back to
[IExtendContextMenu::Command](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-command). If this menu
item is added by the [IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)
interface and then selected, this is the command ID that is passed back to
*pISelected* by
[IContextMenuProvider::ShowContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenuprovider-showcontextmenu).
If this is an insertion point (**CCM_SPECIAL_INSERTION_POINT** is set in
*fSpecialFlags*) or a submenu (*MF_POPUP* is set in
*fFlags*), use *lCommandID* in subsequent calls as
*lInsertionPointID* (for more information, see the following list). Carefully read the
following discussion because specific bits in the new insertion point ID must be on and others must be off.

The following bits in the command ID require special handling for items that are not insertion points or
submenus.

#### CCM_COMMANDID_MASK_RESERVED (0xFFFF0000)

Items other than insertion points and submenus cannot be added when these bits are set.

The following bits in the insertion point ID require special handling for items that are insertion points
(*fSpecialFlags* and **CCM_SPECIAL_INSERTION_POINT**) or
submenus (*fFlags* and **MF_POPUP**).

#### CCM_INSERTIONPOINTID_MASK_SPECIAL (0xFFFF0000)

Special behavior. Snap-ins can use the other bits as required.

#### CCM_INSERTIONPOINTID_MASK_SHARED (0x80000000)

These insertion points and submenus are shared between the creator of the context menu, the primary
extension, and the third-party extension. Items added to a shared insertion point or submenu are available
to the creator of the context menu, the primary extension, and the third-party extension.

If this bit is not set, the
[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider) interface and each
extension can use the same ID. Each ID refers to a different insertion point or submenu.

Only the context menu creator and the primary snap-in can create shared insertion points or submenus.

#### CCM_INSERTIONPOINTID_MASK_CREATE_PRIMARY (0x40000000)

This bit must be set for shared insertion points and submenus created by the primary snap-in and not set
for those created by the context menu creator. This prevents ID conflicts between the two sources of shared
insertion points and submenus.

#### CCM_INSERTIONPOINTID_MASK_ADD_PRIMARY (0x20000000)

Allows the primary snap-in to add items to a shared insertion point or submenu.

#### CCM_INSERTIONPOINTID_MASK_ADD_3RDPARTY (0x10000000)

Allows extension snap-ins to add items to a shared insertion point or submenu.

#### CCM_INSERTIONPOINTID_MASK_RESERVED (0x0FFF0000)

Insertion points or submenus cannot be added with this value set.

### `lInsertionPointID`

A value that specifies where in the context menu the new item should be added. Snap-ins can only add items
to insertion points that are created by the menu creator or the primary snap-in. The following are the
insertion points created by MMC in the default context menus for items in the scope pane and list view result
pane:

#### 0 (zero)

An *lInsertionPointID* of 0 refers to the root menu for this context menu. The
value 0 can be used interchangeably with **CCM_INSERTIONPOINTID_ROOT_MENU**. Be aware
that only [IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider) is permitted to
add items directly to the root menu. Extensions can only add items to insertion points and submenus added to
the root menu by **IContextMenuProvider** or by MMC.

#### CCM_INSERTIONPOINTID_PRIMARY_TOP (0xA0000000)

The primary snap-in can use this insertion point to add items to the top of the main context menu.

#### CCM_INSERTIONPOINTID_PRIMARY_NEW (0xA0000001)

The primary snap-in can use this insertion point to add items to the top of the
**New** submenu. The **New** submenu is available in context
menus of the scope and result panes.

#### CCM_INSERTIONPOINTID_PRIMARY_TASK (0xA0000002)

The primary snap-in can use this insertion point to add items to the top of the All Tasks submenu. The
**All Tasks** submenu is available in context menus of the scope and result
panes.

#### CCM_INSERTIONPOINTID_PRIMARY_VIEW (0xA0000003)

The primary snap-in can use this insertion point to add items to the **View**
menu. If the user clicks the **View** drop-down menu on the toolbar, this insertion
point will be present, but the New and All Tasks insertion points will not appear.

#### CCM_INSERTIONPOINTID_3RDPARTY_NEW (0x90000001)

Extension snap-ins can use this insertion point to add items to the bottom of the
**New** submenu. The **New** submenu is only present for
context menus in the scope pane and not for context menus in the result pane.

#### CCM_INSERTIONPOINTID_3RDPARTY_TASK (0x90000002)

Extension snap-ins can use this insertion point to add items to the bottom of the
**All Tasks** submenu.

#### CCM_INSERTIONPOINTID_ROOT_MENU (0x80000000)

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider) can use this insertion
point to add items to the root menu.

Neither primary extensions nor third-party extensions can add items to the root menu except through
insertion points added by *IContextMenuProvider*.

### `fFlags`

A value that specifies one or more of the following style flags:

#### MF_POPUP

The created item is a submenu within the context menu. Menu items, insertion points, and other submenus
can be added to the created submenu; the new menu item, submenu, or insertion point should use the created
submenu's **lCommandID** member as the **lInsertionPointID**
member value.

#### MF_BITMAP

This flags is not supported;
[IContextMenuCallback2::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback2-additem) will
return **E_INVALIDARG**.

#### MF_OWNERDRAW

This flags is not supported;
[IContextMenuCallback2::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback2-additem) will
return **E_INVALIDARG**.

#### MF_SEPARATOR

Draws a horizontal separator line.

Only [IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider) can add menu items
with **MF_SEPARATOR** set.

The following flags function in the same way as they do in the Windows API.

#### MF_CHECKED

Selects the menu item.

#### MF_DISABLED

Disables the menu item so that it cannot be selected, but the flag does not dim the menu item.

#### MF_ENABLED

Enables the menu item so that it can be selected, restoring it from its dimmed state.

#### MF_GRAYED

Disables the menu item, dimming it so that it cannot be selected.

#### MF_MENUBARBREAK

Functions the same as the **MF_MENUBREAK** flag for a menu bar. For a drop-down
menu, submenu, or shortcut menu, a vertical line separates the new column from the old column.

#### MF_MENUBREAK

Places the item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or
shortcut menu) without separating columns.

#### MF_UNCHECKED

Does not select the item (default).

The following groups of flags cannot be used together:

* **MF_DISABLED**, **MF_ENABLED**, and
  **MF_GRAYED**
* **MF_MENUBARBREAK** and **MF_MENUBREAK**
* **MF_CHECKED** and **MF_UNCHECKED**

### `fSpecialFlags`

A value that specifies one or more of the following flags:

#### CCM_SPECIAL_SEPARATOR (0x0001)

Ignore all other parameters except *lInsertionPointID*. Add a separator to the end
of the menu or at the specified insertion point. Separators placed at the top or bottom of a menu or submenu
will not be displayed. Separators with no menu items between them will be collapsed into a single
separator.

Only [IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider) can add separators,
special or otherwise.

#### CCM_SPECIAL_SUBMENU (0x0002)

If this submenu is empty, it appears dimmed; this is only valid for **MF_POPUP**
items.

#### CCM_SPECIAL_DEFAULT_ITEM (0x0004)

This is the default menu item. If more than one menu item specifies this flag, the last item in each
submenu takes precedence.

#### CCM_SPECIAL_INSERTION_POINT (0x0008)

Ignore all other parameters except *lCommandID* and
*lInsertionPointID*. This flag creates a new insertion point at the end of the
insertion point or submenu identified by **lInsertionPointID**. New menu items,
submenus, or insertion points can be added to the created insertion point; the new menu item, submenu, or
insertion point should use the created insertion point's **lCommandID** member as the
**lInsertionPointID** member value.

#### CCM_SPECIAL_TESTONLY = 0x0010

Validate the item parameters, but do not add the menu item. Returns a result code that indicates whether
an Add operation would have been successful.

### `strLanguageIndependentName`

The language-independent name of the menu item. Retrieve this value in
[MMC 2.0 Automation Object Model](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-2-0-automation-object-model)
applications by getting the
[MenuItem.LanguageIndependentName](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/menuitem-languageindependentname)
property. The **strLanguageIndependentName** member cannot be
**NULL** or an empty string unless a separator or insertion point is added; otherwise,
the [IContextMenuCallback::AddItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontextmenucallback-additem) method
will fail with **E_INVALIDARG** as the return value.

## See also

[IContextMenuCallback2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenucallback2)

[IContextMenuProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontextmenuprovider)

[IExtendContextMenu](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendcontextmenu)

[Working with Context Menus](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/working-with-context-menus)