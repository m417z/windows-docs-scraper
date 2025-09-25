# D3DKMT_SEGMENTGROUPSIZEINFO structure

## Description

The **D3DKMT_SEGMENTGROUPSIZEINFO** structure holds information about the segment group size.

## Members

### `PhysicalAdapterIndex`

The physical adapter index in the LDA (linked display adapter) chain.

### `LegacyInfo`

A [**D3DKMT_SEGMENTSIZEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_segmentsizeinfo) structure that holds legacy segment size info.

### `LocalMemory`

Size of the local memory, in bytes.

### `NonLocalMemory`

Size of non-local memory, in bytes.

### `NonBudgetMemory`

Size of [non-budget memory](https://learn.microsoft.com/windows-hardware/drivers/display/process-residency-budgets).

## See also

[**D3DKMT_SEGMENTSIZEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_segmentsizeinfo)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)