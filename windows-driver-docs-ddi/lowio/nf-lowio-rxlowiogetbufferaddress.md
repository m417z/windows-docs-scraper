# RxLowIoGetBufferAddress function

## Description

**RxLowIoGetBufferAddress** returns the buffer corresponding to the MDL from LowIoContext structure of an RX_CONTEXT structure.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure for this request.

## Return value

**RxLowIoGetBufferAddress **returns a mapped address pointer on success or a **NULL** on failure.

## Remarks

**RxLowIoGetBufferAddress** checks that the **ParamsFor.ReadWrite.ByteCount** member of the **LowIoContext** member of the *RxContext* variable is greater than zero and returns a **NULL** pointer if this is not the case.

**RxLowIoGetBufferAddress** calls **MmGetSystemAddressForMdlSafe** to retrieve the mapped address.

## See also

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer)

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxLowIoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiocompletion)

[RxMapSystemBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxmapsystembuffer)

[RxNewMapUserBuffer](https://learn.microsoft.com/windows-hardware/drivers/ifs/rxnewmapuserbuffer)