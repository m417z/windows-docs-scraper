# IBrowserService2::OnNotify

## Description

Deprecated. Calls the derived class from the base class on receipt of a [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message. The derived class handles the message.

## Parameters

### `pnm` [in, out]

Type: **tagNMHDR***

A pointer to a [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that receives the initialization parameters passed to the window procedure (WinProc) of the class.

## Return value

Type: **LRESULT**

The return value specifies the result of the notification processing; it depends on the notification sent.