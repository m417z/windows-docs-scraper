# D3DKMT_ENUMADAPTERS3 structure

## Description

The **D3DKMT_ENUMADAPTERS3** structure supplies information about adapters on the system.

## Members

### `Filter` [in]

A **D3DKMT_ENUMADAPTERS_FILTER** union containing filter flags for the enumeration. The struct in **Filter** can be a bitwise OR of the following values. See Remarks for more information.

| Value | Meaning |
| ----- | ------- |
| IncludeComputeOnly | When set, enumerate ComputeOnly adapters. |
| IncludeDisplayOnly | When set, enumerate DisplayOnly adapters. |
| IncludeVirtualGpuOnly | When set, enumerate GPU-P adapters. These adapters are meant to be used only inside virtual machines. A driver sets the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)**::MiscCaps.VirtualGpuOnly** cap for such adapters to avoid their enumeration in the host OS. Available starting in Windows 11, version 24H2 (WDDM 3.2). |
| Reserved | Reserved; do not use. |

### `NumAdapters` [in/out]

The number of adapters.

On input, **NumAdapters** specifies how many adapters can be returned in the empty **pAdapters** array. Possible return values for **NumAdapters** are:

- On successful return when **pAdapters** is non-null, **NumAdapters** contains how many adapters were returned in the **pAdapters** array.
- On successful return when **pAdapters** is null, **NumAdapters** contains the maximum supported adapter count.
- On failed return when **pAdapters** is non-null, **NumAdapters** is undefined.

### `pAdapters` [out]

An optional array of [**D3DKMT_ADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo) structures in which to receive information for each adapter.

## Remarks

Adapters will still be enumerated if no flags are set in **Filter**, but [**D3DKMTEnumAdapters3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters3) will enumerate fewer adapters than [**D3DKMTEnumAdapters2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters2). Specifically, **D3DKMTEnumAdapters3** will:

- Leave out ComputeOnly adapters from the default enumeration, to avoid breaking applications.
- Leave out DisplayOnly adapters from the default enumeration.

## See also

[**D3DKMT_ADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterinfo)

[**D3DKMTEnumAdapters3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtenumadapters3)

[**PFND3DKMT_ENUMADAPTERS3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_enumadapters3)