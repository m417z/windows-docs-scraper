# _D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE structure

## Description

The D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE structure describes a buffer that contains the session key, which the authenticated channel uses.

## Members

### `hChannel` [in]

A handle to the authenticated channel that the runtime creates when the runtime calls the driver's [CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel) function.

### `DataSize` [in/out]

The size, in bytes, of the data that the **pData** member points to.

### `pData` [in/out]

A pointer to a buffer that contains the session key.

## See also

[AuthenticatedChannelKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_authenticatedchannelkeyexchange)

[CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel)