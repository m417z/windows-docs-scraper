# KsPinGetDevice function

## Description

The **KsPinGetDevice** function returns the AVStream device to which *Pin* belongs.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the pin for which to return the owning AVStream device.

## Return value

**KsPinGetDevice** returns a pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the AVStream device to which *Pin* belongs.

## Remarks

This call is an inline function call to [KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice)