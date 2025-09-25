# RICHEDIT_IMAGE_PARAMETERS structure

## Description

Defines the attributes of an image to be inserted by the [EM_INSERTIMAGE](https://learn.microsoft.com/windows/desktop/Controls/em-insertimage) message.

## Members

### `xWidth`

The width, in HIMETRIC units (0.01 mm), of the image.

### `yHeight`

### `Ascent`

If *Type* is TA_BASELINE, this parameter is the distance, in HIMETRIC units, that the top of the image extends above the text baseline. If *Type* is TA_BASELINE and ascent is zero, the bottom of the image is placed at the text baseline.

### `Type`

The vertical alignment of the image. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TA_BASELINE** | Align the image relative to the text baseline. |
| **TA_BOTTOM** | Align the bottom of the image at the bottom of the text line. |
| **TA_TOP** | Align the top of the image at the top of the text line |

### `pwszAlternateText`

The alternate text for the image.

### `pIStream`

The stream that contains the image data.

#### - xHeight

The height, in HIMETRIC units, of the image.

## See also

[EM_INSERTIMAGE](https://learn.microsoft.com/windows/desktop/Controls/em-insertimage)