# FilterInstanceGetInformation function

## Description

The **FilterInstanceGetInformation** function returns various kinds of information about a minifilter instance.

## Parameters

### `hInstance` [in]

Handle returned by a previous call to [FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate).

### `dwInformationClass` [in]

The type of instance information structure returned. This parameter must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **InstanceBasicInformation** | Return an [INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information) structure for the instance. |
| **InstanceFullInformation** | Return an [INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information) structure for the instance. |
| **InstancePartialInformation** | Return an [INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information) structure for the instance. |
| **InstanceAggregateStandardInformation** | Return an [INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information) structure for the instance. The **LegacyFilter** portion of the structure is utilized starting with Windows 8. This structure is available starting with Windows Vista. |

### `lpBuffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *dwInformationClass* parameter.

### `dwBufferSize` [in]

Size, in bytes, of the buffer that the *lpBuffer* parameter points to. The caller should set this parameter according to the given *dwInformationClass*.

### `lpBytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *lpBuffer* points to if the call to **FilterInstanceGetInformation** succeeds. This parameter is required and cannot be **NULL**.

## Return value

**FilterInstanceGetInformation** returns S_OK if successful. Otherwise, it returns an HRESULT error value, such as one of the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by *lpBuffer* is not large enough to contain the requested information. When this value is returned, *lpBytesReturned* will contain the size, in bytes, of the buffer required for the given *dwInformationClass* structure. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)** | An invalid value was specified for the *dwInformationClass* parameter. For example, if **InstanceAggregateStandardInformation** is specified for an operating system prior to Windows Vista, **FilterInstanceGetInformation** returns this HRESULT value. |

## Remarks

Given a handle to a minifilter instance, this routine returns information about the minifilter instance. The type of instance information returned is determined by the *dwInformationClass* parameter.

**FilterInstanceGetInformation** is the Win32 equivalent of [FltGetInstanceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetinstanceinformation).

## See also

[FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate)

[FltGetInstanceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetinstanceinformation)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltuserstructures/ns-fltuserstructures-_instance_partial_information)