# IoWMIDeviceObjectToInstanceName function

## Description

The **IoWMIDeviceObjectToInstanceName** routine determines the instance name for the WMI class instance implemented by the driver that is specified by a device object.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock).

### `DeviceObject` [in]

Specifies a device object. The routine returns the instance name for the driver corresponding to the device object.

### `InstanceName` [out]

Pointer to the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that the routine uses to return the instance name. The caller frees the returned buffer within **UNICODE_STRING**.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine stores the instance name in the **UNICODE_STRING** specified by the *InstanceName* parameter. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | The driver does not implement any instances of the WMI class specified by *DataBlockObject*. |

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoWMIHandleToInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmihandletoinstancename)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)