# KsPinRegisterIrpCompletionCallback function

## Description

The **KsPinRegisterIrpCompletionCallback** function registers a minidriver-defined callback routine for a specified pin. AVStream calls the minidriver-provided routine when an IRP completes a pass around the circuit and the frame that is associated with the IRP is about to be recycled or retired.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to register a completion callback.

### `IrpCompletion` [in]

This parameter supplies the address of a [AVStrMiniPinIrpCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinirpcompletion) routine to be called when an IRP completes its traversal of the circuit and is about to be recycled or retired.

## Remarks

**KsPinRegisterIrpCompletionCallback** must be called at IRQL=PASSIVE_LEVEL before the pin goes into KSSTATE_ACQUIRE. For more information about pin states, see [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate).

This function is frequently called from the pin creation dispatch. See [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

**KsPinRegisterIrpCompletionCallback** is only useful on IRP source pins, and is typically used on data source pins. For a data source pin, the callback is made once the IRP is completed back to the pin and is about to be recycled. For a data sink pin, however, the callback is not tied directly to IRP completion. AVStream still makes the callback when the IRP returns for recycling. This return does not occur until that IRP has passed through all the queues that need to use the data that it contains. For information about IRP source/sink pins versus data source/sink pins, see the **DataFlow** and **Communication** members of the [KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor) structure.

**KsPinRegisterIrpCompletionCallback** differs significantly from [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback) in that this routine does not place the pin in any new mode; it simply registers a callback routine.

## See also

[AVStrMiniPinCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinirp)

[AVStrMiniPinIrpCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinirpcompletion)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)

[KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback)