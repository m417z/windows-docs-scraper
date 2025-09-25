# ISceSvcAttachmentData::GetData

## Description

The **GetData** method retrieves configuration information from the Security Configuration snap-in.

## Parameters

### `scesvcHandle` [in]

Type: **SCESVC_HANDLE**

A
[SCESVC_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/scesvc-handle) returned during a previous call to
[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize).

### `sceType` [in]

Type: **SCESVC_INFO_TYPE**

A
[SCESVC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/scesvc/ne-scesvc-scesvc_info_type) value that indicates the type of information requested from the security database. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SCE_SERVICE_CONFIGURATION_INFO** | Requests configuration information from the database. |
| **SCE_SERVICE_ANALYSIS_INFO** | Requests analysis information from the database. |

### `ppvData` [out]

Type: **PVOID***

Pointer to a buffer which receives the data.

### `psceEnumHandle` [in, out]

Type: **PSCE_ENUMERATION_CONTEXT**

An opaque handle used to navigate through the security database.

## Return value

Type: **HRESULT**

The return value is an **HRESULT**. A value of S_OK indicates the method was successful.

## See also

[ISceSvcAttachmentData](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentdata)

[ISceSvcAttachmentData::Initialize](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-initialize)

[SCESVC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/scesvc/ne-scesvc-scesvc_info_type)