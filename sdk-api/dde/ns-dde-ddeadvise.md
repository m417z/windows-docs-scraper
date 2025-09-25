# DDEADVISE structure

## Description

Contains flags that specify how a DDE server application should send data to a client application during an advise loop. A client passes a handle to a **DDEADVISE** structure to a server as part of a [WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise) message.

## Members

### `reserved`

Type: **unsigned short**

Reserved.

### `fDeferUpd`

Type: **unsigned short**

Indicates whether the server should defer sending updated data to the client. If this value is nonzero, the server should send a [WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data) message with a **NULL** data handle whenever the data item changes. In response, the client can post a [WM_DDE_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-request) message to the server to get a handle to the updated data.

### `fAckReq`

Type: **short**

Indicates whether the server should set the **fAckReq** flag in the [WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data) messages it posts to the client. If this value is nonzero, the server should set the **fAckReq** bit.

### `usFlags`

### `cfFormat`

Type: **short**

The client application's preferred data format. The format must be a standard or registered clipboard format. The following standard clipboard formats can be used:

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

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

**Reference**

[WM_DDE_ADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-advise)

[WM_DDE_DATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-data)

[WM_DDE_UNADVISE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-unadvise)