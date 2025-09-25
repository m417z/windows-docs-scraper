# KsGateCaptureThreshold function

## Description

The **KsGateCaptureThreshold** function is used to capture an ON input of an AND gate specified by *Gate*.

## Parameters

### `Gate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the AND gate for which to capture an ON input synchronously.

## Return value

**KsGateCaptureThreshold** returns **TRUE** if the AND gate was originally open. Note that returning **TRUE** implies that the gate was closed so that no other thread could simultaneously capture the gate and commence processing.

## Remarks

**KsGateCaptureThreshold** checks the state of the given AND gate. If the gate is open, it turns off an input to the gate, thereby transitioning the gate to a closed state. If the gate is closed, the function does nothing. Unlike **KsGateGetStateUnsafe**, this call is done synchronously with respect to other gate state changes. It is the primary synchronization mechanism for processing based on gate control.

Despite its name, this function is only a valid call for AND gates, not gates in general. AVStream, however, does not verify whether *Gate* is an AND gate or an OR gate. It is the caller's responsibility to ensure that the call is only made on AND gates.

The call is made using interlocked functions and is thus synchronous with respect to any of the other gate state change functions; it is also a very efficient method of process control.

## See also

[KsGateAddOffInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoand)

[KsGateAddOffInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoffinputtoor)

[KsGateAddOnInputToAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoand)

[KsGateAddOnInputToOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateaddoninputtoor)

[KsGateGetStateUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgategetstateunsafe)

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)

[KsGateRemoveOffInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromand)

[KsGateRemoveOffInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoffinputfromor)

[KsGateRemoveOnInputFromAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromand)

[KsGateRemoveOnInputFromOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateremoveoninputfromor)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)