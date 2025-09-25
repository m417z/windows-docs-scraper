# KsPinGetAndGate function

## Description

The **KsPinGetAndGate** function returns the processing control gate for *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) for which to return the processing control gate.

## Return value

Returns a pointer to the [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) representing the processing control gate for *Pin*.

## Remarks

For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsFilterGetAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetandgate)