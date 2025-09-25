# IMFSample::ConvertToContiguousBuffer

## Description

Converts a sample with multiple buffers into a sample with a single buffer.

## Parameters

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sample does not contain any buffers. |

## Remarks

If the sample contains more than one buffer, this method copies the data from the original buffers into a new buffer, and replaces the original buffer list with the new buffer. The new buffer is returned in the *ppBuffer* parameter.

If the sample contains a single buffer, this method returns a pointer to the original buffer. In typical use, most samples do not contain multiple buffers.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)