# FltGetInstanceInformation function

## Description

The **FltGetInstanceInformation** routine returns information about a minifilter driver instance.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller.

### `InformationClass` [in]

Type of information requested. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for the instance. |
| **InstanceFullInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for the instance. |
| **InstancePartialInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for the instance. |
| **InstanceAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for the instance. The **LegacyFilter** portion of the structure is not utilized. This structure is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltGetInstanceInformation** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltGetInstanceInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified on the operating systems prior to Windows Vista, the routine will return STATUS_INVALID_PARAMETER. This is an error code. |

## Remarks

Given a pointer to a minifilter instance, this routine returns information about the minifilter instance. The type of instance information returned is determined by the *InformationClass* parameter.

## See also

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information)