# IWICColorContext::InitializeFromExifColorSpace

## Description

Initializes the color context using an Exchangeable Image File (EXIF) color space.

## Parameters

### `value` [in]

Type: **UINT**

The value of the EXIF color space.

| Value | Meaning |
| --- | --- |
| 1 | A sRGB color space. |
| 2 | An Adobe RGB color space. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Once a color context has been initialized, it can't be re-initialized.