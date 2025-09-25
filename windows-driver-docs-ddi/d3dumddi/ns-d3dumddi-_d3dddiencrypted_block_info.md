# _D3DDDIENCRYPTED_BLOCK_INFO structure

## Description

The D3DDDIENCRYPTED_BLOCK_INFO structure describes the portions of a buffer that are encrypted.

## Members

### `NumEncryptedBytesAtBeginning` [in]

The number of bytes at the beginning of the buffer that are encrypted.

### `NumBytesInSkipPattern` [in]

The number of bytes in the buffer that are skipped from encryption before encryption starts again.

### `NumBytesInEncryptPattern` [in]

The number of bytes in the buffer that are encrypted after the skip pattern, which the **NumBytesInSkipPattern** member specifies. The skip and encrypt pattern is then repeated until the buffer ends. For more information about the skip-encrypt pattern, see the Remarks section.

## Remarks

Because the buffer's encrypted portion is specified in bytes, an application must ensure that the encrypted blocks match the GPU's crypto-block alignment.

The runtime can specify a populated D3DDDIENCRYPTED_BLOCK_INFO structure in the block of memory that the **pEncryptedBlockInfo** member of the [D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt) structure points to when the runtime calls the driver's [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt) function to write data to a protected surface.

The following examples show how the runtime can partition a buffer's encryption.

1. The following values encrypt the first 100 bytes of the buffer and skip the remaining buffer data:
   * **NumEncryptedBytesAtBeginning** = 100;
   * **NumBytesInSkipPattern** = 0;
   * **NumBytesInEnycryptPattern** = 0;
2. The following values encrypt the first 100 bytes of the buffer, skips the next 20 bytes, and then encrypt the next 2 bytes blocks. The process is then repeated where these values skip 20 bytes and encrypt 2 bytes until the end of the buffer.
   * **NumEncryptedBytesAtBeginning** = 100;
   * **NumBytesInSkipPattern** = 20;
   * **NumBytesInEnycryptPattern** = 2;

## See also

[D3DDDIARG_DECRYPTIONBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decryptionblt)

[DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt)