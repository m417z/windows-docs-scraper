# _D3DDDI_CREATEDEVICEFLAGS structure

## Description

The D3DDDI_CREATEDEVICEFLAGS structure describes how to create a device.

## Members

### `AllowMultithreading`

A UINT value that specifies whether the user-mode display driver can run multiple threads simultaneously when it processes calls to its functions from the Microsoft Direct3D runtime. For situations where the driver must disable multi-threading even when **AllowMultithreading** is set, see [Supporting Multiple Processors](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-multiple-processors).

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `AllowFlipBatching`

A UINT value that specifies whether the user-mode display driver can queue flip operation requests so the driver can process them later on another thread. This flag applies only to when a driver implements its own threading. In this situation, the driver is not required to immediately call the [pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb) function when its [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present) function is called.

The Direct3D runtime enforces a queued present limit (currently set to 1) to ensure that frame latency stays at a reasonable level. If an application initiates a call to the driver's [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present) function while another present operation is queued, the current version of the runtime will flush the queued present. However, drivers should not rely on this behavior because the queued present limit might change in future versions of the runtime.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 30 bits (0xFFFFFFFD) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDI_CREATEDEVICEFLAGS that can hold one 32-bit value that identifies how to create the device.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)