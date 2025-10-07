# SceSvcAttachmentConfig callback function

The **SceSvcAttachmentConfig** function is called by the Security Configuration Engine when the system is configured.

## Parameters

*pSceCbInfo* \[in\]

Pointer to a [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure that contains the database handle and the callback functions to query, set, and free information.

## Return value

If this function succeeds, it returns SCESTATUS\_SUCCESS. Otherwise it returns an error code. For more information about the Security Configuration error codes, see [Attachment Return Values](https://learn.microsoft.com/windows/win32/secmgmt/management-return-values).

## Remarks

When implementing this function, use the callback function pointed to by the **pfQueryInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfQueryInfo) to retrieve configuration information. Then configure the service using the returned information.

This function must do the following:

- Query configuration information from the Security Configuration tool set using the callback function pointed to by the **pfQueryInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfQueryInfo).
- Configure the service using the configuration information.

For more information, see [Implementing SceSvcAttachmentConfig](https://learn.microsoft.com/windows/win32/secmgmt/implementing-scesvcattachmentconfig)

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info)

[**SceSvcAttachmentAnalyze**](https://learn.microsoft.com/windows/win32/secmgmt/scesvcattachmentanalyze)

