# PFND3D11_1DDI_DISCARD callback function

## Description

Discards (evicts) an allocation from video display memory. Implemented by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `HandleType`

A value, of type [D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype), that identifies the context handle type.

### `hResourceOrView`

A pointer to a handle to the resource or to the view that is to be discarded.

### `unnamedParam4`

*pRects* [in, optional]

An optional array of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures for the rectangles in the resource view to discard. If **NULL**, the *Discard(D3D11_1)* function discards the entire surface.

### `NumRects`

The number of rectangles in the array that the *pRects* parameter specifies.

## Remarks

The D3D10_DDI_RECT structure is defined as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure.

```cpp
typedef RECT D3D10_DDI_RECT;
```

## See also

[D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)

[D3D11_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs)