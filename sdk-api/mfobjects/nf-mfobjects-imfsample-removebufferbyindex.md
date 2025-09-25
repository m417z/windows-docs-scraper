# IMFSample::RemoveBufferByIndex

## Description

Removes a buffer at a specified index from the sample.

## Parameters

### `dwIndex` [in]

Index of the buffer. To find the number of buffers in the sample, call [IMFSample::GetBufferCount](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-getbuffercount). Buffers are indexed from zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)