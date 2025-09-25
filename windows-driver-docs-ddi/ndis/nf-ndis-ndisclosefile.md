# NdisCloseFile function

## Description

The
**NdisCloseFile** function releases a handle returned by the
[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile) function and frees the memory
allocated to hold the file contents when it was opened.

## Parameters

### `FileHandle` [in]

The handle that was returned in a preceding call to the
[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile) function.

## Remarks

For miniport drivers, calls to this function are valid only during initialization. If the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
calls the
[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile) function, it must call
**NdisCloseFile** before it returns control.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismapfile)

[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile)

[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile)