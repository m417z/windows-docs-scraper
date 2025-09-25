# MFCreateMediaBufferWrapper function

## Description

Creates a media buffer that wraps an existing media buffer. The new media buffer points to the same memory as the original media buffer, or to an offset from the start of the memory.

## Parameters

### `pBuffer` [in]

A pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of the original media buffer.

### `cbOffset` [in]

The start of the new buffer, as an offset in bytes from the start of the original buffer.

### `dwLength` [in]

The size of the new buffer. The value of *cbOffset* + *dwLength* must be less than or equal to the size of valid data the original buffer. (The size of the valid data is returned by the [IMFMediaBuffer::GetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-getcurrentlength) method.)

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | The requested offset or the requested length is not valid. |

## Remarks

The maximum size of the wrapper buffer is limited to the size of the valid data in the original buffer. This might be less than the allocated size of the original buffer. To set the size of the valid data, call [IMFMediaBuffer::SetCurrentLength](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-setcurrentlength).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)