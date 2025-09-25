# FilterVolumeInstanceFindNext function

## Description

The **FilterVolumeInstanceFindNext** function continues a minifilter driver instance or legacy filter driver search started by a call to [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst).

## Parameters

### `hVolumeInstanceFind` [in]

Volume filter driver search handle returned by a previous call to [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst).

### `dwInformationClass` [in]

The type of filter driver information structure returned. This parameter must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | Return an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceFullInformation** | Return an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstancePartialInformation** | Return an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for a minifilter instance. Legacy filter drivers are ignored. |
| **InstanceAggregateStandardInformation** | Return an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for the instance. The **LegacyFilter** member of the structure is not utilized. <br><br>This structure is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterVolumeInstanceFindNext** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterVolumeInstanceFindNext** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified for an operating system prior to Windows Vista, **FilterVolumeInstanceFindNext** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | No more filter drivers were found on the given volume. |

## Remarks

**FilterVolumeInstanceFindNext** finds one filter driver per call.

After the search handle is established by calling **FilterVolumeInstanceFindFirst**, use the **FilterVolumeInstanceFindNext** function to search for other filter drivers that are attached to the volume specified in the call to [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst). When the search handle is no longer required, close it by calling [FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindclose).

Starting with Windows Vista, this routine can return both legacy filter driver information and minifilter driver instance information when the value of the *dwInformationClass* parameter is **InstanceAggregateStandardInformation**. For earlier operating systems, this routine cannot return legacy filter information because the INSTANCE_AGGREGATE_STANDARD_INFORMATION structure is not available.

## See also

[FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindclose)

[FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information)