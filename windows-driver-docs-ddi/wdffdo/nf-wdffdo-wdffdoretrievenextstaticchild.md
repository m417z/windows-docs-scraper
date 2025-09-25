# WdfFdoRetrieveNextStaticChild function

## Description

[Applies to KMDF only]

The **WdfFdoRetrieveNextStaticChild** method retrieves a handle to the next framework device object in a list of child devices.

## Parameters

### `Fdo` [in]

A handle to a framework device object that represents the parent device.

### `PreviousChild` [in, optional]

A handle to a framework device object that represents the child device that was returned by a previous call to **WdfFdoRetrieveNextStaticChild**. For the first call to **WdfFdoRetrieveNextStaticChild**, this value must be **NULL**.

### `Flags` [in]

A [WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)-typed enumerator value that identifies the type of child devices that the method should retrieve. This parameter cannot be zero.

## Return value

If the operation succeeds, the method returns a handle to a framework device object. Otherwise it returns **NULL**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Bus drivers that use static bus enumeration can call **WdfFdoRetrieveNextStaticChild**.

To retrieve the items in a list of child devices, the driver should:

1. Call [WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration) to lock the child list.
2. Repeatedly call **WdfFdoRetrieveNextStaticChild** to obtain the items in the list, one at a time, until the method returns **NULL**.
3. Call [WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration) to unlock the child list.

For more information about static child lists, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

#### Examples

The following code example searches a static child list until it finds a child device with a serial number that matches a specific value. For other example uses of **WdfFdoRetrieveNextStaticChild**, see the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample bus driver.

```cpp
PPDO_DEVICE_DATA  pdoData;
WDFDEVICE  hChild;
NTSTATUS  status = STATUS_INVALID_PARAMETER;

WdfFdoLockStaticChildListForIteration(Device);

while ((hChild = WdfFdoRetrieveNextStaticChild(
                                               Device,
                                               hChild,
                                               WdfRetrieveAddedChildren
                                               )) != NULL) {
    //
    // Obtain device object context data and check the
    // stored serial number.
    //
    pdoData = PdoGetData(hChild);
    if (SerialNo == pdoData->SerialNo) {
        status = STATUS_SUCCESS;
        WdfPdoRequestEject(hChild);
        break;
    }
}
WdfFdoUnlockStaticChildListFromIteration(Device);
```

## See also

[WdfFdoLockStaticChildListForIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdolockstaticchildlistforiteration)

[WdfFdoUnlockStaticChildListFromIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdounlockstaticchildlistfromiteration)