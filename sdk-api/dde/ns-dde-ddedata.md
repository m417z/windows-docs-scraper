# DDEDATA structure

## Description

Contains the data, and information about the data, sent as part of a [WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data) message.

## Members

### `unused`

Type: **unsigned short**

Unused.

### `fResponse`

Type: **unsigned short**

Indicates whether the data was sent in response to a [WM_DDE_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-request) message or a [WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise) message. If this value is nonzero, the data was sent in response to a **WM_DDE_REQUEST** message.

### `fRelease`

Type: **unsigned short**

Indicates whether the application receiving the [WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke) message should free the data. If this value is nonzero, the application should free the data.

### `reserved`

Type: **unsigned short**

Reserved.

### `fAckReq`

Type: **BYTE**

Indicates whether the application receiving the [WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data) message should acknowledge receipt of the data by sending a [WM_DDE_ACK](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-ack) message. If this value is nonzero, the application should send the acknowledgment.

### `usFlags`

### `cfFormat`

Type: **short**

The format of the data. The format should be a standard or registered clipboard format. The following standard clipboard formats can be used:

#### CF_BITMAP (2)

#### CF_DIB (8)

#### CF_DIF (5)

#### CF_ENHMETAFILE (14)

#### CF_METAFILEPICT (3)

#### CF_OEMTEXT (7)

#### CF_PALETTE (9)

#### CF_PENDATA (10)

#### CF_RIFF (11)

#### CF_SYLK (4)

#### CF_TEXT (1)

#### CF_TIFF (6)

#### CF_WAVE (12)

#### CF_UNICODETEXT (13)

### `Value`

Type: **BYTE[1]**

Contains the data. The length and type of data depend on the **cfFormat** member.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

**Reference**

[WM_DDE_ACK](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-ack)

[WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise)

[WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data)

[WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke)

[WM_DDE_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-request)