# ID2D1Bitmap1::Unmap

## Description

Unmaps the bitmap from memory.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | One or more arguments are not valid. |
| E_POINTER | Pointer is not valid. |

## Remarks

Any memory returned from the [Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map) call is now invalid and may be reclaimed by the operating system or used for other purposes.

The bitmap must have been previously mapped.

## See also

[D2D1_BITMAP_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options)

[D2D1_MAPPED_RECT](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_mapped_rect)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)