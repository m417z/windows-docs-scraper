# _D3DKMT_ENUMADAPTERS structure

## Description

Supplies information for enumerating all graphics adapters on the system.

## Members

### `NumAdapters` [in]

The number of graphics adapters.

### `Adapters`

An array of [D3DKMT_ADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo) structures that supply configuration information for each adapter. The maximum number of adapters that can be enumerated is 16.

## See also

[D3DKMT_ADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo)