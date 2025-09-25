# D3DKMT_ADAPTERINFO structure

## Description

Supplies information about an adapter.

## Members

### `hAdapter`

A handle to the adapter.

### `AdapterLuid`

A LUID value that uniquely identifies the adapter, typically until the operating system is rebooted. The LUID value changes whenever:

- the system is rebooted
- the adapter's driver is updated
- the adapter is disabled
- the adapter is disconnected

### `NumOfSources`

The number of video present sources supported by the adapter.

### `bPrecisePresentRegionsPreferred`

If **TRUE**, the adapter prefers precise present regions.

## See also

[**D3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2)