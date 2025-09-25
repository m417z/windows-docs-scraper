# _D3DDDIARG_QUERYAUTHENICATEDCHANNEL structure

## Description

The D3DDDIARG_QUERYAUTHENTICATEDCHANNEL structure describes authenticated-channel information to query by using the [QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel) function.

## Members

### `InputSize` [in]

The size, in bytes, of the input data that the **pInputData** member points to.

### `pInputData` [in]

A pointer to a buffer that describes the information to query. The buffer that **pInputData** points to is defined identically to the input buffer that is passed to the **IDirect3DAuthenticatedChannel::Query** method. For more information about **IDirect3DAuthenticatedChannel::Query**, see the Windows SDK documentation.

### `OutputSize` [in]

The size, in bytes, of the output data that the **pOutputData** member points to.

### `pOutputData` [in/out]

A pointer to a buffer that describes the information that the [QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel) function returns. The buffer that **pOutputData** points to is defined identically to the output buffer that the **IDirect3DAuthenticatedChannel::Query** method returns.

## Remarks

The definitions of the input and output buffers to which the **pInputData** and **pOutputData** members point, depend on the type of information. The first member of the input buffer is always a D3DAUTHENTICATEDCHANNEL_QUERY_INPUT structure, whose **QueryType** member identifies the type of information to query.

The definition of the output buffer also depends on the information that the [QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel) function queries. However, the first member of the output buffer is always a D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT structure, whose members specify the following information:

* The **omac** member identifies the One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC) that permits the caller to authenticate the entire buffer, which prevents man-in-the-middle attacks.
* The **QueryType**, **hChannel**, and **SequenceNumber** members from the input buffer prevent against replay attacks.

## See also

[QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel)