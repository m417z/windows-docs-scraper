# D3DKMT_QUERY_PHYSICAL_ADAPTER_PNP_KEY structure

## Description

The **D3DKMT_QUERY_PHYSICAL_ADAPTER_PNP_KEY** structure holds information to query the physical adapter PNP key.

## Members

### `PhysicalAdapterIndex`

The physical adapter index in the LDA (linked display adapter) chain.

### `PnPKeyType`

A [**D3DKMT_PNP_KEY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_pnp_key_type) enumeration value that specifies the type of the PNP key being queried.

### `pDest`

Pointer to a buffer that receives the requested PnP key as a wide-character string.

### `pCchDest`

Pointer to a variable that specifies the size of the **pDest** buffer, in characters. On input, it should contain the maximum number of characters that can be stored in the buffer. On output, it is updated to reflect the actual number of characters written to **pDest**, including the null terminator.

## See also

[**D3DKMT_PNP_KEY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_pnp_key_type)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)