# PFND3D12DDI_CREATEHEAPANDRESOURCE_0030 callback function

## Description

A user-mode display driver's **PFND3D12DDI_CREATEHEAPANDRESOURCE_0030** function simultaneously creates a heap and resource.

## Parameters

### `unnamedParam1`

A **D3D12DDI_HDEVICE** handle to the display device (graphics context).

### `unnamedParam2`

A [**D3D12DDIARG_CREATEHEAP_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createheap_0001) structure with arguments used to create a heap.

### `unnamedParam3`

A **D3D12DDI_HHEAP** handle to a heap.

### `unnamedParam4`

The **D3D12DDI_HRTRESOURCE** handle of the resource for the driver to use when it calls back into the runtime.

### `unnamedParam5`

Pointer to a [**D3D12DDIARG_CREATERESOURCE_0003**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0003) structure containing the arguments used to create a resource.

### `unnamedParam6`

Pointer to a [**D3D12DDI_CLEAR_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_clear_values) structure with values used to optimize clear operations for the resource.

### `unnamedParam7`

A **D3D12DDI_HPROTECTEDRESOURCESESSION_0030** handle to the protected resource session to use for the resource being created. Zero indicates unprotected resources. See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

### `unnamedParam8`

The **D3D12DDI_HRESOURCE** handle to the hardware resource.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[**D3D12DDI_CLEAR_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_clear_values)