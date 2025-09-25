# Font::Font(IN HDC,IN const HFONT)

## Description

Creates a **Font::Font** object indirectly from a Windows Graphics Device Interface (GDI) logical font by using a handle to a GDI **LOGFONT** structure.

## Parameters

### `hdc` [in]

Type: **HDC**

Handle to a Windows device context. A handle is a number that Windows uses internally to reference an object.

### `hfont` [in]

Type: **const HFONT**

Handle to a logical font.

## Remarks

A device context is a structure that is maintained internally. It is associated with a particular device, such as a video monitor or a printer. There is usually one device context associated with each window displayed on a video monitor. A device context contains some graphics attributes used by GDI+.