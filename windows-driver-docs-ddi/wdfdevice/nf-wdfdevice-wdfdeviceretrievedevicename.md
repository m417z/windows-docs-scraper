# WdfDeviceRetrieveDeviceName function

## Description

[Applies to KMDF only]

The **WdfDeviceRetrieveDeviceName** method returns the device name for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `String` [in]

A handle to a framework string object that receives the device name.

## Return value

If the operation succeeds, **WdfDeviceRetrieveDeviceName** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDeviceRetrieveDeviceName** method returns the device name that the driver specified in a previous call to [WdfDeviceInitAssignName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignname).

To obtain the device name string from the string object, the driver can call [WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring).

#### Examples

The following code example creates a string object and then retrieves a specified device's name.

```cpp
NTSTATUS status;
WDFSTRING string;

status = WdfStringCreate(
                         NULL,
                         WDF_NO_OBJECT_ATTRIBUTES,
                         &string
                         );
if (NT_SUCCESS(status)) {
    status = WdfDeviceRetrieveDeviceName(
                                         Device,
                                         string
                                         );
    if (!NT_SUCCESS(status)) {
        return status;
    }
}
```

## See also

[WdfDeviceInitAssignName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignname)

[WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)