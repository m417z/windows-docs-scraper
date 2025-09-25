# PFSCE_SET_INFO callback function

## Description

The *PFSCE_SET_INFO* callback function sets or overwrites service-specific configuration and analysis information.

## Parameters

### `sceHandle` [in]

Type: **SCE_HANDLE**

Specifies the opaque SCE handle passed to the attachment by the Security Configuration tool set during the call to
[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize). This handle is used to set or overwrite the information.

### `sceType` [in]

Type: **SCESVC_INFO_TYPE**

Specifies the type of information to be set. Specify one of the following flags.

| Value | Meaning |
| --- | --- |
| **SCE_SERVICE_CONFIGURATION_INFO** | Indicates that configuration information is set. |
| **SCE_SERVICE_ANALYSIS_INFO** | Indicates that analysis information is set. |

### `lpPrefix` [in, optional]

Type: **LPTSTR**

Specifies what information should be set or overwritten. This string can specify a specific key (see *bExact*) or a prefix for a set of keys. When a string is supplied, only information for those keys (and their corresponding values) that match the string is set. When set to **NULL**, all information for the service is set.

### `bExact` [in]

Type: **BOOL**

Specifies whether the string provided by *lpPrefix* should be treated as a specific key or a prefix for a set of keys. This parameter is ignored if *lpPrefix* is set to **NULL**.

Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUE** | The string specified in *lpPrefix* represents a specific key. Only that key is set. |
| **FALSE** | The string specified by *lpPrefix* represents a prefix for a set of keys. All keys (and their values) that have the same prefix is set. |

### `pvInfo` [in]

Type: **PVOID**

Returns a pointer to one of the following structures. The Security Configuration tool set (not the attachment) allocates the buffer for the information; therefore, this pointer must point to **NULL**.

| Value | Meaning |
| --- | --- |
| **SCESVC_CONFIGURATION_INFO** | When *sceType* is set to SCE_SERVICE_CONFIGURATION_INFO. |
| **SCESVC_ANALYSIS_INFO** | When *sceType* is set to SCE_SERVICE_ANALYSIS_INFO. |

## Return value

Type: **SCESTATUS**

If the function succeeds, it returns SCESTATUS_SUCCESS; otherwise, it returns an error value which can be one of the following.

| Return code | Description |
| --- | --- |
| **SCESTATUS_ACCESS_DENIED** | The caller does not have sufficient privileges to complete this action. |
| **SCESTATUS_BAD_FORMAT** | The format is bad. |
| **SCESTATUS_PREFIX_OVERFLOW** | There is more data than the buffer can hold. |
| **SCESTATUS_INVALID_PARAMETER** | One of the parameters passed into the function was not valid. |
| **SCESTATUS_NOT_ENOUGH_RESOURCE** | There is insufficient memory. |
| **SCESTATUS_OTHER_ERROR** | An unspecified error has occurred. |
| **SCESTATUS_RECORD_NOT_FOUND** | The specified record was not found in the security database. |

## See also

[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info)

[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info)

[SCESVC_CONFIGURATION_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info)