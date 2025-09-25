# FltEnumerateInstanceInformationByVolume function

## Description

The **FltEnumerateInstanceInformationByVolume** routine provides information about minifilter driver instances and legacy filter drivers (Windows Vista only) that are attached to a given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume.

### `Index` [in]

Zero-based index of the minifilter driver instance or legacy filter driver for which the information is requested.

### `InformationClass` [in]

Type of information to be returned for the minifilter driver instance or legacy filter driver. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceFullInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstancePartialInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for a minifilter driver instance or legacy filter driver. This structure is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateInstanceInformationByVolume** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateInstanceInformationByVolume** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter instance was found, but it is being torn down. This is an error code. Note that this return value does not apply to legacy filter drivers because legacy filter drivers cannot be unloaded. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified on an operating system prior to Windows Vista, the routine will return STATUS_INVALID_PARAMETER. This is an error code. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the volume's instance/filter list. This is a warning code. |

## Remarks

Using the *Index* parameter is simply a way for **FltEnumerateInstanceInformationByVolume** to select among minifilter driver instances and legacy filter drivers in the instance/filter list for the volume that is specified by *Volume*. Because the minifilter driver instances in the instance/filter list can change at any time, two calls to **FltEnumerateInstanceInformationByVolume** with the same *Index* and *Volume* values are not guaranteed to return the same result.

Starting with Windows Vista, this routine can return both legacy filter driver information and minifilter driver instance information when the value of the *InformationClass* parameter is **InstanceAggregateStandardInformation**. For earlier operating systems, this routine cannot return legacy filter information because the INSTANCE_AGGREGATE_STANDARD_INFORMATION structure is not available.

To list filter information for all registered minifilter drivers, call [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

To get filter information for a given minifilter driver, call [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

To enumerate all instances of a given minifilter driver, call [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter).

To enumerate instances of all minifilter drivers on all volumes, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

To enumerate all volumes that are known to the Filter Manager, call [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes).

## See also

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information)