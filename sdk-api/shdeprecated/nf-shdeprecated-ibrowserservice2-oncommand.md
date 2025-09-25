# IBrowserService2::OnCommand

## Description

Deprecated. Calls the derived class from the base class on receipt of a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message. The derived class handles the message.

## Parameters

### `wParam` [in]

Type: **WPARAM**

Additional information taken from the [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message. The high-order word specifies the notification code if the message is from a control. If the message is from an accelerator, this value is 1. If the message is from a menu, this value is zero.

The low-order word specifies the identifier of the menu item, control, or accelerator.

### `lParam` [in]

Type: **LPARAM**

Additional information taken from the [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message. Handle to the control sending the message if the message is from a control. Otherwise, this parameter is **NULL**.

## Return value

Type: **LRESULT**

The return value specifies the result of the command processing; it depends on the command sent.