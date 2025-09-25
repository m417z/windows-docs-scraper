# MCIWndSendString macro

## Syntax

```cpp
LONG MCIWndSendString(
     hwnd,
     sz
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSendString** macro sends an MCI command in string form to the device associated with the MCIWnd window. You can use this macro or explicitly send the [MCIWNDM_SENDSTRING](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-sendstring) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `sz`

String command to send to the MCI device.

## Remarks

The message handler for **MCIWndSendString** (and **MCIWNDM_SENDSTRING**) appends a device alias to the MCI command you send to the device. Therefore, you should not use any alias in an MCI command that you issue with **MCIWndSendString**.

To get the return string, which contains the result of the command, use the [MCIWndReturnString](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndreturnstring) macro.

## See also

[Multimedia Command Strings](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-command-strings)