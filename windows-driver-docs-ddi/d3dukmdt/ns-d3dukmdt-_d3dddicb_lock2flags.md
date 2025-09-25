# _D3DDDICB_LOCK2FLAGS structure

## Description

**D3DDDICB_LOCK2FLAGS** is used by the [Lock2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock2) kernel function to determine how an allocation is locked.
Unlike [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock), which supported numerous flags, [Lock2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock2) has none. The **Lock2** arguments allow flags to be specified using this structure, but currently it only has a reserved field to allow for capabilities to added in the future.

## Members

### `Reserved`

This member is reserved and must be zero.

### `Value`

This member must be zero.

## See also

[Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock)

[Lock2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock2)