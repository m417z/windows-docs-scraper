# EVT_UFX_DEVICE_TEST_MODE_SET callback function

## Description

The client driver's implementation to set the test mode of the function controller.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

Test mode selector value as defined by the USB 2.0 Specification. These values are defined in usbfnbase.h

* USB_TEST_MODE_TEST_J 0x01
* USB_TEST_MODE_TEST_K 0x02
* USB_TEST_MODE_TEST_SE0_NAK 0x03
* USB_TEST_MODE_TEST_PACKET 0x04
* USB_TEST_MODE_TEST_FORCE_ENABLE 0x05

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_TEST_MODE_SET* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```
EVT_UFX_DEVICE_TEST_MODE_SET UfxDevice_EvtDeviceTestModeSet;

VOID
UfxDevice_EvtDeviceTestModeSet (
    _In_ UFXDEVICE UfxDevice,
    _In_ ULONG TestMode
    )
/*++

Routine Description:

    EvtDeviceTestModeSet handler for the UFXDEVICE object.

    Handles a set test mode request from the host.  Places the controller into
    the specified test mode.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    TestMode - Test mode value.  See Section 7.1.20 of the USB 2.0 specification for definitions of
               each test mode.

--*/
{
    NTSTATUS Status;

    UNREFERENCED_PARAMETER(TestMode);

    TraceEntry();

    //
    // #### TODO: Insert code to put the controller into the specified test mode ####
    //

    Status = STATUS_SUCCESS;

    UfxDeviceEventComplete(UfxDevice, Status);
    TraceExit();
}

```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)