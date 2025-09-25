# _D3DKMT_OPENADAPTERFROMLUID structure

## Description

Describes the mapping of the given locally unique identifier (LUID) of a device to a graphics adapter handle.

## Members

### `AdapterLuid`

 [in] A LUID that serves as an identifier for the device. **LUID** is defined in Dxgi.h.

### `hAdapter` [out]

A handle to the graphics adapter for the device that the **AdapterLuid** member specifies. The adapter handle is returned from a call to the [D3DKMTOpenAdapterFromLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromluid) function.

## See also

[D3DKMTOpenAdapterFromLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromluid)