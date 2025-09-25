# FilterGetInformation function

## Description

The **FilterGetInformation** function returns various kinds of information about a minifilter.

## Parameters

### `hFilter` [in]

Handle returned by a previous call to the [FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate) function.

### `dwInformationClass` [in]

Type of information requested. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterFullInformation** | Return a [FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information) structure for the minifilter. |
| **FilterAggregateBasicInformation** | Return a [FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information) structure for the minifilter. This *dwInformationClass* value is available starting with Microsoft Windows Server 2003 with SP1 and Microsoft Windows XP with SP2 with filter manager rollup. For more information about the filter manager rollup package for Windows XP with SP2, see article 914882, " [The filter manager rollup package for Windows XP SP2](https://support.microsoft.com/?kbid&ID=914882)," in the Microsoft Knowledge Base. |
| **FilterAggregateStandardInformation** | Return a [FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information) structure for each minifilter. The LegacyFilter portion of the structure is not utilized. This *dwInformationClass* value is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterGetInformation** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterGetInformation** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **FilterAggregateStandardInformation** is specified for an operating system prior to Windows Vista, **FilterGetInformation** returns this HRESULT value. |

## Remarks

**FilterGetInformation** is the Win32 equivalent of [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetfilterinformation).

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetfilterinformation)