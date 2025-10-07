# SceSvcAttachmentAnalyze callback function

The **SceSvcAttachmentAnalyze** function is called by the Security Configuration Engine when the system is analyzed.

## Parameters

*pSceCbInfo* \[in\]

Pointer to a [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure which contains an opaque database handle and callback function pointers to query, set, and free information.

## Return value

If this function succeeds, it returns SCESTATUS\_SUCCESS. Otherwise it returns an error code. For more information about the Security Configuration error codes, see [Attachment Return Values](https://learn.microsoft.com/windows/win32/secmgmt/management-return-values).

## Remarks

The **SceSvcAttachmentAnalyze** function must do the following:

- Directly query configuration information from the service.
- Call the callback function pointed to by the **pfQueryInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfQueryInfo) to retrieve information from the security database.
- Compute the differences between the information based on type and syntax.
- Call the callback function pointed to by the **pfSetInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfSetInfo) to update the security database with the retrieved service information that is different.

For more information, see [Implementing SceSvcAttachmentAnalyze](https://learn.microsoft.com/windows/win32/secmgmt/implementing-scesvcattachmentanalyze).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[Implementing SceSvcAttachmentAnalyze](https://learn.microsoft.com/windows/win32/secmgmt/implementing-scesvcattachmentanalyze)

[**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info)

[**SceSvcAttachmentConfig**](https://learn.microsoft.com/windows/win32/secmgmt/scesvcattachmentconfig)

