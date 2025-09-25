# ITfContextOwner::GetACPFromPoint

## Description

The **ITfContextOwner::GetACPFromPoint** method converts a point in screen coordinates to an application character position.

## Parameters

### `ptScreen` [in]

Pointer to the **POINT** structure with the screen coordinates of the point.

### `dwFlags` [in]

Specifies the character position to return based upon the screen coordinates of the point relative to a character bounding box. By default, the character position returned is the character bounding box containing the screen coordinates of the point. If the point is outside a character's bounding box, the method returns **NULL** or TF_E_INVALIDPOINT.

If the GXFPF_ROUND_NEAREST flag is specified for this parameter and the screen coordinates of the point are contained in a character bounding box, the character position returned is the bounding edge closest to the screen coordinates of the point.

If the GXFPF_NEAREST flag is specified for this parameter and the screen coordinates of the point are not contained in a character bounding box, the closest character position is returned.

The bit flags can be combined.

### `pacp` [out]

Receives the character position that corresponds to the screen coordinates of the point

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_INVALIDPOINT** | The *ptScreen* parameter is not within the bounding box of any character. |
| **TS_E_NOLAYOUT** | The application has not calculated a text layout. |

## Remarks

![Point 1 is in character bounding box and point 2 is outside the character bounding box.](https://learn.microsoft.com/windows/win32/api/msctf/images/ACPFig01.gif)
Use the illustration to determine the character position returned based on the flags used in the *dwFlags* parameter.

**Point 1**

* Default-- *pacp = 0* --The screen coordinates of the point is inside the character bounding box of Character Position 0.
* GXFPF_ROUND_NEAREST-- *pacp = 1* --The screen coordinates of the point is closest to Range Position 1 which is the starting range position of Character Position 1.
* GXFPF_NEAREST-- *pacp = 0* --The default behavior occurs because the point lies within the character bounding box of Character Position 0.

**Point 2**

* Default-- *hr = TF_E_INVALIDPOINT* --The screen coordinates of the point is outside a character bounding box.
* GXFPF_ROUND_NEAREST-- *hr = TF_E_INVALIDPOINT* --The default behavior occurs because the screen coordinates of the point is outside a character bounding box.
* GXFPF_NEAREST-- *pacp = 1* --The closest character position to the screen coordinates of the point is Character Position 1.

## See also

[ITextStoreACP::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getacpfrompoint)

[ITfContextOwner](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextowner)

[ITfContextView::GetRangeFromPoint](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-getrangefrompoint)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)