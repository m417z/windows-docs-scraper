# KsFilterGetAndGate function

## Description

The **KsFilterGetAndGate** function returns *Filter*'s AND gate.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to acquire the corresponding AND gate.

## Return value

**KsFilterGetAndGate** returns *Filter*'s AND gate as a pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure.

## Remarks

A minidriver can use AND gates on a filter as a processing control mechanism for that filter.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateCaptureThreshold](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgatecapturethreshold)

[KsGateTurnInputOff](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputoff)

[KsGateTurnInputOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateturninputon)

[KsPinAttachAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattachandgate)

[KsPinGetAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetandgate)