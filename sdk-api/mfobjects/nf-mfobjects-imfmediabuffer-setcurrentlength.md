# IMFMediaBuffer::SetCurrentLength

## Description

Sets the length of the valid data in the buffer.

## Parameters

### `cbCurrentLength` [in]

Length of the valid data, in bytes. This value cannot be greater than the allocated size of the buffer, which is returned by the [IMFMediaBuffer::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getmaxlength) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified length is greater than the maximum size of the buffer. |

## Remarks

Call this method if you write data into the buffer.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)