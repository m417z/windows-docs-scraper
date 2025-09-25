# FltEnumerateInstanceInformationByDeviceObject function

## Description

The **FltEnumerateInstanceInformationByDeviceObject** routine provides information about minifilter driver instances and legacy filter drivers that are attached to the volume related to a specified device object.

## Parameters

### `DeviceObject` [in]

The device object for the related file object or volume.

### `Index` [in]

Zero-based index of the minifilter driver instance or legacy filter driver for which the information is requested.

### `InformationClass` [in]

Type of information to be returned for the minifilter driver instance or legacy filter driver. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceFullInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstancePartialInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for a minifilter driver instance or legacy filter driver. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateInstanceInformationByDeviceObject** returns **STATUS_BUFFER_TOO_SMALL** and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateInstanceInformationByDeviceObject** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter instance was found, but it is being torn down. Note that this return value does not apply to legacy filter drivers because legacy filter drivers cannot be unloaded. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the volume's instance/filter list. |
| **STATUS_FLT_VOLUME_NOT_FOUND** | No related volume was found for *DeviceObject*. |
| **STATUS_FLT_INTERNAL_ERROR** | *DeviceObject* is not a valid volume device object.<br><br>-or-<br><br>The volume related to *DeviceObject* was registered but does not have any filter instances attached. |

## Remarks

Using the *Index* parameter is simply a way for **FltEnumerateInstanceInformationByDeviceObject** to select among minifilter driver instances and legacy filter drivers in the instance/filter list for the volume that is related to *DeviceObject*. Because the minifilter driver instances in the instance/filter list can change at any time, two calls to **FltEnumerateInstanceInformationByDeviceObject** with the same *Index* and *DeviceObject* values are not guaranteed to return the same result.

This routine will return both legacy filter driver information and minifilter driver instance information when the value of the *InformationClass* parameter is **InstanceAggregateStandardInformation**.

## See also

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateInstanceInformationByVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolumename)