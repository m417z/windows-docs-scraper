# WdfDeviceAssignProperty function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceAssignProperty** method modifies the current setting of a device property.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceProperty` [in]

A pointer to a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure that identifies the device property to modify.

### `Type` [in]

A **DEVPROPTYPE**-typed variable that specifies the type of the data stored in *Data*.

### `Size` [in]

The size, in bytes, of the buffer that is pointed to by *Data*.

### `Data` [in, optional]

A pointer to a caller-allocated buffer that contains the device property data. Set this parameter to **NULL** to delete the specified property.

## Return value

If the operation succeeds, **WdfDeviceAssignProperty** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters is incorrect. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

You can use **WdfDeviceAssignProperty** to modify the setting of any property that is exposed through the unified property model.

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)