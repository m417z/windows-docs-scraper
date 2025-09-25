# WdfPdoRequestEject function

## Description

[Applies to KMDF only]

The **WdfPdoRequestEject** method informs the framework that a specified device is about to be ejected from its docking station.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the device's physical device object (PDO).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A bus driver can call **WdfPdoRequestEject** or [WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject) to report that the driver has detected an attempt to eject one of its enumerated child devices from the device's docking station. For example, the driver might detect that a user has pushed an eject button.

If the framework device object for the device's PDO is available, the driver can call **WdfPdoRequestEject**. If the driver is using dynamic bus enumeration and if the device's identification description is available, the driver can call [WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject).

For more information about **WdfPdoRequestEject** and [WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject), see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

#### Examples

The following code example searches a list of child devices to find one that matches a specified serial number. When the example finds the correct child, it calls **WdfPdoRequestEject** to indicate that the child is being ejected. This example was taken from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample bus driver and simplified.

```cpp
WDFDEVICE  hChild = NULL;
NTSTATUS  status = STATUS_INVALID_PARAMETER;
PPDO_DEVICE_DATA  pdoData;

WdfFdoLockStaticChildListForIteration(Device);

while ((hChild = WdfFdoRetrieveNextStaticChild(
                                               Device,
                                               hChild,
                                               WdfRetrieveAddedChildren
                                               )) != NULL) {
    //
    // Obtain device object context space, and check the
    // stored serial number.
    //
    pdoData = PdoGetData(hChild);
    if (SerialNo == pdoData->SerialNo) {
        status = STATUS_SUCCESS;
        WdfPdoRequestEject(hChild);
    }
}
WdfFdoUnlockStaticChildListFromIteration(Device);
```

## See also

[WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration)

[WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild)

[WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration)