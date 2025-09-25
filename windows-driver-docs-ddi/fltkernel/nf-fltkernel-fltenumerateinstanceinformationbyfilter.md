# FltEnumerateInstanceInformationByFilter function

## Description

The **FltEnumerateInstanceInformationByFilter** routine provides information about instances of a given minifilter driver.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller.

### `Index` [in]

Zero-based index of the instance for which the information is requested.

### `InformationClass` [in]

Type of information requested. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for the instance. |
| **InstanceFullInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for the instance. |
| **InstancePartialInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for the instance. |
| **InstanceAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for the instance. The *LegacyFilter* portion of the structure is not utilized. This structure is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateInstanceInformationByFilter** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateInstanceInformationByFilter** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | A matching instance was found, but it is being torn down. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **FilterAggregateStandardInformation** is specified on an operating system prior to Windows Vista, the routine will return STATUS_INVALID_PARAMETER. This is an error code. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the minifilter driver's instance list. This is a warning code. |

## Remarks

The *Index* parameter is simply a way for **FltEnumerateInstanceInformationByFilter** to select among instances in the instance list for the minifilter driver specified by *Filter*. Because the minifilter driver instances in the instance list can change at any time, two calls to **FltEnumerateInstanceInformationByFilter** with the same *Index* and *Filter* values are not guaranteed to return the same result.

To enumerate all registered minifilter drivers, call [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters).

To list filter information for all registered minifilter drivers, call [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

To get filter information for a given minifilter driver, call [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

To enumerate all minifilter driver instances on a given volume, call [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume).

To enumerate instances of all minifilter drivers on all volumes, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

To enumerate all volumes that are known to the Filter Manager, call [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes).

.

## See also

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information)