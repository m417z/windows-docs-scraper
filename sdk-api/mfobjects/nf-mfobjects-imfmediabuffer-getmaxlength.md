# IMFMediaBuffer::GetMaxLength

## Description

Retrieves the allocated size of the buffer.

## Parameters

### `pcbMaxLength` [out]

Receives the allocated size of the buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The buffer might or might not contain any valid data, and if there is valid data in the buffer, it might be smaller than the buffer's allocated size. To get the length of the valid data, call [IMFMediaBuffer::GetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getcurrentlength).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)