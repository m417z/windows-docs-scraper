# IBrowserService2::WndProcBS

## Description

Deprecated. Allows a derived class to call the **WinProc** function of the base class.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window receiving the message.

### `uMsg` [in]

Type: **UINT**

The message received by the window.

### `wParam` [in, out]

Type: **WPARAM**

Additional message information specific to the message type.

### `lParam` [in, out]

Type: **LPARAM**

Additional message information specific to the message type.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing; it depends on the message sent.