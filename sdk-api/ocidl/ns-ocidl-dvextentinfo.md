# DVEXTENTINFO structure

## Description

Represents the sizing data used in [IViewObjectEx::GetNaturalExtent](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent).

## Members

### `cb`

The size of the structure, in bytes.

### `dwExtentMode`

Indicates whether the sizing mode is content or integral sizing. See the [DVEXTENTMODE](https://learn.microsoft.com/windows/win32/api/ocidl/ne-ocidl-dvextentmode) enumeration for possible values.

### `sizelProposed`

The proposed size in content sizing or the preferred size in integral sizing.

## See also

[DVEXTENTMODE](https://learn.microsoft.com/windows/win32/api/ocidl/ne-ocidl-dvextentmode)

[IViewObjectEx::GetNaturalExtent](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iviewobjectex-getnaturalextent)