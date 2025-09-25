## Description

An AVStream minidriver's *AVStrMiniFrameReturn* routine is called when an injected frame has completed its trip around the circuit and is ready to be recycled or freed.

## Parameters

### `Pin` [in]

Pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the pin on which the frame was injected.

### `Data` [in, optional]

Pointer to the buffer originally specified in the call to [KsPinSubmitFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframe).

### `Size` [in, optional]

Specifies the size in bytes of*Data* as originally specified in [KsPinSubmitFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframe).

### `Mdl` [in, optional]

Pointer to a memory descriptor list describing the injected frame as in the call to [KsPinSubmitFrameMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframemdl).

### `Context` [in, optional]

Pointer to the minidriver-supplied context buffer attached to the frame when the frame was injected into the circuit.

### `Status` [in]

Contains a copy of*Irp->IoStatus.Status* for the IRP to which the requested frame was attached.

## Remarks

The minidriver specifies this routine's address in the*FrameReturn* parameter of a call to [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback).

## See also

[KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback)

[KsPinSubmitFrameMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframemdl)