# NdisZeroMappedMemory macro

## Description

**NdisZeroMappedMemory** fills a block of memory that was mapped with a preceding call to
**NdisMMapIoSpace** with zeros.

## Parameters

### `Destination` [in]

Specifies the base virtual address of a block of mapped memory.

### `Length` [in]

Specifies the number of bytes to be filled with zeros.

## Remarks

A miniport driver can call
**NdisZeroMappedMemory** to zero-initialize mapped device memory. The given
*Destination* and
*Length* must be a proper subrange of the range specified when the driver called [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

**NdisZeroMappedMemory** is optimized, and a miniport driver can call this function any time that it
needs to clear a mapped memory range.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiszeromemory)