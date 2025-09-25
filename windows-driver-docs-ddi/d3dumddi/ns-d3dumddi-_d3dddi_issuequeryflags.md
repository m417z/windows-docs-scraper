# _D3DDDI_ISSUEQUERYFLAGS structure

## Description

The D3DDDI_ISSUEQUERYFLAGS structure identifies the state of a query issue.

## Members

### `Begin`

A UINT value that specifies whether to start the query issue. The Microsoft Direct3D runtime does not request query data while in this state.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `End`

A UINT value that specifies whether to end the query issue and transition the state to subsignaled. Results of the query are not available until the state transitions to signaled.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFC) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_ISSUEQUERYFLAGS that can hold one 32-bit value that identifies the state of the query.

## See also

[D3DDDIARG_ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_issuequery)