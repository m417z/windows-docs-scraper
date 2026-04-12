# IDDCX_DEVICE_FEATURES_1_11 enumeration

## Description

A **IDDCX_FEATURE_IMPLEMENTATION** value is used to indicate how a given IddCx version 1.11 supported feature is implemented.

## Constants

### `IDDCX_DEVICE_FEATURES_1_11_D3D12:1`

The underlying OS supports D3D12 swap chains.

### `IDDCX_DEVICE_FEATURES_1_11_DISPLAY_ID_ONLY:2`

The underlying OS supports the driver submitting DisplayID only monitor descriptors.

### `IDDCX_DEVICE_FEATURES_1_11_UPDATE_REENCODE_COUNT:4`

The underlying OS supports updating the StaticDesktopReencodeFrameCount value for a swap chain.

## See also

[**IDARG_OUT_FEATURES_SUPPORTED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_features_supported)