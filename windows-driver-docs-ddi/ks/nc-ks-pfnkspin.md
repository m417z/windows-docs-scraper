# PFNKSPIN callback function

## Description

An AVStream minidriver's callback routine is called when:

* There is data available for a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure to process. Use this routine to perform [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing).
* The relevant [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) is serving as a sink pin and is connected to an AVStream source pin.

## Parameters

### `Pin` [in]

Pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) that has frame data available to process.

## Return value

Return STATUS_SUCCESS to continue processing. Return STATUS_PENDING to stop processing until the next triggering event.

## Remarks

**About AVStrMiniPinProcess**

The minidriver specifies this routine's address in the **Process** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

Indicate that a filter uses [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing) by providing this dispatch function. The minidriver sets pin flags in the relevant [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) structure that determine when AVStream calls *AVStrMiniPinProcess*. If the minidriver sets no flags in the descriptor, the default behavior is that AVStream calls *AVStrMiniPinProcess* when new data arrives into a previously empty queue. See Pin-Centric Processing for more details on processing triggers.

After processing, the minidriver can prevent the frame from being completed by cloning the leading edge stream pointer. To do this, call [KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone). See [Leading and Trailing Edge Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/leading-and-trailing-edge-stream-pointers).

Alternatively, specify a distinct trailing edge by setting KSPIN_FLAG_DISTINCT_TRAILING_EDGE on [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex). A third option is not to advance the leading edge stream pointer.

The process dispatch is either made at the default IRQL = PASSIVE_LEVEL, or possibly at DISPATCH_LEVEL if the minidriver has specified KSPIN_FLAG_DISPATCH_LEVEL_PROCESSING in the relevant [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex).

This routine is optional.

**About AVStrMiniPinConnect**

The minidriver specifies this routine's address in the **Connect** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

Return STATUS_SUCCESS or the error returned from the attempt to establish an intra-connection. Do not return STATUS_PENDING.

This routine is optional.

Also see [KS Pins](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-pins).

## See also

[Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KsStreamPointerClone](https://learn.microsoft.com/windows-hardware/drivers/devtest/ks-ksstreampointerclone)

[Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing)