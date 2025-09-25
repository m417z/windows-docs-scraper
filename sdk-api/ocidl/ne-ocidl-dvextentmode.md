# DVEXTENTMODE enumeration

## Description

Indicates whether the sizing mode is content or integral sizing.

## Constants

### `DVEXTENT_CONTENT:0`

Indicates that the container will ask the object how big it wants to be to exactly fit its content, for example, in snap-to-size operations.

### `DVEXTENT_INTEGRAL`

Indicates that the container will provide a proposed size to the object for its use in resizing.

## See also

[DVEXTENTINFO](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-dvextentinfo)

[IViewObjectEx::GetNaturalExtent](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent)