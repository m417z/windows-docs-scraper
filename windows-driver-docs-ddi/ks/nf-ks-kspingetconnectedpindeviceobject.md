# KsPinGetConnectedPinDeviceObject function

## Description

The **KsPinGetConnectedPinDeviceObject** function returns the device object at the top of the device stack corresponding to the sink pin attached to the source pin *Pin*.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that is the source pin for which to obtain the connected sink pin's device object.

## Return value

If *Pin* is a source pin, **KsPinGetConnectedPinDeviceObject** returns a pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure at the top of the device stack on which the sink pin resides. Otherwise, it returns **NULL**.

## Remarks

The returned device object is not necessarily the functional device object (FDO) for the device on which the sink resides, since there might exist an upper level filter driver. It is, however, the device object to which IOCTLs destined for the sink pin are sent.

## See also

[KsGetDeviceForDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevicefordeviceobject)