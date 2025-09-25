# FltGetFilterInformation function

## Description

The **FltGetFilterInformation** routine provides information about a minifilter driver.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller.

### `InformationClass` [in]

Type of information requested. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterFullInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information) structure for the minifilter driver. |
| **FilterAggregateBasicInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information) structure for the minifilter driver. This *InformationClass* value is available starting with Microsoft Windows Server 2003 SP1 and Windows XP SP2 with filter manager rollup. For more information on the filter manager rollup package for Windows XP SP2, see article 914882, " [The filter manager rollup package for Windows XP SP2](https://go.microsoft.com/fwlink/p/?linkid=3100&ID=914882)," in the Microsoft Knowledge Base. |
| **FilterAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information) structure for the minifilter driver. The **LegacyFilter** portion of the structure is not utilized. This *InformationClass* value is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltGetFilterInformation** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltGetFilterInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **FilterAggregateStandardInformation** is specified on an operating system prior to Windows Vista, the routine returns STATUS_INVALID_PARAMETER. This is an error code. |

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltGetInstanceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstanceinformation)