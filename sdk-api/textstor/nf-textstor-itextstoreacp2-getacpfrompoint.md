# ITextStoreACP2::GetACPFromPoint

## Description

Converts a point in screen coordinates to an application character position.

## Parameters

### `vcView` [in]

Specifies the context view.

### `ptScreen` [in]

Pointer to the **POINT** structure with the screen coordinates of the point.

### `dwFlags` [in]

Specifies the character position to return based upon the screen coordinates of the point relative to a character bounding box. By default, the character position returned is the character bounding box containing the screen coordinates of the point. If the point is outside a character bounding box, the method returns **NULL** or [TF_E_INVALIDPOINT](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values). Other bit flags for this parameter are as follows.

The bit flags can be combined.

| Value | Meaning |
| --- | --- |
| **GXFPF_ROUND_NEAREST** | If the screen coordinates of the point are contained in a character bounding box, the character position returned is the bounding edge closest to the screen coordinates of the point. |
| **GXFPF_NEAREST** | If the screen coordinates of the point are not contained in a character bounding box, the closest character position is returned. |

### `pacp` [out]

Receives the character position that corresponds to the screen coordinates of the point.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_INVALIDPOINT** | The *ptScreen* parameter is not within the bounding box of any character. |
| **TS_E_NOLAYOUT** | The application has not calculated a text layout. |

## See also

[GXFPF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/gxfpf--constants)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[ITfContextOwner::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getacpfrompoint)

[ITfContextView::GetRangeFromPoint](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-getrangefrompoint)

[Manager Return Values](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)