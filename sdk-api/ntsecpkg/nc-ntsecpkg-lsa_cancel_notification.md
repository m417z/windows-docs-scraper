# LSA_CANCEL_NOTIFICATION callback function

## Description

The **CancelNotification** function cancels a previously registered notification.

## Parameters

### `NotifyHandle` [in]

Handle returned by a previous call to
[RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification).

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed. The following table lists a common reason for failure and the error code that the function returns.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The handle specified by the *NotifyHandle* parameter is not valid. |

## Remarks

Use the
[RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification) function to register a notification.

A pointer to the **CancelNotification** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)