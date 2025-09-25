## Description

Indicates the level of support that the adapter provides for metacommands.

## Members

### `CommandId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The fixed GUID that identifies the metacommand to query about.

### `NodeMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

For single GPU operation, this is zero. If there are multiple GPU nodes, a bit is set to identify a node (the device's physical adapter). Each bit in the mask corresponds to a single node. Only 1 bit must be set. Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `pQueryInputData`

Type:  **const [void](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a buffer containing the query input data. Allocate *QueryInputDataSizeInBytes* bytes.

### `QueryInputDataSizeInBytes`

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the buffer pointed to by *pQueryInputData*, in bytes.

### `pQueryOutputData`

Type: **[void](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a buffer containing the query output data.

### `QueryOutputDataSizeInBytes`

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the buffer pointed to by *pQueryOutputData*, in bytes.

## Remarks

## See also