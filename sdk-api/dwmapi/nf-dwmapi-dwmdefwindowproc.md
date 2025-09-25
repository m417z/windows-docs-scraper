# DwmDefWindowProc function

## Description

Default window procedure for Desktop Window Manager (DWM) hit testing within the non-client area.

You also need to ensure that **DwmDefWindowProc** is called for the [WM_NCMOUSELEAVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncmouseleave) message. If **DwmDefWindowProc** is not called for the **WM_NCMOUSELEAVE** message, DWM does not remove the highlighting from the **Maximize**, **Minimize**, and **Close** buttons when the cursor leaves the window.

## Parameters

### `hWnd` [in]

A handle to the window procedure that received the message.

### `msg` [in]

The message.

### `wParam` [in]

Specifies additional message information. The content of this parameter depends on the value of the *msg* parameter.

### `lParam` [in]

Specifies additional message information. The content of this parameter depends on the value of the *msg* parameter.

### `plResult` [out]

A pointer to an **LRESULT** value that, when this method returns successfully,receives the result of the hit test.

## Return value

**TRUE** if **DwmDefWindowProc** handled the message; otherwise, **FALSE**.

## Remarks

When creating custom frames that include the standard caption buttons, [WM_NCHITTEST](https://learn.microsoft.com/windows/desktop/inputdev/wm-nchittest) and other non-client hit test messages should first be passed to the **DwmDefWindowProc** function. This enables the DWM to provide hit testing for the captions buttons. If **DwmDefWindowProc** does not handle the non-client hit test messages, further processing of these messages might be necessary.