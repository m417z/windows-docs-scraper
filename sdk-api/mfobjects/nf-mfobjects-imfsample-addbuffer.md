# IMFSample::AddBuffer

## Description

Adds a buffer to the end of the list of buffers in the sample.

## Parameters

### `pBuffer` [in]

Pointer to the buffer's [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## Remarks

For uncompressed video data, each buffer should contain a single video frame, and samples should not contain multiple frames. In general, storing multiple buffers in a sample is discouraged.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)