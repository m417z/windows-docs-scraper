# FilterVolumeFindFirst function

## Description

The **FilterVolumeFindFirst** function returns information about a volume.

## Parameters

### `dwInformationClass` [in]

Type of requested information. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterVolumeBasicInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information) structure for the volume. |
| **FilterVolumeStandardInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information) structure for the volume. This structure is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterVolumeFindFirst** succeeds. This parameter is required and cannot be **NULL**.

### `lpVolumeFind` [out]

Pointer to a caller-allocated variable that receives a search handle for the minifilter if the call to **FilterVolumeFindFirst** succeeds; otherwise, it receives INVALID_HANDLE_VALUE. This search handle can be used in subsequent calls to [FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext) and [FilterVolumeFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindclose).

## Return value

**FilterVolumeFindFirst** returns S_OK if it successfully returns information about a volume. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **FilterVolumeStandardInformation** is specified for an operating system prior to Windows Vista, **FilterVolumeFindFirst** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | A volume was not found in the list of volumes known to the filter manager. |

## Remarks

This **FilterVolumeFindFirst**  function is used to begin scanning the volumes that are known to the filter manager.

**FilterVolumeFindFirst** opens a search handle and returns information about the first volume found in the list of volumes known to the filter manager. After the search handle has been established, use the [FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext) function to search for other volumes in the filter manager's list. When the search handle is no longer required, close it by calling [FilterVolumeFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindclose).

Note that when using **FilterVolumeFindFirst** and [FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext) to enumerate the list of volumes known to the filter manager, it is possible for two or more volumes in the list to have the same name. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

## See also

[FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information)

[FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[FilterVolumeFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindclose)

[FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext)