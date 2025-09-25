# DDEACK structure

## Description

Contains status flags that a DDE application passes to its partner as part of the [WM_DDE_ACK](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-ack) message. The flags provide details about the application's response to the messages [WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data), [WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke), [WM_DDE_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-execute), [WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise), [WM_DDE_UNADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-unadvise), and [WM_DDE_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-request).

## Members

### `bAppReturnCode`

Type: **unsigned short**

An application-defined return code.

### `reserved`

Type: **unsigned short**

Reserved.

### `fBusy`

Type: **unsigned short**

Indicates whether the application was busy and unable to respond to the partner's message at the time the message was received. A nonzero value indicates the partner was busy and unable to respond. The **fBusy** member is defined only when the **fAck** member is zero.

### `fAck`

Type: **unsigned short**

Indicates whether the application accepted the message from its partner. A nonzero value indicates the partner accepted the message.

### `usFlags`

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

**Reference**

[WM_DDE_ACK](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-ack)

[WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise)

[WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data)

[WM_DDE_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-execute)

[WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke)

[WM_DDE_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-request)

[WM_DDE_UNADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-unadvise)