# ITfContextView::GetRangeFromPoint

## Description

The **ITfContextView::GetRangeFromPoint** method converts a point, in screen coordinates, to an empty range of text positioned at a corresponding location.

## Parameters

### `ec` [in]

Specifies the edit cookie with read-only access.

### `ppt` [in]

Specifies the point in screen coordinates.

### `dwFlags` [in]

Specifies the range position to return based upon the screen coordinates of the point to a character bounding box. By default, the range position returned is the character bounding box containing the screen coordinates of the point. If the point is outside a character bounding box, the method returns **NULL** or [TF_E_INVALIDPOINT](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values). Other bit flags for this parameter are as follows.

The bit flags can be combined.

| Value | Meaning |
| --- | --- |
| **GXFPF_ROUND_NEAREST** | If the screen coordinates of the point are contained in a character bounding box, the range position returned is the bounding edge closest to the screen coordinates of the point. |
| **GXFPF_NEAREST** | If the screen coordinates of the point are not contained in a character bounding box, the closest range position is returned. |

### `ppRange` [out]

Receives a pointer to the ITfRange interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_INVALIDPOINT** | The *pptScreen* parameter does not cover any document text. |
| **TF_E_NOLAYOUT** | The application has not calculated a text layout. |
| **TF_E_NOLOCK** | The specified edit cookie is invalid. |

## Remarks

![Point 1 is in character bounding box and point 2 is outside the character bounding box.](https://learn.microsoft.com/windows/win32/api/msctf/images/RngFig01.gif)
By default, the method will return a range positioned at 0 for point 1 and TF_E_INVALIDPOINT for point 2. If the *dwFlags* parameter is set to [GXFPF_ROUND_NEAREST](https://learn.microsoft.com/windows/desktop/TSF/gxfpf--constants), the method returns range position 1 for point 1. If the *dwFlags* parameter is set to GXFPF_NEAREST then the method returns range position 2 for point 2.

## See also

[GXFPF_NEAREST](https://learn.microsoft.com/windows/desktop/TSF/gxfpf--constants)

GXFPF_ROUND_NEAREST

[ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview)

[TF_E_INVALIDPOINT](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values)