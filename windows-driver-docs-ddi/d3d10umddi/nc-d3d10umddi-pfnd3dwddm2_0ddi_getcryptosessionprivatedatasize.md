# PFND3DWDDM2_0DDI_GETCRYPTOSESSIONPRIVATEDATASIZE callback function

## Description

**GetCryptoSessionPrivateDataSize** retrieves sizes for optional private driver data.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `pCryptoType`

Indicates the crypto type for which the private input and output size is queried.

### `pDecoderProfile`

Indicates the decoder profile for which the private input and output size is queried.

### `pKeyExchangeType`

Indicates the key exchange type for which the private input and output size is queried.

### `pPrivateInputSize`

Returns the size of private data that the driver needs for input commands.

### `pPrivateOutputSize`

Returns the size of private data that the driver needs for output commands.

## Remarks

When **pKeyExchangeType** is **D3D11_KEY_EXCHANGE_HW_PROTECTION**, the following behavior is expected in the **NegotiateCryptessionKeyExchange**device driver interface (DDI):

* **DataSize** is set to the size of the **D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA** structure.
* **pData** points to a **D3D11_KEY_EXCHANGE_CONTENT_PROTECTION_DATA** structure.
* **pInputData** points to a **D3D11_KEY_EXCHANGE_CONTENT_PROTECTION_OUTPUT_DATA** structure where:

  + **pbInput**[0] – **pbInput**[N-1] contains memory reserved for use by the driver. The number of bytes (N) reserved for the driver is determined by the **pPrivateInputSize** value returned by the **GetCryptoSessionPrivateDataSize**DDI.
  + **pbInput**[N] contains the first byte of the Digital Rights Management (DRM) command packet.
* **pOutputData** points to a **D3D11_KEY_EXCHANGE_CONTENT_PROTECTION_OUTPUT_DATA** structure where:

  + **pbOutput**[0] – **pbOutput**[M-1] contains memory reserved for use by the driver. The number of bytes (M) reserved for the driver is determined by the **pPrivateOutputSize** value returned by the **GetCryptoSessionPrivateDataSize**DDI.
  + **pbOutput**[M] contains the first byte of the DRM command packet.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)