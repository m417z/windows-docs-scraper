# IWMResizerProps::SetResizerQuality

## Description

Specifies whether to use an algorithm that produces higher-quality video, or a faster algorithm.

## Parameters

### `lquality` [in]

Boolean value. If **TRUE**, the video resizer uses an algorithm that produces higher-quality video. If **FALSE**, the video resizer uses a faster algorithm.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is equivalent to setting the [MFPKEY_RESIZE_QUALITY](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-resize-quality) property.

## See also

[IWMResizerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresizerprops)