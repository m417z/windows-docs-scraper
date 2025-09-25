# D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK structure

## Description

Describes a sub sample mapping block.

## Members

### `ClearSize`

The number of clear (non-encrypted) bytes at the start of the block.

### `EncryptedSize`

The number of encrypted bytes following the clear bytes.

## Remarks

Values in the sub sample mapping blocks are relative to the start of the decode buffer.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)