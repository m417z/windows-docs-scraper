# D3DKMT_ENUMADAPTERS2 structure

## Description

The **D3DKMT_ENUMADAPTERS2** structure is a parameter passed to [**D3DKMTEnumAdapters2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters2) to acquire information about adapters on the system.

## Members

### `NumAdapters`

[in, out] The number of adapters.

### `pAdapters`

[out, optional] Pointer to an array of [**D3DKMT_ADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo) structures in which to receive information for each adapter.

## Remarks

## See also

- [D3DKMT_ADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo)
- [D3DKMTEnumAdapters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters2)
- [PFND3DKMT_ENUMADAPTERS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_enumadapters2)