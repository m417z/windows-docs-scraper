# _D3DKMT_GETPRESENTHISTORY structure

## Description

The D3DKMT_GETPRESENTHISTORY structure describes the state of copying history.

## Members

### `hAdapter` [in]

The handle to the graphics adapter.

### `ProvidedSize` [in]

Supported in Windows 7 and later versions.

The size, in bytes, of the provided buffer that the **pTokens** member points to.

### `WrittenSize` [out]

Supported in Windows 7 and later versions.

The size, in bytes, that the [D3DKMTGetPresentHistory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetpresenthistory) function copies to the buffer that the **pTokens** member points to or the required size for first token.

### `pTokens` [in/out]

Supported in Windows 7 and later versions.

A pointer to the buffer that receives the tokens. Each token is described by a [D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken) structure.

### `NumTokens` [out]

Supported in Windows 7 and later versions.

The number of tokens that the [D3DKMTGetPresentHistory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetpresenthistory) function copies to the buffer that the **pTokens** member points to.

## See also

[D3DKMTGetPresentHistory](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetpresenthistory)

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)