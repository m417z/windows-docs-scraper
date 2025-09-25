# RxLowIoCompletion function

## Description

**RxLowIoCompletion** must be called by the network mini-redirector low I/O routines when they complete, if the low I/O routines have initially returned STATUS_PENDING.

## Parameters

### `RxContext`

A pointer to the RX_CONTEXT structure for this IRP.

## Return value

**RxLowIoCompletion**
returns different values depending on whether the *RxContext* parameter indicates this is synchronous or asynchronous I/O.

If the *RxContext* parameter indicates this is synchronous I/O, then **RxLowIoCompletion** returns STATUS_MORE_PROCESSING_REQUIRED.

If the *RxContext* parameter indicates this is asynchronous I/O, then **RxLowIoCompletion** will try to call the **LowIoContext.CompletionRoutine** member of the RX_CONTEXT. The completion routine will only be called if the **LowIoContext.Flags**member indicates that the completion routine can be called at DPC level and the current IRQL is less than dispatch level. In this case, the return value is the result returned by the completion routine. If these conditions are not met, then **RxLowIoCompletion** returns STATUS_MORE_PROCESSING_REQUIRED.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxLowIoGetBufferAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiogetbufferaddress)

[RxMapSystemBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxmapsystembuffer)

[RxNewMapUserBuffer](https://learn.microsoft.com/windows-hardware/drivers/ifs/rxnewmapuserbuffer)