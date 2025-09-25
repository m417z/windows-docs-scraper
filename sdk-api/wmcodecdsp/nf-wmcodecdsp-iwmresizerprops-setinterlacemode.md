# IWMResizerProps::SetInterlaceMode

## Description

The **SetInterlaceMode** method specifies whether the input video stream is interlaced.

## Parameters

### `lmode` [in]

Boolean value. If **TRUE**, the video is interlaced. If **FALSE**, the video is progressive.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is equivalent to setting the [MFPKEY_RESIZE_INTERLACE](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-interlace) property.

## See also

[IWMResizerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresizerprops)