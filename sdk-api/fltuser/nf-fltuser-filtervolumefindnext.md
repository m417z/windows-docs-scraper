# FilterVolumeFindNext function

## Description

The **FilterVolumeFindNext** function continues a volume search started by a call to [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst).

## Parameters

### `hVolumeFind` [in]

Volume search handle returned by a previous call to [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst).

### `dwInformationClass` [in]

Type of information requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterVolumeBasicInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information) structure for the volume. |
| **FilterVolumeStandardInformation** | The buffer pointed to by the *lpBuffer* parameter receives a [FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information) structure for the volume. This structure is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterVolumeFindNext** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterVolumeFindNext** returns S_OK if it successfully returns volume information. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **FilterVolumeStandardInformation** is specified for an operating system prior to Windows Vista, **FilterVolumeFindNext** returns this HRESULT value. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | No more volumes were found in the list of volumes known to the filter manager. |

## Remarks

After the search handle is established by calling [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst), use the **FilterVolumeFindNext** function to search for other volumes. **FilterVolumeFindNext** finds one volume per call.

Note that when using [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst) and **FilterVolumeFindNext** to enumerate the list of volumes known to the filter manager, it is possible for two or more of the volumes in the list to have the same name. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

## See also

[FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information)

[FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[FilterVolumeFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindclose)

[FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst)