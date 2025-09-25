# D3D11_1DDI_ENCRYPTED_BLOCK_INFO structure

## Description

Specifies which bytes in a video surface are encrypted.

## Members

### `NumEncryptedBytesAtBeginning`

The number of bytes that are encrypted at the start of the buffer.

### `NumBytesInSkipPattern`

The number of bytes that are skipped after the first **NumEncryptedBytesAtBeginning** bytes, and then after each block of **NumBytesInEncryptPattern** bytes. Skipped bytes are not encrypted.

### `NumBytesInEncryptPattern`

The number of bytes that are encrypted after each block of skipped bytes.

The skip and encrypt pattern is then repeated until the buffer ends. For more information about the skip-encrypt pattern, see the Remarks section.

## Remarks

Because the buffer's encrypted portion is specified in bytes, an application must ensure that the encrypted blocks match the GPU's crypto-block alignment.

The following examples show how the runtime can partition a buffer's encryption.

1. The following values encrypt the first 100 bytes of the buffer and skip the remaining buffer data:
   * **NumEncryptedBytesAtBeginning** = 100;
   * **NumBytesInSkipPattern** = 0;
   * **NumBytesInEnycryptPattern** = 0;
2. The following values encrypt the first 100 bytes of the buffer, skips the next 20 bytes, and then encrypt the next 2 bytes blocks. The process is then repeated where these values skip 20 bytes and encrypt 2 bytes until the end of the buffer.
   * **NumEncryptedBytesAtBeginning** = 100;
   * **NumBytesInSkipPattern** = 20;
   * **NumBytesInEnycryptPattern** = 2;