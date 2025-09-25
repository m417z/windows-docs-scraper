# SCOPEDATAITEM structure

## Description

The
**SCOPEDATAITEM** structure specifies items to be inserted into the scope pane.

## Members

### `mask`

A value that specifies an array of flags that indicate which members of the structure contain valid data. When this structure is used in the
[IConsoleNameSpace2::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getitem) method, it indicates the item attributes to be retrieved. This member can be one of the following values.

#### SDI_STR (0x00002)

The **displayname** member of the structure is valid. **SDI_STR** is supported only when you specify a value for the **displayname** member. MMC does not store the value for the **displayname** member, and it cannot be retrieved by calling the [IConsoleNamespace2::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getitem) method.

#### SDI_IMAGE (0x00004)

The **nImage** member of the structure is valid or must be filled in.

#### SDI_OPENIMAGE (0x00008)

The **nOpenImage** member of the structure is valid or must be filled in.

#### SDI_STATE (0x00010)

The **nState** member of the structure is valid or must be filled in.

#### SDI_PARAM (0x00020)

The **lParam** member of the structure is valid or must be filled in.

#### SDI_CHILDREN (0x00040)

The **cChildren** member of the structure is valid or must be filled in.

#### SDI_PARENT (0x00000000)

Use only when inserting items into the scope pane. The **relativeID** member of the structure is the **HSCOPEITEM** of the parent. The item is inserted as the last child of the item referred to by **relativeID**.

#### SDI_PREVIOUS (0x10000000)

Use only when inserting items into the scope pane. The **relativeID** member of the structure is the **HSCOPEITEM** of the previous sibling.

#### SDI_NEXT (0x20000000)

Use only when inserting items into the scope pane. The **relativeID** member of the structure is the **HSCOPEITEM** of the next sibling.

#### SDI_FIRST (0x08000000)

Use only when inserting items into the scope pane. The **relativeID** member of the structure is the **HSCOPEITEM** of the parent. The item is inserted as the first child of the item referred to by **relativeID**.

### `displayname`

**MMC_CALLBACK** value or a pointer to a null-terminated string, which depends on how the structure is being used.

* When an item is inserted by using
  [IConsoleNameSpace2::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-insertitem), this member must be set to **MMC_CALLBACK**.
* When the name of an item inserted by the snap-in is changed by using
  [IConsoleNameSpace2::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-setitem), this member must be set to **MMC_CALLBACK**.
* When the name of the static node (an item that the console inserts) is changed, this member can be set to **MMC_CALLBACK**, or be a pointer to the null-terminated string that contains the item text.

Be aware that the snap-in can use **MMC_TEXTCALLBACK** instead of **MMC_CALLBACK**. The **MMC_TEXTCALLBACK** value is a type-correct (no casting necessary) version of **MMC_CALLBACK**.

**MMC_TEXTCALLBACK** is introduced in MMC version 1.2.

### `nImage`

Virtual image index in the image list when the item is in the nonselected state. Be aware that the virtual image index is mapped internally to the actual index. This member can also be specified as a callback item: **MMC_CALLBACK** or **MMC_IMAGECALLBACK**. The **MMC_IMAGECALLBACK** is a type-correct (no casting necessary) version of **MMC_CALLBACK**.

**MMC_IMAGECALLBACK** is introduced in MMC version 1.2.

### `nOpenImage`

Virtual image index in the image list when the item is in the selected state. Be aware that the virtual image index is mapped internally to the actual index. The item is like a folder in Microsoft Windows Explorer. The icon is for an open folder.

### `nState`

A value that specifies the state mask for the item. For [IConsoleNameSpace2::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getitem), this member returns **MMC_SCOPE_ITEM_STATE_EXPANDEDONCE** if the item has been expanded at least one time, or 0 (zero) if the item has not been expanded.

This member is ignored for [IConsoleNameSpace2::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-insertitem) and [IConsoleNameSpace2::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-setitem).

### `cChildren`

A value that specifies the number of enumerated items.

When a snap-in inserts a scope item, it should set the **cChildren** field to 0 (zero), and set the **SDI_CHILDREN** flag if both of the following conditions are met:

* The snap-in does not have any child items to add under the inserted item.
* The snap-in does not dynamically enable any namespace extension snap-ins for this item.

Otherwise, when inserting a scope item, the **cChildren** field should be set to 1 (one), or not set at all.

If conditions change at a later time, the snap-in can modify the **cChildren** field by using
[IConsoleNameSpace2::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-setitem).

If it will take a significant amount of time to determine the number of children, the snap-in should use a best guess at insertion time, and make the actual determination on another thread so the MMC user interface will not be locked out.
[IConsoleNameSpace2::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-setitem) can be used to correct the setting if necessary.

When MMC detects a scope item with a **cChildren** count of 0 (zero), it checks for namespace extensions that have been statically enabled for the item by the user or the
[IRequiredExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-irequiredextensions) interface. If none are enabled, the plus (+) sign is removed from the item.

After an item is expanded, the state of the plus sign is determined by the actual number of child items present.

### `lParam`

A value that specifies a user-supplied 32-bit value to associate with the item. This item, also called a cookie, is the value that is passed as the first parameter to
[IComponentData::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject).

### `relativeID`

A console-supplied unique item identifier. An item is inserted at a position relative to the item that this member specifies. The **mask** settings determine the relative position.

To determine how **relativeID** is interpreted, specify one of the following constants as the **mask** member.

#### SDI_PARENT

**relativeID** is the **HSCOPEITEM** of the parent. The item is inserted as the last child of the parent item. The value of **SDI_PARENT** indicates that it is a no-op, because by default, the parent item ID is **relativeID**.

#### SDI_PREVIOUS

**relativeID** is the **HSCOPEITEM** of the previous sibling.

#### SDI_NEXT

**relativeID** is the **HSCOPEITEM** of the next sibling.

#### SDI_FIRST

Same as **SDI_PARENT**, except the item is inserted as the first child.

### `ID`

A value that specifies a console-supplied unique identifier for the scope item. This value is used to identify an item in the scope pane of calls to some of the
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) and
[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2) interface methods.

After the snap-in successfully inserts an item into the scope pane (by using [IConsoleNameSpace2::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-insertitem)), the
**ID** member of the
**SCOPEDATAITEM** structure contains the **HSCOPEITEM** handle of the newly inserted item. This handle is the unique identifier for the scope item.

For a static node, MMC inserts an item into the scope pane of the snap-in. Then MMC passes the **HSCOPEITEM** of the static node to the snap-in as the *param* parameter in the [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification.

Be aware that snap-ins should store the **HSCOPEITEM** of each inserted item and use it later to manipulate the item by using the methods of the
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) and
[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2) interfaces.

## Remarks

It is not valid to insert an item as a sibling of the static node. If a snap-in sets the **relativeID** member to the **HSCOPEITEM** of the static node, sets the **SDI_PREVIOUS** or **SDI_NEXT** flags, and then calls [IConsoleNameSpace2::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-insertitem), MMC returns **E_INVALIDARG**.

## See also

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IComponentData::GetDisplayInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-getdisplayinfo)

[IConsoleNameSpace2::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getitem)

[IConsoleNameSpace2::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-insertitem)

[IConsoleNameSpace2::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-setitem)