# IWCContextMenuCallback::AddExtensionMenuItem

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Adds a menu item to a
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) context menu.

## Parameters

### `lpszName` [in]

Pointer to a null-terminated Unicode string containing the name of the item to be added to the menu. Although
declared as a **BSTR**, this parameter is implemented as an
**LPWSTR**.

### `lpszStatusBarText` [in]

Pointer to text to display on the status bar when the new item is selected. Although declared as a
**BSTR**, this parameter is implemented as an
**LPWSTR**.

### `nCommandID` [in]

Identifier for the command to be invoked when the menu item is selected. The
*nCommandID* parameter must not be set to –1.

### `nSubmenuCommandID` [in]

Identifier for a submenu. Submenus are not supported, and the *nSubmenuCommandID*
parameter must be zero.

### `uFlags` [in]

Bitmask of flags that describes the new menu item. One or more of the following values may be set.

#### MF_CHECKED (8)

Acts as a toggle with **MF_UNCHECKED** to place the default check mark next to the
item.

#### MF_UNCHECKED (0)

Acts as a toggle with **MF_CHECKED** to remove a check mark placed next to the
item.

#### MF_DISABLED (2)

Disables the menu item so it cannot be selected but does not dim it.

#### MF_ENABLED (0)

Enables the menu item so it can be selected and restores it from its dimmed state if the item was
previously dimmed.

#### MF_GRAYED (1)

Disables the menu item so it cannot be selected and dims it.

#### MF_MENUBARBREAK (32 (0x20))

Places the item in a new column. The new column is separated from the old column by a vertical dividing
line.

#### MF_MENUBREAK (64 (0x40))

Places the item in a new column. No dividing line is placed between the columns.

#### MF_SEPARATOR (2048 (0x800))

Draws a horizontal dividing line. This line cannot be dimmed, disabled, or highlighted. The
*lpszName* and *lpszStatusBarText* parameters are
ignored.

#### MF_STRING (0)

Specifies that the menu item is a character string. The *lpszName* parameter
contains a pointer to a **NULL**-terminated Unicode string. This is the default
interpretation.

## Return value

If **AddExtensionMenuItem**
is not successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | The *uFlags* parameter was set to either **MF_OWNERDRAW** or **MF_POPUP**. |
| **E_OUTOFMEMORY**<br><br>0x8007000e | There was an error allocating the menu item. |

## Remarks

The **AddExtensionMenuItem**
method adds items at the top of the context menu and follows them by a separator. The command identified by
*nCommandID* is passed in the *nCommandID* parameter to the
[IWEInvokeCommand::InvokeCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweinvokecommand-invokecommand) method
when the user selects this menu item.

Note that the **MF_OWNERDRAW** and **MF_POPUP** flags are not
supported specifically for the *uFlags* parameter.

[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extensions call
**AddExtensionMenuItem** from
their
[IWEExtendContextMenu::AddContextMenuItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendcontextmenu-addcontextmenuitems)
method.

## See also

[IWCContextMenuCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwccontextmenucallback)

[IWEExtendContextMenu::AddContextMenuItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendcontextmenu-addcontextmenuitems)

[IWEInvokeCommand::InvokeCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweinvokecommand-invokecommand)