# FilterFindNext function

## Description

The **FilterFindNext** function continues a filter search started by a call to [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst).

## Parameters

### `hFilterFind` [in]

Filter search handle returned by a previous call to [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst).

### `dwInformationClass` [in]

Type of information requested. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterFullInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information) structure for each minifilter instance. Legacy filters are ignored. |
| **FilterAggregateBasicInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information) structure for each minifilter instance or legacy filter. This *dwInformationClass* value is available starting with Microsoft Windows Server 2003 with SP1 and Windows XP with SP2 with filter manager rollup. For more information about the filter manager rollup package for Windows XP with SP2, see article 914882, " [The filter manager rollup package for Windows XP SP2](https://support.microsoft.com/?kbid&ID=914882)," in the Microsoft Knowledge Base. |
| **FilterAggregateStandardInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information) structure for each minifilter instance or legacy filter. This *dwInformationClass* value is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterFindNext** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterFindNext** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **FilterAggregateStandardInformation** is specified for an operating system prior to Windows Vista, **FilterFindNext** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | No more filter drivers were found in the global list of registered filter drivers. |

## Remarks

After the filter search handle is established by calling [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst), use the **FilterFindNext** function to search for additional filters in the global list of registered filters.

**FilterFindNext** finds one filter driver (minifilter driver instance or legacy filter driver) per call.

Starting with Microsoft Windows Server 2003 with SP1 and Microsoft Windows XP with SP2 with filter manager rollup, [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst) and **FilterFindNext** can provide legacy filter driver information and minifilter driver instance information. On earlier versions of Windows, **FilterFindFirst** and **FilterFindNext** can only provide information about minifilters (see the description for the *dwInformationClass* parameter above).

[FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst) and **FilterFindNext** return information about filter drivers in order of decreasing distance from the base file system. Information about the filter farthest from the base file system is returned first. Information about the second-farthest filter is returned second. Information about the filter closest to the base file system is returned last.

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose)

[FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst)