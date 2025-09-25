# WdfIoTargetQueryTargetProperty function

## Description

[Applies to KMDF only]

The **WdfIoTargetQueryTargetProperty** method retrieves a specified device property for a specified I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed value that identifies the device property to be retrieved.

### `BufferLength` [in]

The size, in bytes, of the buffer that *PropertyBuffer* points to.

### `PropertyBuffer` [out, optional]

A pointer to a caller-allocated buffer that receives the requested device property information. This pointer can be **NULL** if *BufferLength* is zero.

### `ResultLength` [out]

A pointer to a location that, on return, contains the size, in bytes, of the information that **WdfIoTargetQueryTargetProperty** stored in the buffer that *PropertyBuffer* points to. If **WdfIoTargetQueryTargetProperty** returns STATUS_BUFFER_TOO_SMALL, this location receives the required buffer size.

## Return value

**WdfIoTargetQueryTargetProperty** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *PropertyBuffer* parameter pointed to was too small to receive the requested information. |
| **STATUS_INVALID_PARAMETER_2** | The value that the *DeviceProperty* parameter specified was invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The device's drivers have not yet reported the device's properties. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before drivers receive device property data, they typically call the **WdfIoTargetQueryTargetProperty** method to obtain the required buffer size. For some properties, the data size can change between when the required size is returned and when the driver calls **WdfIoTargetQueryTargetProperty** again. Therefore, drivers should call **WdfIoTargetQueryTargetProperty** inside a loop that executes until the return status is not STATUS_BUFFER_TOO_SMALL.

Instead of calling **WdfIoTargetQueryTargetProperty**, your driver can call [WdfIoTargetAllocAndQueryTargetProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetallocandquerytargetproperty), which allocates a buffer and places the property information in the buffer.

For more information about **WdfIoTargetQueryTargetProperty**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example obtains a device's **DevicePropertyUINumber** property. The example calls **WdfIoTargetQueryTargetProperty** instead of [WdfIoTargetAllocAndQueryTargetProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetallocandquerytargetproperty) because the length of a UI number is known.

```cpp
ULONG targetUINumber, resultLength;
NTSTATUS status;

status = WdfIoTargetQueryTargetProperty(
                                        target,
                                        DevicePropertyUINumber,
                                        sizeof(targetNumber),
                                        &targetUINumber,
                                        &resultLength
                                        );
```

## See also

[DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfDeviceQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryproperty)

[WdfIoTargetAllocAndQueryTargetProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetallocandquerytargetproperty)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)