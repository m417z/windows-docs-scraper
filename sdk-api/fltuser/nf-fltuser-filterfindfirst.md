# FilterFindFirst function

## Description

The **FilterFindFirst** function returns information about a filter driver (minifilter driver instance or legacy filter driver) and is used to begin scanning the filters in the global list of registered filters.

## Parameters

### `dwInformationClass` [in]

Type of filter driver information requested. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterFullInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information) structure for each minifilter instance. Legacy filters are ignored. |
| **FilterAggregateBasicInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information) structure for each minifilter instance or legacy filter. This *dwInformationClass* value is available starting with Windows Server 2003 with SP1 and Windows XP with SP2 with filter manager rollup. For more information about the filter manager rollup package for Windows XP with SP2, see article 914882, " [The filter manager rollup package for Windows XP SP2](https://support.microsoft.com/?kbid&ID=914882)," in the Microsoft Knowledge Base. |
| **FilterAggregateStandardInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information) structure for each minifilter instance or legacy filter. This *dwInformationClass* value is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterFindFirst** succeeds. This parameter is required and cannot be **NULL**.

### `lpFilterFind` [out]

Pointer to a caller-allocated variable that receives a search handle for the filter driver if the call to **FilterFindFirst** succeeds; otherwise, it receives INVALID_HANDLE_VALUE. This search handle can be used in subsequent calls to [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) and [FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose).

## Return value

**FilterFindFirst** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if *FilterAggregateStandardInformation* is specified for an operating system prior to Windows Vista, **FilterFindFirst** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | A filter driver was not found in the global list of registered filters. |

## Remarks

The **FilterFindFirst** function opens a search handle and returns information about the first filter driver that is found in the global list of registered filters. After the search handle has been established, call the [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) function to search for other filters in the global list. When the search handle is no longer required, close it by calling [FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose).

Starting with Microsoft Windows Server 2003 with SP1 and Windows XP with Service Pack 1 (SP1) with filter manager rollup, **FilterFindFirst** and [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) can provide legacy filter driver information and minifilter driver instance information. On earlier versions of Windows, **FilterFindFirst** and **FilterFindNext** can only provide information about minifilters (see the description for the *dwInformationClass* parameter above).

**FilterFindFirst** and [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) return information about filter drivers in order of decreasing distance from the base file system. Information about the filter farthest from the base file system is returned first. Information about the second-farthest filter is returned second. Information about the filter closest to the base file system is returned last.

If the input *dwBufferSize* is too small, *lpFilterFind* receives INVALID_HANDLE_VALUE, and *lpBytesReturned* receives the number of bytes required to store the requested information.

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FilterFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindclose)

[FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext)