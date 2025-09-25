# INameSpaceTreeControlEvents::OnItemClick

## Description

Called when the user clicks a button on the mouse.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that was clicked.

### `nstceHitTest` [in]

Type: **NSTCEHITTEST**

The location on the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that was clicked. One of the following values:

#### NSTCEHT_NOWHERE (0x0001)

The click missed the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMICON (0x0002)

The click was on the icon of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMLABEL (0x0004)

The click was on the label text of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMINDENT (0x0008)

The click was on the indented space on the leftmost side of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMBUTTON (0x0010)

The click was on the expando button of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMRIGHT (0x0020)

The click was on the rightmost side of the text of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMSTATEICON (0x0040)

The click was on the state icon of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEM (0x0046)

The click was on the item icon or the item label or the state icon of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

#### NSTCEHT_ONITEMTABBUTTON (0x1000)

The click was on the tab button of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `nstceClickType` [in]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)**

Indicates which button was clicked and the kind of click. One of the following values:

#### NSTCECT_LBUTTON (0x0001)

The left button was clicked.

#### NSTCECT_MBUTTON (0x0002)

The middle button was clicked.

#### NSTCECT_RBUTTON (0x0003)

The right button was clicked.

#### NSTCECT_BUTTON (0x0003)

A button was clicked.

#### NSTCECT_DBLCLICK (0x0004)

The click was a double click. If this value is present, it is added to one of the other values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method fails, the event is processed by both [INameSpaceTreeControl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrol) and TreeView. If it returns S_OK, then only **INameSpaceTreeControl** will process the event.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)