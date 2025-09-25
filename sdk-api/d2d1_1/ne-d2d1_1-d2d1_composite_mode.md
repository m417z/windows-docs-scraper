## Description

Used to specify the blend mode for all of the Direct2D blending operations.

## Constants

### `D2D1_COMPOSITE_MODE_SOURCE_OVER:0`

The standard source-over-destination blend mode.

### `D2D1_COMPOSITE_MODE_DESTINATION_OVER:1`

The destination is rendered over the source.

### `D2D1_COMPOSITE_MODE_SOURCE_IN:2`

Performs a logical clip of the source pixels against the destination pixels.

### `D2D1_COMPOSITE_MODE_DESTINATION_IN:3`

The inverse of the **D2D1_COMPOSITE_MODE_SOURCE_IN** operation.

### `D2D1_COMPOSITE_MODE_SOURCE_OUT:4`

This is the logical inverse to **D2D1_COMPOSITE_MODE_SOURCE_IN**.

### `D2D1_COMPOSITE_MODE_DESTINATION_OUT:5`

The is the logical inverse to **D2D1_COMPOSITE_MODE_DESTINATION_IN**.

### `D2D1_COMPOSITE_MODE_SOURCE_ATOP:6`

Writes the source pixels over the destination where there are destination pixels.

### `D2D1_COMPOSITE_MODE_DESTINATION_ATOP:7`

The logical inverse of **D2D1_COMPOSITE_MODE_SOURCE_ATOP**.

### `D2D1_COMPOSITE_MODE_XOR:8`

The source is inverted with the destination.

### `D2D1_COMPOSITE_MODE_PLUS:9`

The channel components are summed.

### `D2D1_COMPOSITE_MODE_SOURCE_COPY:10`

The source is copied to the destination; the destination pixels are ignored.

### `D2D1_COMPOSITE_MODE_BOUNDED_SOURCE_COPY:11`

Equivalent to **D2D1_COMPOSITE_MODE_SOURCE_COPY**, but pixels outside of the source bounds are unchanged.

### `D2D1_COMPOSITE_MODE_MASK_INVERT:12`

Destination colors are inverted according to a source mask.

### `D2D1_COMPOSITE_MODE_FORCE_DWORD:0xffffffff`

## Remarks

The figure here shows an example of each of the modes with images that have an opacity of 1.0 or 0.5.

![An example image of each of the modes with opacity set to 1.0 or 0.5.](https://learn.microsoft.com/windows/win32/api/d2d1_1/images/composite_types.png)

There can be slightly different interpretations of these enumeration values depending on where the value is used.

* With a composite effect:

  **D2D1_COMPOSITE_MODE_DESTINATION_COPY** is equivalent to **D2D1_COMPOSITE_MODE_SOURCE_COPY** with the inputs inverted.
* As a parameter to [ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)):
  **D2D1_COMPOSITE_MODE_DESTINATION_COPY** is a no-op since the destination is already in the selected target.

### Sample code

For an example that uses composite modes, download the [Direct2D composite effect modes sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/Direct2D%20composite%20effect%20modes%20sample).

## See also

[ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode))