# INameSpaceTreeControlEvents::OnKeyboardInput

## Description

Called when the user presses a key on the keyboard.

## Parameters

### `uMsg` [in]

Type: **UINT**

The message value.

### `wParam` [in]

Type: **WPARAM**

Specifies the WParam parameters of the message.

### `lParam` [in]

Type: **LPARAM**

Specifies the LParam parameters of the message.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method receives its message directly from WndProc. When this returns S_OK, the message was not consumed and the namespace tree control is allowed to process the message. Otherwise this message was handled, with no further action required.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)