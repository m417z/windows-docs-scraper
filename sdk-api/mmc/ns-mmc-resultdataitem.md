# RESULTDATAITEM structure

## Description

The
**RESULTDATAITEM** structure specifies or receives the attributes of result items in the result pane of the snap-in.

## Members

### `mask`

A set of flags that specifies attributes of this data structure, or an operation that uses this structure.

The following flags specify the members of the
**RESULTDATAITEM** structure that contain valid data, or need to be filled in with data. One or more of the flags can be set.

#### RDI_STR (0x0002)

The **str** member is valid or must be filled in.

#### RDI_IMAGE (0x0004)

The **nImage** member is valid or must be filled in.

#### RDI_STATE (0x0008)

The **nState** member is valid or must be filled in.

#### RDI_PARAM (0x0010)

The **lParam** member is valid or must be filled in.

#### RDI_INDEX (0x0020)

The **nIndex** member is valid or must be filled in.

#### RDI_INDENT (0x0040)

The **iIndent** member is valid or must be filled in.

### `bScopeItem`

**TRUE** if the **lParam** member refers to a scope item. **FALSE** if the **lParam** member refers to a result item.

### `itemID`

A value that specifies a console-supplied unique item identifier for the result item. This value is used to identify an item in the result pane of calls to some
[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata) interface methods.

After the snap-in successfully inserts an item in the scope pane (by using [IResultData::InsertItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-insertitem)), the **itemID** member of the
**RESULTDATAITEM** structure contains the **HRESULTITEM** handle of the newly inserted item. This handle is the unique identifier for the result item.

The snap-in should store this value to manipulate (later) the inserted item by calling methods such as [IResultData::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-getitem). If this value is not stored, it can be looked up by using [IResultData::FindItemByLParam](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-finditembylparam).

### `nIndex`

A value that specifies the zero-based index of the item to which this structure refers.

### `nCol`

A value that specifies the column on which an operation is to be performed. If the operation is to be performed on an item and not a column, the value is zero (0).

### `str`

A pointer to a null-terminated string that contains the item text if the structure specifies the **RDI_STR** item attribute. If this member is the **MMC_CALLBACK** value, the item is a callback item.

Be aware that the snap-in can use **MMC_TEXTCALLBACK** instead of **MMC_CALLBACK**. The **MMC_TEXTCALLBACK** value is a type-correct (no casting necessary) version of **MMC_CALLBACK**.

**MMC_TEXTCALLBACK** is introduced in MMC version 1.2.

### `nImage`

Virtual image index of the list view item's icon in the large and small icon image lists. Be aware that the virtual image index is mapped internally to the actual index. This member can also be specified as a callback item: **MMC_CALLBACK** or **MMC_IMAGECALLBACK**. The **MMC_IMAGECALLBACK** value is a type-correct (no casting necessary) version of **MMC_CALLBACK**.

**MMC_IMAGECALLBACK** is introduced in MMC version 1.2.

### `nState`

A value that specifies the state mask for the item. It can be one of the following values.

#### LVIS_CUT

The item is marked for a cut-and-paste operation.

#### LVIS_DROPHILITED

The item is highlighted as a drag-and-drop target.

#### LVIS_FOCUSED

The item has the focus, so it is surrounded by a standard focus rectangle. More than one item can be selected, but only one item can have the focus.

#### LVIS_SELECTED

The item is selected. The appearance of a selected item depends on whether it has the focus, and on the system colors used for the selection.

**Note** To use the **LVIS_*** constants, include CommCtrl.h in your source file.

### `lParam`

A value that specifies a user-supplied 32-bit value to associate with the item. This item, also called a cookie, is the value that is passed as the first parameter to
[IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject).

### `iIndent`

Reserved.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)