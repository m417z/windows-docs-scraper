# FilterInstanceFindFirst function

## Description

The **FilterInstanceFindFirst** function returns information about a minifilter driver instance and is used as a starting point for scanning the instances of a minifilter.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string that contains the name of the minifilter driver that owns the instance.

### `dwInformationClass` [in]

The type of instance information structure returned. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | Return an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for the instance. |
| **InstanceFullInformation** | Return an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for the instance. |
| **InstancePartialInformation** | Return an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for the instance. |
| **InstanceAggregateStandardInformation** | Return an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for the instance. The LegacyFilter portion of the structure is not utilized. This structure is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to, if the call to **FilterInstanceFindFirst** succeeds. This parameter is required and cannot be **NULL**.

### `lpFilterInstanceFind` [out]

Pointer to a caller-allocated variable that receives a search handle for the minifilter if the call to **FilterInstanceFindFirst** succeeds; otherwise, it receives INVALID_HANDLE_VALUE. This search handle can be used in subsequent calls to [FilterInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindnext) and [FilterInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindclose).

## Return value

**FilterInstanceFindFirst** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified for operating systems prior to Windows Vista, the function returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | The minifilter specified by the *lpFilterName* parameter does not have an instance on the file system stack. |

## Remarks

The **FilterInstanceFindFirst** function opens a search handle and returns information about an instance for the minifilter named by *lpFilterName*. After the search handle has been established, call [FilterInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindnext) to search for other instances of the same minifilter. When the search handle is no longer needed, close it by calling [FilterInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindclose).

## See also

[FilterInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindclose)

[FilterInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindnext)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information)