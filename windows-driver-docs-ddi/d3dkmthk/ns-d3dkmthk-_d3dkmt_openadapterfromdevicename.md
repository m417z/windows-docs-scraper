# _D3DKMT_OPENADAPTERFROMDEVICENAME structure

## Description

The D3DKMT_OPENADAPTERFROMDEVICENAME structure describes the mapping of the given name of a device to a graphics adapter handle and monitor output.

## Members

### `pDeviceName` [in]

A Null-terminated string that contains the name of the device from which to open an adapter instance.

### `hAdapter` [out]

A handle to the graphics adapter for the device that **pDeviceName** specifies. The adapter handle is returned from the call to the [D3DKMTOpenAdapterFromDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromdevicename) function.

### `AdapterLuid` [out]

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) of the graphics adapter for the device that **pDeviceName** specifies. The LUID is returned from the [D3DKMTOpenAdapterFromDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromdevicename) call.

## See also

[D3DKMTOpenAdapterFromDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromdevicename)