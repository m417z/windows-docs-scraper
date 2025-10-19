# MFCreateAlignedMemoryBuffer function

## Description

Allocates system memory with a specified byte alignment and creates a media buffer to manage the memory.

## Parameters

### `cbMaxLength`

Size of the buffer, in bytes.

### `cbAligment`

Specifies the memory alignment for the buffer. Use one of the following constants.

| Value | Meaning |
| --- | --- |
| **MF_1_BYTE_ALIGNMENT**<br><br>0x00000000 | Align to 1 bytes. |
| **MF_2_BYTE_ALIGNMENT**<br><br>0x00000001 | Align to 2 bytes. |
| **MF_4_BYTE_ALIGNMENT**<br><br>0x00000003 | Align to 4 bytes. |
| **MF_8_BYTE_ALIGNMENT**<br><br>0x00000007 | Align to 8 bytes. |
| **MF_16_BYTE_ALIGNMENT**<br><br>0x0000000F | Align to 16 bytes. |
| **MF_32_BYTE_ALIGNMENT**<br><br>0x0000001F | Align to 32 bytes. |
| **MF_64_BYTE_ALIGNMENT**<br><br>0x0000003F | Align to 64 bytes. |
| **MF_128_BYTE_ALIGNMENT**<br><br>0x0000007F | Align to 128 bytes. |
| **MF_256_BYTE_ALIGNMENT**<br><br>0x000000FF | Align to 256 bytes. |
| **MF_512_BYTE_ALIGNMENT**<br><br>0x000001FF | Align to 512 bytes. |

### `ppBuffer`

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of the media buffer. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

When the media buffer object is destroyed, it releases the allocated memory.

## See also

[MFCreateMemoryBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatememorybuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)