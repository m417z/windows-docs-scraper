# IWMVideoForceKeyFrame::SetKeyFrame

## Description

Specifies that the current frame will be encoded as a key frame.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To force the encoder to make the current frame a key frame, call this method before calling **IMediaObject::ProcessOutput** or [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

Each call to this method applies to a single frame. After processing this frame, the encoder resumes automatically assigning key frames (bounded by the maximum key frame distance).

## See also

[IWMVideoForceKeyFrame Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmvideoforcekeyframe)