# DDEPOKE structure

## Description

Contains the data, and information about the data, sent as part of a [WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke) message.

## Members

### `unused`

Type: **unsigned short**

Unused.

### `fRelease`

Type: **unsigned short**

Indicates whether the application receiving the [WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke) message should free the data. If this value is nonzero, the application should free the data.

### `fReserved`

Type: **unsigned short**

Reserved.

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

Contains the data. The length and type of data depend on the value of the
**cfFormat** member.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

**Reference**

[WM_DDE_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-poke)