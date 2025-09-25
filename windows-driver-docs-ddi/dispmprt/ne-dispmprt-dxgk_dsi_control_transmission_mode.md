# DXGK_DSI_CONTROL_TRANSMISSION_MODE enumeration

## Description

Describes an override for the transmission mode, allowing the OEM panel driver to specify whether low power or high performance mode should be used for write packets in the transmission to mitigate cases where a panel only supports one of the modes.

## Constants

### `DXGK_DCT_DEFAULT`

Graphics driver selects transmission mode based on size of payload, current transmission mode and host capabilities. This allows the driver to use the most optimal mode of transmission so should be used unless the OEM panel driver has hardware limitations which the graphics driver is not expected to be aware of which require one specific transmission mode.

### `DXGK_DCT_FORCE_LOW_POWER`

Write packets should use low-power transmission mode or failed if that is not available.

### `DXGK_DCT_FORCE_HIGH_SPEED`

Write packets should use high-speed transmission mode or failed if that is not available.

## Remarks

## See also