# DVASPECTINFO structure

## Description

Contains information that is used by the [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) method to optimize rendering of an inactive object by making more efficient use of the GDI.

## Members

### `cb`

The size of the structure, in bytes.

### `dwFlags`

A value taken from the [DVASPECTINFOFLAG](https://learn.microsoft.com/windows/win32/api/ocidl/ne-ocidl-dvaspectinfoflag) enumeration.

## See also

[DVASPECTINFOFLAG](https://learn.microsoft.com/windows/win32/api/ocidl/ne-ocidl-dvaspectinfoflag)

[IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw)