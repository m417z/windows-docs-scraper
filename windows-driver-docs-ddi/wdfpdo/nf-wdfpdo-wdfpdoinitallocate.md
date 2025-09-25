# WdfPdoInitAllocate function

## Description

[Applies to KMDF only]

The **WdfPdoInitAllocate** method allocates a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure for a framework-based bus driver, which the bus driver uses when reporting a new device.

## Parameters

### `ParentDevice` [in]

A handle to a framework device object that represents the parent device of the new device. The framework device object must represent a functional device object (FDO).

## Return value

If the operation succeeds, the method returns a pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure. Otherwise, the method returns **NULL**.

## Remarks

If a bus driver uses static enumeration, it reports a new device by:

1. Calling **WdfPdoInitAllocate** to allocate a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.
2. Calling [framework device object initialization methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) and [framework PDO initialization methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/), as needed, to initialize the WDFDEVICE_INIT structure. If a call to one of these methods fails, the driver must call [WdfDeviceInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree).
3. Calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create a framework device object, supplying the initialized WDFDEVICE_INIT structure as input.

For more information about static enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

#### Examples

For a code example that uses **WdfPdoInitAllocate**, see [WdfFdoAddStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoaddstaticchild).

## See also

[WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate)