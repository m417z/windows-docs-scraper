# IWMCodecOutputTimestamp::GetNextOutputTime

## Description

Queries the decoder for the time stamp of the upcoming output sample. Use this method if you need to know the time of the sample before calling **IMediaObject::ProcessOutput** or [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) to get the sample.

## Parameters

### `prtTime` [out]

Address of a variable that receives the presentation time of the next sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is important when decoding video using frame interpolation, because the rendering application cannot predict the time stamps of interpolated frames.

## See also

[IWMCodecOutputTimestamp Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecoutputtimestamp)