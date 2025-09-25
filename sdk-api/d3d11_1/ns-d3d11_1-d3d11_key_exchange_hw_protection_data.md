# D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA structure

## Description

Represents key exchange data for hardware content protection.

## Members

### `HWProtectionFunctionID`

The function ID of the DRM command. The values and meanings of the function ID are defined by the DRM specification.

### `pInputData`

Pointer to a buffer containing a [D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_input_data) structure that specifies memory reserved for IHV use and the input data for the DRM command.

### `pOutputData`

Pointer to a buffer containing a [D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_key_exchange_hw_protection_output_data) structure that specifies memory reserved for IHV use and the input data for the DRM command.

### `Status`

The result of the hardware DRM command.

## Remarks

A pointer to this structure is passed in the *pData* parameter of [ID3D11VideoContext::NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-negotiatecryptosessionkeyexchange) method when the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) is creating using the **D3D11_KEY_EXCHANGE_HW_PROTECTION** key exchange type.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)