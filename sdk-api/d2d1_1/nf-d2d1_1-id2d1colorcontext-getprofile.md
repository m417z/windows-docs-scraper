# ID2D1ColorContext::GetProfile

## Description

Gets the color profile bytes for an [ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext).

## Parameters

### `profile` [out]

Type: **BYTE***

When this method returns, contains the color profile.

### `profileSize`

Type: **UINT32**

The size of the *profile* buffer.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_INSUFFICIENT_BUFFER | The supplied buffer was too small to accommodate the data. |

## Remarks

If *profileSize* is insufficient to store the entire profile, *profile* is zero-initialized before this method fails.

## See also

[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)

[ID2D1Bitmap1::GetColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-getcolorcontext)

[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)

[ID2D1ColorContext::GetProfileSize](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1colorcontext-getprofilesize)