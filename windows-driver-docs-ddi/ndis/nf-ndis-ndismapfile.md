# NdisMapFile function

## Description

The
**NdisMapFile** function maps an already open file into a caller-accessible buffer if the file is
currently unmapped.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of the mapping
operation, which can be one of the following:

#### NDIS_STATUS_SUCCESS

The caller has exclusive access to the file contents until the
[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile) function is called.

#### NDIS_STATUS_ALREADY_MAPPED

The caller cannot access the file contents at this time.

### `MappedBuffer` [out]

A pointer to a caller-supplied variable in which this function returns the base virtual address of
the mapped file contents or **NULL**.

### `FileHandle` [in]

The handle that was returned by a preceding call to the
[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile) function.

## Remarks

**NdisMapFile** associates (maps) a virtual address range with an opened file so the driver can access
the file contents.
**NdisMapFile** allows only one mapping of a particular file to be outstanding at any time.
Consequently, a successful caller is given exclusive access to the file data until
**NdisUnmapFile** or the
[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile) function is called.

A miniport driver can map and unmap such an open file as necessary, using alternating calls to
**NdisMapFile** and
[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile). A call to
**NdisCloseFile** releases the
*FileHandle* and deallocates the buffer containing the file contents.

A miniport driver can call
**NdisMapFile** only during initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile)

[NdisOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenfile)

[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile)