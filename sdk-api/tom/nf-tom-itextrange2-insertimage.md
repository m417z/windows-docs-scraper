# ITextRange2::InsertImage

## Description

Inserts an image into this range.

## Parameters

### `width` [in]

Type: **long**

The width, in HIMETRIC units (0.01 mm), of the image.

### `height` [in]

Type: **long**

The height, in HIMETRIC units, of the image.

### `ascent` [in]

Type: **long**

If *Type* is TA_BASELINE, this parameter is the distance, in HIMETRIC units, that the top of the image extends above the text baseline. If *Type* is TA_BASELINE and *ascent* is zero, the bottom of the image is placed at the text baseline.

### `Type` [in]

Type: **long**

The vertical alignment of the image. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TA_BASELINE** | Align the image relative to the text baseline. |
| **TA_BOTTOM** | Align the bottom of the image at the bottom of the text line. |
| **TA_TOP** | Align the top of the image at the top of the text line |

### `bstrAltText` [in]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)**

The alternate text for the image.

### `pStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)**

The stream that contains the image data.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the range is nondegenerate, the image replaces the text in the range.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)