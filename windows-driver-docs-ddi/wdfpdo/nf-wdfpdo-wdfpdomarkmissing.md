# WdfPdoMarkMissing function

## Description

[Applies to KMDF only]

The **WdfPdoMarkMissing** method informs the framework that a device is no longer accessible.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the device's physical device object (PDO).

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *Device* handle does not represent a PDO. |
| **STATUS_NO_SUCH_DEVICE** | The device object could not be found. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about **WdfPdoMarkMissing**, see [Static Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/static-enumeration).

#### Examples

The following code example searches a list of child devices to find one that matches a specified serial number. When the example finds the correct child, it calls **WdfPdoMarkMissing** to indicate that the child is not accessible. This example was taken from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample bus driver and simplified.

```cpp
WDFDEVICE  hChild = NULL;
NTSTATUS  status = STATUS_INVALID_PARAMETER;
BOOLEAN  found = FALSE;
PPDO_DEVICE_DATA  pdoData;

WdfFdoLockStaticChildListForIteration(Device);

while ((hChild = WdfFdoRetrieveNextStaticChild(
                                               Device,
                                               hChild,
                                               WdfRetrieveAddedChildren
                                               )) != NULL) {
    pdoData = PdoGetData(hChild);  // Device object context space
    if (SerialNo == pdoData->SerialNo) {
        status = WdfPdoMarkMissing(hChild);
        if(!NT_SUCCESS(status)) {
            KdPrint(("WdfPdoMarkMissing failed 0x%x\n", status));
            break;
        }
        found = TRUE;
        break;
    }
}
WdfFdoUnlockStaticChildListFromIteration(Device);
```

## See also

[WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration)

[WdfFdoRetrieveNextStaticChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoretrievenextstaticchild)

[WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration)