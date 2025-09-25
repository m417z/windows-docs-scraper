# WdfFdoAddStaticChild function

## Description

[Applies to KMDF only]

The **WdfFdoAddStaticChild** method adds a specified device to a function driver's list of child devices that have been identified by static enumeration.

## Parameters

### `Fdo` [in]

A handle to a framework device object that represents the parent device.

### `Child` [in]

A handle to a framework device object that represents the child device.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *Fdo* is not a handle to a function driver's device object. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers that use static bus enumeration can call **WdfFdoAddStaticChild**. For more information about static child lists, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

If **WdfFdoAddStaticChild** returns an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**, the driver must call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to delete the framework device object that represents the child device. The driver must not delete the framework device object after **WdfFdoAddStaticChild** returns STATUS_SUCCESS.

#### Examples

The following code example creates a framework device object that represents a new child device and adds the child device to the parent device's list of children. For the complete code example, see the [KbFiltr](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver.

```cpp
NTSTATUS  status;
PWDFDEVICE_INIT  pDeviceInit = NULL;
WDFDEVICE  hChild = NULL;
WDF_OBJECT_ATTRIBUTES  pdoAttributes;

pDeviceInit = WdfPdoInitAllocate(Device);
if (pDeviceInit == NULL) {
    status = STATUS_INSUFFICIENT_RESOURCES;
    goto Cleanup;
}
...
status = WdfDeviceCreate(
                         &pDeviceInit,
                         &pdoAttributes,
                         &hChild
                         );
if (!NT_SUCCESS(status)) {
    WdfDeviceInitFree(pDeviceInit);
    pDeviceInit = NULL;
    goto Cleanup;
}
...
status = WdfFdoAddStaticChild(
                              Device,
                              hChild
                              );
if (!NT_SUCCESS(status)) {
    goto Cleanup;
}
```

## See also

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate)