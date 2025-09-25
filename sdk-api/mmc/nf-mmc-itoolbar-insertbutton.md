# IToolbar::InsertButton

## Description

The **IToolbar::InsertButton** method enables a snap-in to add a single button to the toolbar. The button being added is placed at the end of the toolbar.

## Parameters

### `nIndex` [in]

An internal index at which the button will be inserted. The button is always placed at the end of the toolbar; the internal index is required if the button is to be deleted (by means of
[IToolbar::DeleteButton](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-itoolbar-deletebutton)).

### `lpButton` [in]

A pointer to the
[MMCBUTTON](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmcbutton) structure that defines the button to be inserted.

## Return value

This method can return one of these values.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)