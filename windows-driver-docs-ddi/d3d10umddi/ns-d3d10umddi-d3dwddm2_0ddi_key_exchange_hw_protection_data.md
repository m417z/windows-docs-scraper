# D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA structure

## Description

**D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA** is used with [NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange) in the implementation of Digital Rights Management (DRM).

## Members

### `HWProtectionFunctionID`

Specifies the function ID of the DRM command. The values and meanings of the function ID are defined by each individual DRM component.

### `pInputData`

Pointer to a buffer containing a [D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_input_data) structure, reserved memory for IHV use, and the input data for the DRM command.

### `pOutputData`

Pointer to a buffer containing a [D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_output_data) structure, reserved memory for IHV use, and the output data for the DRM command.

### `Status`

Returns the result of the hardware DRM command.

## Remarks

A pointer to this structure is passed in as the *pData* parameter of [NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange) function when the **CryptoSession** object is creating using the **D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION** key exchange type.

## See also

[D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_input_data)

[D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_key_exchange_hw_protection_output_data)

[NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange)