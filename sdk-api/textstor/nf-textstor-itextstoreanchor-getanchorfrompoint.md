# ITextStoreAnchor::GetAnchorFromPoint

## Description

The **ITextStoreAnchor::GetAnchorFromPoint** method converts a point in screen coordinates to an anchor positioned at a corresponding location.

## Parameters

### `vcView` [in]

Specifies the context view.

### `ptScreen` [in]

Pointer to the **POINT** structure with the screen coordinates of the point.

### `dwFlags` [in]

Specifies the anchor position to return based upon the screen coordinates of the point relative to a character bounding box. By default, the anchor position returned is the character bounding box containing the screen coordinates of the point. If the point is outside a character bounding box, the method returns **NULL** or [TF_E_INVALIDPOINT](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values). Other bit flags for this parameter are as follows.

The bit flags can be combined.

| Value | Meaning |
| --- | --- |
| **GXFPF_ROUND_NEAREST** | If the screen coordinates of the point are contained in a character bounding box, an anchor is returned at the bounding edge closest to the screen coordinates of the point. |
| **GXFPF_NEAREST** | If the screen coordinates of the point are not contained in a character bounding box, an anchor at the closest character position is returned. |

### `ppaSite` [out]

Pointer to an anchor object at a location corresponding to the screen coordinates *ptScreen*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One or more input parameters is invalid. |
| **E_OUTOFMEMORY** | The attempt to instantiate an anchor at the specified location failed. |
| **TS_E_INVALIDPOINT** | The *ptScreen* parameter is not within the bounding box of any character. |
| **TS_E_NOLAYOUT** | The application has not calculated a text layout yet. |

## Remarks

![Point 1 is in character bounding box and point 2 is outside the character bounding box.](https://learn.microsoft.com/windows/win32/api/textstor/images/ACPFig01.gif)
The point 1 screen coordinates cause the offset (character position) of anchor *ppaSite* to be 0 by default or if the *dwFlags* parameter is set to [GXFPF_NEAREST](https://learn.microsoft.com/windows/desktop/TSF/gxfpf--constants) because the point 1 screen coordinates are inside the character bounding box of character position 0. If the *dwFlags* parameter is set to GXFPF_ROUND_NEAREST for point 1, the anchor offset is 1 because the point 1 screen coordinates are closest to range position 1. Range position 1 is the starting range position of character position 1.

For the point 2 screen coordinates, the method returns **TF_E_INVALIDPOINT** by default or if the *dwFlags* parameter is set to **GXFPF_NEAREST** because the point 2 screen coordinates are outside a character bounding box. If the *dwFlags* parameter is set to **GXFPF_ROUND_NEAREST**, then the point 2 screen coordinates causes the anchor offset to be 1, because the closest character position to the point 2 screen coordinates is character position 1.

**Point 1**

* Default-- *anchor offset = 0* --The screen coordinates point is inside the character bounding box of Character Position 0.
* **GXFPF_ROUND_NEAREST** -- *anchor offset = 1* --The screen coordinates of the point is closest to Range Position 1 which is the starting range position of Character Position 1.
* **GXFPF_NEAREST** -- *anchor offset = 0* --The default behavior occurs because the point is within the character bounding box of Character Position 0.

**Point 2**

* Default-- *hr = TF_E_INVALIDPOINT* --The screen coordinates of the point are outside a character bounding box.
* GXFPF_ROUND_NEAREST-- *hr = TF_E_INVALIDPOINT* --The default behavior occurs because the screen coordinates of the point is outside a character bounding box.
* GXFPF_NEAREST-- *anchor offset = 1* --The closest character position to the screen coordinates of the point is Character Position 1.

## See also

[GXFPF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/gxfpf--constants)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITfContextView::GetRangeFromPoint](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-getrangefrompoint)

[Manager Return Values](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)