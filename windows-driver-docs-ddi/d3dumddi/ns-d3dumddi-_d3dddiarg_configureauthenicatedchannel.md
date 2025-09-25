# _D3DDDIARG_CONFIGUREAUTHENICATEDCHANNEL structure

## Description

The D3DDDIARG_CONFIGUREAUTHENTICATEDCHANNEL structure describes the state that is set within an authenticated channel by using the [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function.

## Members

### `InputSize` [in]

The size, in bytes, of the input data that the **pInputData** member points to.

### `pInputData` [in]

A pointer to a buffer that describes the configuration data to set. The definition of the input buffer depends on the configuration data that is set. The buffer that **pInputData** points to is defined identically to the input buffer that is passed to the **IDirect3DAuthenticatedChannel::Configure** method. For more information about **IDirect3DAuthenticatedChannel::Configure**, see the Windows SDK documentation.

### `pOutputData` [in/out]

A pointer to a buffer that describes the information that the [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function returns.

## Remarks

The first member of the input buffer that the **pInputData** member points to is always the D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT structure, whose members specify the following information:

* The **ConfigureType** member identifies the configuration state to set.
* The **omac** member identifies the One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC), which verifies that the input is from a trusted source.
* The **SequenceNumber** member specifies a unique number that the driver can use to prevent against replay attacks.

The **pOutputData** member points to a D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT structure that contains the configuration type and the sequence number of the output buffer to prevent against replay attacks.

Configuration state that an authenticated channel sets cannot be disabled by another authenticated channel. A call to the driver's [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function with such an attempt fails.

## See also

[ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel)