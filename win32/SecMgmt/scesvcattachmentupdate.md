# SceSvcAttachmentUpdate callback function

The **SceSvcAttachmentUpdate** function is called by the Security Configuration snap-ins to pass configuration changes to the security database.

## Parameters

*pSceCbInfo* \[in\]

Pointer to a [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure which contains the callback handle and function pointers to SCE.

*ServiceInfo* \[in\]

Updated configuration information. The data structure used for this information is [**SCESVC\_CONFIGURATION\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info).

## Return value

If this function succeeds, it returns SCESTATUS\_SUCCESS. Otherwise it returns an error code. For more information about the Security Configuration error codes, see [Attachment Return Values](https://learn.microsoft.com/windows/win32/secmgmt/management-return-values).

## Remarks

The **SceSvcAttachmentUpdate** function must do the following:

- Call the callback function pointed to by the **pfQueryInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfQueryInfo) to retrieve the current base configuration information from the security database.
- Call the callback function pointed to by the **pfQueryInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfQueryInfo) to retrieve the last set of differences (analysis information) from the security database.
- Use the supplied service information (see *ServiceInfo*) to compute the new base configuration.
- Use the supplied service information (see *ServiceInfo*) and the analysis to compute the new difference information.
- Call the callback function pointed to by the **pfSetInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfSetInfo)to set the new base configuration in the security database.
- Call the callback function pointed to by the **pfSetInfo** member of the [**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info) structure (pSceCbInfo->pfSetInfo) to set the new analysis information in the security database.

For more information, see [Implementing SceSvcAttachmentUpdate](https://learn.microsoft.com/windows/win32/secmgmt/implementing-scesvcattachmentupdate)

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SCESVC\_CALLBACK\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_callback_info)

[**SCESVC\_CONFIGURATION\_INFO**](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info)

