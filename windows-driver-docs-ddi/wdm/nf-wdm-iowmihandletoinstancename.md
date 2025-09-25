# IoWMIHandleToInstanceName function

## Description

The **IoWMIHandleToInstanceName** routine determines the instance name for the WMI class instance implemented by the driver that is specified by a file handle.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine.

### `FileHandle` [in]

Specifies a file handle. The routine returns the instance name corresponding to the driver that is represented by the file handle.

### `InstanceName` [out]

Pointer to the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that the routine uses to return the instance name. The caller frees the returned buffer within **UNICODE_STRING**.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine fills the **UNICODE_STRING** structure pointed to by the *InstanceName* parameter with the instance name. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | The driver does not implement any instances of the WMI class specified by *DataBlockObject*. |

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoWMIDeviceObjectToInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoinstancename)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)