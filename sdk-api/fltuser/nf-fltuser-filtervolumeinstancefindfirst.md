# FilterVolumeInstanceFindFirst function

## Description

The **FilterVolumeInstanceFindFirst** function returns information about a minifilter driver instance or legacy filter driver and is used to begin scanning the filter drivers that are attached to a volume.

## Parameters

### `lpVolumeName` [in]

Pointer to a null-terminated wide-character string that contains the name of the volume to which the minifilter instance or legacy filter is attached.

The *lpVolumeName* input string can be any of the following. The trailing backslash (\\) is optional.

* A drive letter, such as D:\
* A path to a volume mount point, such as c:\mnt\edrive\
* A unique volume identifier (also called a *volume GUID name*), such as \??\Volume{7603f260-142a-11d4-ac67-806d6172696f}\
* A nonpersistent device name (also called a *target name* or an *NT device name*), such as \Device\HarddiskVolume1\

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

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterVolumeInstanceFindFirst** succeeds. This parameter is required and cannot be **NULL**.

### `lpVolumeInstanceFind` [out]

Pointer to a caller-allocated variable that receives a search handle for the minifilter instance or legacy filter (only when **InstanceAggregateStandardInformation** is specified) if the call to **FilterVolumeInstanceFindFirst** succeeds. Otherwise, *lpVolumeInstanceFind* receives INVALID_HANDLE_VALUE. This search handle can be used in subsequent calls to [FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext) and [FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindclose).

## Return value

**FilterVolumeInstanceFindFirst** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified for an operating system prior to Windows Vista, **FilterVolumeInstanceFindFirst** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | A filter driver was not found on the given volume. |

## Remarks

The **FilterVolumeInstanceFindFirst** function opens a search handle and returns information about the first filter driver found that is attached to the volume named by *lpVolumeName*. After the search handle has been established, call [FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext) to search for other filter drivers that are attached to the same volume. When the search handle is no longer needed, close it by calling [FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindclose).

Starting with Windows Vista, **FilterVolumeInstanceFindFirst** can return both legacy filter driver information and minifilter driver instance information when the value of the *dwInformationClass* parameter is **InstanceAggregateStandardInformation**. For earlier operating systems, this function cannot return legacy filter information because the INSTANCE_AGGREGATE_STANDARD_INFORMATION structure is not available.

## See also

[FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindclose)

[FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information)