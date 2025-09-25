# IMEAPPLETCFG structure

## Description

Used to specify and set applet configuration in [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad).

## Members

### `dwConfig`

Combination of **IPACFG_*** flags.

| Value | Meaning |
| --- | --- |
| **IPACFG_NONE** |  |
| **IPACFG_PROPERTY** | The applet has a property Dialog. If this flag is set, [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) calls [IImePadApplet::Notify](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepadapplet-notify) with **IMEPN_CFG**. |
| **IPACFG_HELP** | The applet has help. If this flag is set, [IImePad](https://learn.microsoft.com/windows/desktop/api/imepad/nn-imepad-iimepad) calls [IImePadApplet::Notify](https://learn.microsoft.com/windows/desktop/api/imepad/nf-imepad-iimepadapplet-notify) with **IMEPN_HELP**. |
| **IPACFG_TITLE** | **wchTitle** is set. |
| **IPACFG_TITLEFONTFACE** | **wchTitleFontFace** and **dwCharSet** are set. |
| **IPACFG_CATEGORY** | **iCategory** is set. |
| **IPACFG_LANG** | **LangID** is set. |

### `wchTitle`

The applet's title, in Unicode.

### `wchTitleFontFace`

The applet title's FontFace name.

### `dwCharSet`

The applet font's character set.

### `iCategory`

Not used.

### `hIcon`

The icon handle for the ImePad applet's menu.

### `langID`

The applet's language ID.

### `dummy`

Not used.

### `lReserved1`

Reserved.

## See also

[IImePadApplet::GetAppletCfg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh851787(v=vs.85))