# FltEnumerateInstanceInformationByVolumeName function

## Description

The **FltEnumerateInstanceInformationByVolumeName** routine provides information about minifilter driver instances and legacy filter drivers that are attached to the volume with the specified name.

## Parameters

### `VolumeName` [in]

The name of the volume to enumerate filter instances for.

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

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateInstanceInformationByVolumeName** returns **STATUS_BUFFER_TOO_SMALL** and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateInstanceInformationByVolumeName** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter instance was found, but it is being torn down. Note that this return value does not apply to legacy filter drivers because legacy filter drivers cannot be unloaded. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter.<br><br>-or-<br><br>*VolumeName* contains an invalid volume name. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the volume's instance/filter list. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The volume specified in *VolumeName* does not exist. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The path for the volume specified in *VolumeName* does not exist. |
| **STATUS_FLT_VOLUME_NOT_FOUND** | The volume specified by *VolumeName* does not have any filter instances attached.<br><br>-or-<br><br>The volume specified by *VolumeName* is being removed from the system. |
| **STATUS_FLT_INTERNAL_ERROR** | The volume specified by *VolumeName* was registered but does not have any filter instances attached. |

## Remarks

Using the *Index* parameter is simply a way for **FltEnumerateInstanceInformationByVolumeName** to select among minifilter driver instances and legacy filter drivers in the instance/filter list for the volume that is specified by *VolumeName*. Because the minifilter driver instances in the instance/filter list can change at any time, two calls to **FltEnumerateInstanceInformationByVolumeName** with the same *Index* and *VolumeName* values are not guaranteed to return the same result.

This routine will return both legacy filter driver information and minifilter driver instance information when the value of the *InformationClass* parameter is **InstanceAggregateStandardInformation**.

## See also

[FltEnumerateInstanceInformationByDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbydeviceobject)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)