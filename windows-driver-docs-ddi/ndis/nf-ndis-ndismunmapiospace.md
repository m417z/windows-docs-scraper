# NdisMUnmapIoSpace function

## Description

**NdisMUnmapIoSpace** releases a virtual range mapped by an initialization-time call to [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle originally input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `VirtualAddress` [in]

Specifies the base virtual address for the mapped range that was returned by
**NdisMMapIoSpace**.

### `Length` [in]

Specifies the number of bytes in the range that was mapped with
**NdisMMapIoSpace**.

## Remarks

When a miniport driver is unloading, any memory range that it mapped during initialization with [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace) must be released with a
call to
**NdisMUnmapIoSpace**.

The
*Length* passed to
**NdisMUnmapIoSpace** must match the
*Length* originally passed to
**NdisMMapIoSpace**.

**NdisMUnmapIoSpace** can be called only from a miniport driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) and
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) functions.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)