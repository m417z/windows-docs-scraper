# IDDCX_SWAPCHAIN_DEVICE_TYPE enumeration

## Description

A **IDDCX_SWAPCHAIN_DEVICE_TYPE** value is used to indicate how to set the swap chain device type.

## Constants

### `IDDCX_SWAPCHAIN_DEVICE_TYPE_INVALID:0`

The swap chain device type is invalid.

### `IDDCX_SWAPCHAIN_DEVICE_TYPE_DXGI:1`

The value used when the driver wants to set **[IDARG_IN_SWAPCHAINSETDEVICE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_swapchainsetdevice2)::Driver.pDxgiDevice**.

### `IDDCX_SWAPCHAIN_DEVICE_TYPE_D3D12:2`

The value used when the driver wants to set **[IDARG_IN_SWAPCHAINSETDEVICE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_swapchainsetdevice2)::Driver.pD3d12Device**.

## See also

[**IDARG_IN_SWAPCHAINSETDEVICE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_swapchainsetdevice2)