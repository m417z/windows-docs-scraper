# PFNKSPINIRPCOMPLETION callback function

## Description

An AVStream minidriver's *AVStrMiniPinIrpCompletion* routine is called when an IRP completes a pass around the circuit and the frame that is associated with the IRP is about to be recycled or retired.

## Parameters

### `Pin` [in]

Points to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which the callback is registered.

### `Irp` [in]

Points to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) which originated from the circuit to which *Pin* belongs.

## Remarks

The minidriver specifies this routine's address in the *IrpCompletion* parameter of a call to [KsPinRegisterIrpCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterirpcompletioncallback).

## See also

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsPinRegisterIrpCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterirpcompletioncallback)