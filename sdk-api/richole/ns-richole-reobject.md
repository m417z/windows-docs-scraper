# REOBJECT structure

## Description

Contains information about an OLE or image object in a rich edit control.

## Members

### `cbStruct`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Structure size, in bytes.

### `cp`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character position of the object.

### `clsid`

Type: **CLSID**

Class identifier of the object.

### `poleobj`

Type: **LPOLEOBJECT**

An instance of the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface for the object.

### `pstg`

Type: **LPSTORAGE**

An instance of the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface. This is the storage object associated with the object.

### `polesite`

Type: **LPOLECLIENTSITE**

An instance of the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface. This is the object's client site in the rich edit control. This address must have been obtained from the [GetClientSite](https://learn.microsoft.com/windows/desktop/api/richole/nf-richole-iricheditole-getclientsite) method.

### `sizel`

Type: **SIZEL**

The size of the object. The unit of measure is 0.01 millimeters, which is a HIMETRIC measurement. For more information, see function [GetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmapmode). A 0, 0 on insertion indicates that an object is free to determine its size until the modify flag is turned off.

### `dvaspect`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Display aspect used. See [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) for an explanation of possible values.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Object status flag. It can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **REO_ALIGNTORIGHT** | Align the object with the right side of the view. This value is ignored if REO_WRAPTEXTAROUND is not specified. |
| **REO_BELOWBASELINE** | The object sits below the baseline of the surrounding text; the default is to sit on the baseline. |
| **REO_BLANK** | The object is new. This value gives the object an opportunity to save nothing and be deleted from the control automatically. |
| **REO_CANROTATE** | The object can display itself in a rotated position. |
| **REO_DONTNEEDPALETTE** | The object is rendered before the creation and realization of a half-tone palette. Applies to 32-bit platforms only. |
| **REO_DYNAMICSIZE** | The object always determines its extents and may change despite the modify flag being turned off. |
| **REO_GETMETAFILE** | The rich edit control retrieved the metafile from the object to correctly determine the object's extents. This flag can be read but not set. |
| **REO_HILITED** | The object is currently highlighted to indicate selection. Occurs when focus is in the control and **REO_SELECTED** is set. This flag can be read but not set. |
| **REO_INPLACEACTIVE** | The object is currently inplace active. This flag can be read but not set. |
| **REO_INVERTEDSELECT** | The object is to be drawn entirely inverted when selected; the default is to be drawn with a border. |
| **REO_LINK** | The object is a link. This flag can be read but not set. |
| **REO_LINKAVAILABLE** | The object is a link and is believed to be available. This flag can be read but not set. |
| **REO_OPEN** | The object is currently open in its server. This flag can be read but not set. |
| **REO_OWNERDRAWSELECT** | The owner draws the selected object. |
| **REO_RESIZABLE** | The object may be resized. |
| **REO_SELECTED** | The object is currently selected in the rich edit control. This flag can be read but not set. |
| **REO_STATIC** | The object is a static object. This flag can be read but not set. |
| **REO_USEASBACKGROUND** | Use the object as the background picture. |
| **REO_WRAPTEXTAROUND** | Wrap text around the object. |

### `dwUser`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved for user-defined values.

## Remarks

An OLE or image object in a rich edit control occupies one character position in the plain text part of the in-memory backing store and have the value U+FFFC. They differ from "in-line objects" such as math objects. In-line objects occupy at least two character positions because they have an in-line object start delimiter (U+FDD0) and end delimiter (U+FDEF).

## See also

[GetClientSite](https://learn.microsoft.com/windows/desktop/api/richole/nf-richole-iricheditole-getclientsite)

**Reference**