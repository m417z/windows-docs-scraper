# MFCreateMemoryBuffer function

## Description

Allocates system memory and creates a media buffer to manage it.

## Parameters

### `cbMaxLength`

Size of the buffer, in bytes.

### `ppBuffer`

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of the media buffer. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The function allocates a buffer with a 1-byte memory alignment. To allocate a buffer that is aligned to a larger memory boundary, call [MFCreateAlignedMemoryBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatealignedmemorybuffer).

When the media buffer object is destroyed, it releases the allocated memory.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)