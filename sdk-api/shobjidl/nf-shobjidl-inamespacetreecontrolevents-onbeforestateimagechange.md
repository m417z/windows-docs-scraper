# INameSpaceTreeControlEvents::OnBeforeStateImageChange

## Description

Called before the state icon of the given [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) is changed.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) in which the state image is changing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method returns S_OK, the client has processed the event and no further action is required of the namespace control. Otherwise the event will need to be processed, in this case the default action is to go to the next image in the list.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)