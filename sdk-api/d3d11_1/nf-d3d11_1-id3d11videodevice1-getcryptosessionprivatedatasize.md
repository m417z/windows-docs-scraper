# ID3D11VideoDevice1::GetCryptoSessionPrivateDataSize

## Description

Retrieves optional sizes for private driver data.

## Parameters

### `pCryptoType` [in]

Type: **const GUID***

Indicates the crypto type for which the private input and output size is queried.

### `pDecoderProfile` [in, optional]

Type: **const GUID***

Indicates the decoder profile for which the private input and output size is queried.

### `pKeyExchangeType` [in]

Type: **const GUID***

Indicates the key exchange type for which the private input and output size is queried.

### `pPrivateInputSize` [out]

Type: **UINT***

Returns the size of private data that the driver needs for input commands.

### `pPrivateOutputSize` [out]

Type: **UINT***

Returns the size of private data that the driver needs for output commands.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

When *pKeyExchangeType* is **D3D11_KEY_EXCHANGE_HW_PROTECTION**, the following behavior is expected in the [ID3D11VideoContext::NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-negotiatecryptosessionkeyexchange) method:

* The *DataSize* parameter is set to the size of the [D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_data) structure.
* *pData* points to a [D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_data) structure.
  + The **pInputData** of this structure points to a [D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_input_data) structure where:
    - **pbInput**[0] – **pbInput**[N-1] contains memory reserved for use by the driver. The number of bytes (N) reserved for the driver is determined by the **pPrivateInputSize** value returned by the **ID3D11VideoDevice1::GetCryptoSessionPrivateDataSize** function.
    - **pbInput**[N] contains the first byte of the DRM command packet.
  + The **pOutputData** of this structure points to a [D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_output_data) structure where:
    - **pbOutput**[0] – **pbOutput**[N-1] contains memory reserved for use by the driver. The number of bytes (N) reserved for the driver is determined by the **pPrivateOutputSize** value returned by the **ID3D11VideoDevice1::GetCryptoSessionPrivateDataSize** function.
    - **pbOutput**[N] contains the first byte of the DRM command packet.

## See also

[ID3D11VideoDevice1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videodevice1)