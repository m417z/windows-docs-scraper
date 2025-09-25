# IMFSample::GetBufferByIndex

## Description

Gets a buffer from the sample, by index.

**Note** In most cases, it is safer to use the [IMFSample::ConvertToContiguousBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-converttocontiguousbuffer) method. If the sample contains more than one buffer, the **ConvertToContiguousBuffer** method replaces them with a single buffer, copies the original data into that buffer, and returns the new buffer to the caller. The copy operation occurs at most once. On subsequent calls, no data is copied.

## Parameters

### `dwIndex` [in]

Index of the buffer. To find the number of buffers in the sample, call [IMFSample::GetBufferCount](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-getbuffercount). Buffers are indexed from zero.

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** pointer argument, or the index is out of range. |

## Remarks

A sample might contain more than one buffer. Use the **GetBufferByIndex** method to enumerate the individual buffers.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[IMFSample::ConvertToContiguousBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-converttocontiguousbuffer)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)