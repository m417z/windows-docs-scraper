# _D3DDDICB_SUBMITCOMMANDFLAGS structure

## Description

**D3DDDICB_SUBMITCOMMANDFLAGS** is used to indicate how to process command buffers on contexts that support graphics processing unit (GPU) virtual addressing.

## Members

### `NullRendering`

Indicates whether the associated command buffers should be processed. When set, the command buffers should not be processed. This flag is set only during performance investigating and debugging to simulate an infinitely fast rendering engine that still must perform the overhead of DMA buffer submission and signaling. **NullRendering** is never set during typical operations.

Setting this member is equivalent to setting the first bit of the 32-bit Value member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

The consolidated value of the bit-field members in this structure.