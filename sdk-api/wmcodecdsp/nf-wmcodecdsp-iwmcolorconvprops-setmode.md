# IWMColorConvProps::SetMode

## Description

Specifies whether the input video stream is interlaced.

## Parameters

### `lMode` [in]

Specifies one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Progressive video |
| 2 | Interlaced video |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

By default, the color converter uses the input media type to determine whether the video is interlaced. You can call this method to override the media type setting.

This method is equivalent to setting the [MFPKEY_COLORCONV_MODE](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-colorconv-mode) property.

## See also

[IWMColorConvProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcolorconvprops)