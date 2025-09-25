# D3DKMT_CREATESTANDARDALLOCATION structure

## Description

The **D3DKMT_CREATESTANDARDALLOCATION** structure is used to create a standard allocation.

## Members

### `Type`

A [**D3DKMT_STANDARDALLOCATIONTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_standardallocationtype) value that indicates the type of the standard allocation.

### `ExistingHeapData`

A [**D3DKMT_STANDARDALLOCATION_EXISTINGHEAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_standardallocation_existingheap) structure that holds information about the existing heap.

### `Flags`

A [**D3DKMT_CREATESTANDARDALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createstandardallocationflags) structure that holds the flags to use to create a standard allocation.

## See also

[**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation)

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)