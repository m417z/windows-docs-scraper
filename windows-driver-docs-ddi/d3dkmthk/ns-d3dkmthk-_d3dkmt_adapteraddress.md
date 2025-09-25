# _D3DKMT_ADAPTERADDRESS structure

## Description

The D3DKMT_ADAPTERADDRESS structure describes the physical location of the graphics adapter.

## Members

### `BusNumber` [out]

The number of the bus that the graphics adapter's physical device is located on.

### `DeviceNumber` [out]

The index of the graphics adapter's physical device on the bus.

### `FunctionNumber` [out]

The function number of the graphics adapter on the physical device.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)