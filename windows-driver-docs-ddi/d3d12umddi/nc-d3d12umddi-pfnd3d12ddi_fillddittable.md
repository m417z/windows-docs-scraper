# PFND3D12DDI_FILLDDITTABLE callback function

## Description

The **PFND3D12DDI_FILLDDITTABLE** callback function retrieves a list of function pointers implemented by the user-mode driver.

## Parameters

### `unnamedParam1` [in]

**hAdapter** is the handle to the graphics adapter object.

### `unnamedParam2` [in]

**tableType** is a [**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type) value that indicates the type of function pointers to retrieve.

### `unnamedParam3` [in/out]

**pTable** is a pointer to the returned table of callback functions that define the queried implementation.

### `unnamedParam4` [in]

**tableSize** is the size of the table pointed to by **pTable**, in bytes.

### `unnamedParam5` [in]

**tableNum** is the table index.

### `unnamedParam6` [in, optional]

**hHandle** is a D3D12DDI_HRTTABLE handle.

## Return value

Returns an [**HRESULT**](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) value.

## See also

[**D3DDDI_ADAPTERFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs)

[**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type)