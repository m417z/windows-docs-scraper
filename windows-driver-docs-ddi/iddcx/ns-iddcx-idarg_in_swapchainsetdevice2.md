# IDARG_IN_SWAPCHAINSETDEVICE2 structure

## Description

Gives more information about the device that will process the swap chain.

## Members

### `Type`

This must be set correctly by the driver so the OS knows how to access the **IDARG_IN_SWAPCHAINSETDEVICE2::Device** object.

### `pDxgiDevice`

Must be set when **IDARG_IN_SWAPCHAINSETDEVICE2::Type** is set to IDDCX_SWAPCHAIN_DEVICE_TYPE_DXGI.

### `pD3d12Device`

Must be set when **IDARG_IN_SWAPCHAINSETDEVICE2::Type** is set to IDDCX_SWAPCHAIN_DEVICE_TYPE_D3D12.

## See also

[IDDCX_SWAPCHAIN_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_swapchain_device_type)