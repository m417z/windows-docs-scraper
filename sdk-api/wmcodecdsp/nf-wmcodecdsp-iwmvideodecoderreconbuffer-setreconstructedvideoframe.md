# IWMVideoDecoderReconBuffer::SetReconstructedVideoFrame

## Description

**Note** This method is obsolete and should not be used.

Restores the current reconstructed video frame.

## Parameters

### `pBuf` [in]

Address of an IMediaBuffer interface containing the reconstructed frame to restore.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMVideoDecoderReconBuffer Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmvideodecoderreconbuffer)

[IWMVideoDecoderReconBuffer::GetReconstructedVideoFrame](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmvideodecoderreconbuffer-getreconstructedvideoframe)

[IWMVideoDecoderReconBuffer::GetReconstructedVideoFrameSize](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmvideodecoderreconbuffer-getreconstructedvideoframesize)