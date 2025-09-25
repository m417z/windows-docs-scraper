# FltEnumerateFilterInformation function

## Description

The **FltEnumerateFilterInformation** routine provides information about all the registered filter drivers (including minifilter and legacy filter drivers) in the system.

## Parameters

### `Index` [in]

Zero-based index of the filter driver for which the information is requested. This parameter identifies the filter in the global list of registered filter drivers. If the list contains *n* filter drivers, valid *Index* values range from 0 to *n*-1. If the *Index* value exceeds this range, **FltEnumerateFilterInformation** returns STATUS_NO_MORE_ENTRIES.

### `InformationClass` [in]

Type of information requested. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterFullInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information) structure for the minifilter driver (legacy filter drivers are ignored). |
| **FilterAggregateBasicInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information) structure for the minifilter or legacy filter driver. This *InformationClass* value is available starting with Microsoft Windows Server 2003 SP1 and Windows XP SP2 with filter manager rollup. For more about the filter manager rollup package for Windows XP SP2, see article 914882, "[The filter manager rollup package for Windows XP SP2](https://go.microsoft.com/fwlink/p/?linkid=3100&ID=914882)," in the Microsoft Knowledge Base. |
| **FilterAggregateStandardInformation** | The buffer pointed to by the *Buffer* parameter receives a [FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information) structure for the minifilter or legacy filter driver. This *InformationClass* value is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateFilterInformation** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateFilterInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter driver was found, but it is being torn down. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **FilterAggregateStandardInformation** is specified on operating systems prior to Windows Vista, the routine will return STATUS_INVALID_PARAMETER. This is an error code. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the global list of registered filter drivers. (The value of the *Index* parameter is greater than or equal to the number of filter drivers.) This is a warning code. |

## Remarks

Starting with Microsoft Windows Server 2003 SP1 and Windows XP SP2 with filter manager rollup, **FltEnumerateFilterInformation** provides information about file system filter drivers (also called "legacy filters") as well as minifilter drivers. On earlier versions of Windows, **FltEnumerateFilterInformation** only provides information about minifilter drivers.

The following pseudocode enumerates filter information for all registered filter drivers.

```
#define InfoClass FilterAggregateStandardInformation   // Assumes Windows Vista or later operating system.

int i = 0;
while ( FltEnumerateFilterInformation(i, InfoClass, ...) != STATUS_NO_MORE_ENTRIES )
{
 Process acquired filter driver information returned by the Buffer parameter of FltEnumerateFilterInformation, if applicable.
 i++;
}
```

**FltEnumerateFilterInformation** returns information about registered filter drivers, through the *Buffer* parameter, in order of decreasing distance from the underlying file system. For example, assume that there are *n* filter drivers attached above an underlying file system. Information about the filter driver attached farthest from the file system is returned first (with an *Index* parameter value of 0). Information about the next-farthest attached filter driver is returned second (with an *Index* parameter value of 1), and so on. Finally, information about the filter driver closest to the file system is returned last (with an *Index* parameter value of *n*-1).

**Note** Because filter drivers can register at any time, it is possible that two calls to **FltEnumerateFilterInformation** with the same *Index* might not return the same result.

To enumerate all registered minifilter drivers, call [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters).

To enumerate all registered legacy filter drivers, call [IoEnumerateRegisteredFiltersList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioenumerateregisteredfilterslist).

To enumerate all instances of a given minifilter driver, call [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter).

To enumerate all minifilter driver instances on a given volume, call [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume).

To list volume information for all volumes that are known to the Filter Manager, call [FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation).

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[IoEnumerateRegisteredFiltersList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioenumerateregisteredfilterslist)