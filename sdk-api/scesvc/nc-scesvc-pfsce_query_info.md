# PFSCE_QUERY_INFO callback function

## Description

The *PFSCE_QUERY_INFO* callback function queries service-specific information from the Security Configuration file or analysis database.

## Parameters

### `sceHandle` [in]

Type: **SCE_HANDLE**

Specifies the opaque handle passed to the attachment by the Security Configuration tool set during the call to
[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize). This handle is used to store the queried information.

### `sceType` [in]

Type: **SCESVC_INFO_TYPE**

Specifies the type of information to be queried. Specify one of the following flags.

| Value | Meaning |
| --- | --- |
| **SCE_SERVICE_CONFIGURATION_INFO** | Requests configuration information from the database. |
| **SCE_SERVICE_ANALYSIS_INFO** | Requests analysis information from the database. |

### `lpPrefix` [in, optional]

Type: **LPTSTR**

Specifies a prefix or key (see *bExact*) for limiting the query. When a string is supplied, only those keys (and their corresponding values) that match the string are returned. When set to **NULL**, all keys are returned.

### `bExact` [in]

Type: **BOOL**

Specifies whether the string provided by *lpPrefix* should be treated as a specific key or a prefix. This parameter is ignored if *lpPrefix* is set to **NULL**. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUE** | The string specified in *lpPrefix* represents a specific key. Only records matching that key are returned. |
| **FALSE** | The string specified by *lpPrefix* represents a prefix. All keys (and their values) that have this same prefix are returned. |

### `ppvInfo` [out]

Type: **PVOID***

Returns a pointer to one of the following structures. The Security Configuration tool set (not the attachment) allocates the buffer for the information; therefore, this pointer must point to **NULL**.

| Value | Meaning |
| --- | --- |
| **SCESVC_CONFIGURATION_INFO** | When *sceType* is set to SCE_SERVICE_CONFIGURATION_INFO. |
| **SCESVC_ANALYSIS_INFO** | When *sceType* is set to SCE_SERVICE_ANALYSIS_INFO. |

### `psceEnumHandle` [out]

Type: **PSCE_ENUMERATION_CONTEXT**

Returns a handle that can be used in successive calls to this function. Due to the large number of keys that may be present, not all keys are returned in a single call. The maximum number of keys that may be returned in a single call is 256.

## Return value

Type: **SCESTATUS**

An **SCESTATUS** value that indicates the result of the function call. If the function succeeds, it returns SCESTATUS_SUCCESS; otherwise, it returns an error value, which can be one of the following.

| Return code | Description |
| --- | --- |
| **SCESTATUS_INVALID_PARAMETER** | One of the parameters passed into the function was not valid. |
| **SCESTATUS_RECORD_NOT_FOUND** | The specified record was not found in the security database. |
| **SCESTATUS_BAD_FORMAT** | The format is not valid. |
| **SCESTATUS_OTHER_ERROR** | An unspecified error has occurred. |
| **SCESTATUS_NOT_ENOUGH_RESOURCE** | There is insufficient memory. |

## Remarks

The Security Configuration tool set allocates buffers when *PFSCE_QUERY_INFO* is called. To free these buffers call
[PFSCE_FREE_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_free_info) after the returned information is no longer needed.

#### Examples

| For an example of | See |
| --- | --- |
| Retrieving configuration information | [Implementing SceSvcAttachmentConfig](https://learn.microsoft.com/windows/desktop/SecMgmt/implementing-scesvcattachmentconfig) |
| Retrieving analysis information | [Implementing SceSvcAttachmentAnalyze](https://learn.microsoft.com/windows/desktop/SecMgmt/implementing-scesvcattachmentanalyze) |
| Retrieving configuration and analysis information | [Implementing SceSvcAttachmentUpdate](https://learn.microsoft.com/windows/desktop/SecMgmt/implementing-scesvcattachmentupdate) |

## See also

[PFSCE_FREE_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_free_info)

[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info)

[SCESVC_CONFIGURATION_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info)