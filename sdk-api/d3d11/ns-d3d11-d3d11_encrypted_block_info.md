# D3D11_ENCRYPTED_BLOCK_INFO structure

## Description

Specifies which bytes in a video surface are encrypted.

## Members

### `NumEncryptedBytesAtBeginning`

The number of bytes that are encrypted at the start of the buffer.

### `NumBytesInSkipPattern`

The number of bytes that are skipped after the first **NumEncryptedBytesAtBeginning** bytes, and then after each block of **NumBytesInEncryptPattern** bytes. Skipped bytes are not encrypted.

### `NumBytesInEncryptPattern`

The number of bytes that are encrypted after each block of skipped bytes.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoContext::SubmitDecoderBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-submitdecoderbuffers)