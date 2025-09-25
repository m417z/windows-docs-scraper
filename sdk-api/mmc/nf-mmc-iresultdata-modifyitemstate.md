# IResultData::ModifyItemState

## Description

The **IResultData::ModifyItemState** method enables the snap-in to modify the state of an item.

## Parameters

### `nIndex` [in]

A value that specifies the index of the item whose state is to be modified. This parameter is used only when the itemID parameter is zero. When applied to virtual lists, you must use nIndex and set itemID to zero.

### `itemID` [in]

Unique identifier of the item whose state is to be modified. When applied to virtual lists, set itemID = 0.

### `uAdd` [in]

A value that specifies which Windows list-view state flags can be set. When applied to virtual lists, only focus and select states can be modified. This value can be any valid combination of the following:

#### LVIS_CUT

The item is marked for a cut-and-paste operation.

#### LVIS_DROPHILITED

The item is highlighted as a drag-and-drop target.

#### LVIS_FOCUSED

The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item can be selected, only one item can have the focus.

#### LVIS_SELECTED

The item is selected. The appearance of a selected item depends on whether it has the focus and on the system colors used for selection.

### `uRemove` [in]

A value that specifies the list-view item state flags that can be removed. This value can be any valid combination of the preceding Win32 LVIS_* flags shown for the uAdd parameter.

## Return value

This method can return one of these values.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)