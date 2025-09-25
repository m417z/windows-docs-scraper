# KsPinGetCopyRelationships function

## Description

The **KsPinGetCopyRelationships** function returns copy relationship information for a pin that is contained within a [pin-centric](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing) filter.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure from which you want to acquire copy information.

### `CopySource` [out]

A pointer to a pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that is the copy source for *Pin*. If *Pin* is the copy source, AVStream sets this parameter to **NULL**.

### `DelegateBranch` [out]

A pointer to a pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that is the pin from which *Pin* receives delegated frames. If *Pin* is the delegator, AVStream sets this parameter to **NULL**.

## Remarks

[Filter-centric](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) filters receive similar *CopySource* and *DelegateBranch* information when AVStream calls the minidriver's [AVStrMiniFilterProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfilterprocess) function with an array of [KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry) structures.

The only difference is that **KsPinGetCopyRelationships** returns pointers to PKSPIN rather than pointers to PKSPROCESSPIN. For more information about the *CopySource* and *DelegateBranch* parameters, see [AVStream Splitters](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-splitters).

All pins operate independently in the context of a pin-centric filter. As a result, a minidriver that calls **KsPinGetCopyRelationships** is responsible for ensuring that the appropriate synchronization is performed before call time.

To guarantee safety when calling **KsPinGetCopyRelationships**, either obtain the control mutex (do not use this mechanism in a processing dispatch) or make sure that the pin does not transition below **KSSTATE_PAUSE** while calling or using the information obtained. For more information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

For more information, see [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing) and [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

## See also

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPROCESSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin)