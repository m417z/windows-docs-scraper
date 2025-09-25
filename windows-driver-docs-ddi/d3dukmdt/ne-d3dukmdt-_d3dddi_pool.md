# _D3DDDI_POOL enumeration

## Description

The D3DDDI_POOL enumeration type contains values that identify particular types of memory pool.

## Constants

### `D3DDDIPOOL_SYSTEMMEM`

Resources exist in system memory.

### `D3DDDIPOOL_VIDEOMEMORY`

Resources exist in display memory.

### `D3DDDIPOOL_LOCALVIDMEM`

Resources exist in true, local display memory rather than nonlocal display memory (for example, AGP memory).

### `D3DDDIPOOL_NONLOCALVIDMEM`

Resources exist in nonlocal display memory (for example, AGP memory) rather than true, local display memory.

### `D3DDDIPOOL_STAGINGMEM`

Resources exist in staging memory that the user-mode display driver has allocated. This value indicates to the driver that it should allocate its own staging memory rather than use allocated Direct3D 10Level 9 memory.

Must be supported by WDDM 1.3 and later drivers. Available starting with Windows 8.1.

## Remarks

Pool memory types are defined as an enumeration type rather than separate flags because the types are all mutually exclusive.

Note that the D3DDDIPOOL_LOCALVIDMEM and D3DDDIPOOL_NONLOCALVIDMEM values are provided as hints to the user-mode display driver so it can improve performance. For more information about these values, see [Specifying Memory Type for a Resource](https://learn.microsoft.com/windows-hardware/drivers/display/specifying-memory-type-for-a-resource).

## See also

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)