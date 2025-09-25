# NdisUnmapFile function

## Description

The
**NdisUnmapFile** function releases a virtual address mapping of a file previously set up with the
[NdisMapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismapfile) function.

## Parameters

### `FileHandle` [in]

The handle that was returned by the
[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile) function.

## Remarks

To reduce resource usage, a miniport driver should always call
**NdisUnmapFile** when it no longer needs exclusive access to the contents of a file that it opened.
Such a driver can map and unmap the file as necessary, using alternating calls to
**NdisMapFile** and
**NdisUnmapFile** until it releases the file handle with the
[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile) function.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile)

[NdisMapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismapfile)

[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile)