# D2D1_PRIMITIVE_BLEND enumeration

## Description

Used to specify the geometric blend mode for all Direct2D primitives.

## Constants

### `D2D1_PRIMITIVE_BLEND_SOURCE_OVER:0`

The standard source-over-destination blend mode.

### `D2D1_PRIMITIVE_BLEND_COPY:1`

The source is copied to the destination; the destination pixels are ignored.

### `D2D1_PRIMITIVE_BLEND_MIN:2`

The resulting pixel values use the minimum of the source and destination pixel values. Available in Windows 8 and later.

### `D2D1_PRIMITIVE_BLEND_ADD:3`

The resulting pixel values are the sum of the source and destination pixel values. Available in Windows 8 and later.

### `D2D1_PRIMITIVE_BLEND_MAX:4`

The resulting pixel values use the maximum of the source and destination pixel values.
Available in Windows 10 and later (set using [ID21CommandSink4::SetPrimitiveBlend2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1commandsink4-setprimitiveblend2)).

### `D2D1_PRIMITIVE_BLEND_FORCE_DWORD:0xffffffff`

## Remarks

### Blend modes

For aliased rendering (except for MIN mode), the output value O is computed by linearly interpolating the value *blend(S, D)* with the destination pixel value, based on the amount that the primitive covers the destination pixel.

The table here shows the primitive blend modes for both aliased and antialiased blending. The equations listed in the table use these elements:

* O = Output
* S = Source
* SA = Source Alpha
* D = Destination
* DA = Destination Alpha
* C = Pixel coverage

| Primitive blend mode | Aliased blending | Antialiased blending | Description |
| --- | --- | --- | --- |
| D2D1_PRIMITIVE_BLEND_SOURCE_OVER | O = (S + (1 – SA) * D) * C + D * (1 – C) | O = S * C + D *(1 – SA *C) | The standard source-over-destination blend mode. |
| D2D1_PRIMITIVE_BLEND_COPY | O = S * C + D * (1 – C) | O = S * C + D * (1 – C) | The source is copied to the destination; the destination pixels are ignored. |
| D2D1_PRIMITIVE_BLEND_MIN | O = Min(S + 1-SA, D) | O = Min(S * C + 1 – SA *C, D) | The resulting pixel values use the minimum of the source and destination pixel values. Available in Windows 8.1 and later. |
| D2D1_PRIMITIVE_BLEND_ADD | O = (S + D) * C + D * (1 – C) | O = S * C + D | The resulting pixel values are the sum of the source and destination pixel values. Available in Windows 8.1 and later. |

![An illustration of Direct2D primitive blend modes with varying opacity and backgrounds.](https://learn.microsoft.com/windows/win32/api/d2d1_1/images/PrimBlendDemo.png)
An illustration of the primitive blend modes with varying opacity and backgrounds.

## See also

[ID2D1DeviceContext::GetPrimitiveBlend](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getprimitiveblend)

[ID2D1DeviceContext::SetPrimitiveBlend](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setprimitiveblend)