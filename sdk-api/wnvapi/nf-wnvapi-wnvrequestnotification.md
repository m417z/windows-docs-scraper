# WnvRequestNotification function

## Description

Requests notification from the Windows Network Virtualization (WNV) driver whenever a certain type of event occurs.

## Parameters

### `WnvHandle`

Type: **HANDLE**

An object handle that is returned from a call to the [WnvOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvopen) function.

### `NotificationParam`

Type: **[PWNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param)**

A pointer to the notification type for the request.

### `Overlapped`

Type: **[LPOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)**

Information about the asynchronous completion of this request. If this parameter is **NULL**, the request is synchronous.

### `BytesTransferred`

Type: **PULONG**

When this function returns, the *BytesTransferred* parameter points to the size of the buffer that is filled with the notification structures of the specific event type.

## Return value

Type: **ULONG**

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns one of the following system error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | There is a problem with the *NotificationParam* parameter, in the [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure's **Header** field:<br><br>* The major and minor version values of the [WNV_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_header) structure are incorrect<br>* The size specified in the [WNV_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_header) structure is smaller than at least one notification structure of these types:   + [WNV_OBJECT_CHANGE_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_change_param)   + [WNV_POLICY_MISMATCH_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_policy_mismatch_param)   + [WNV_REDIRECT_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_redirect_param) |

## Remarks

This function can be called synchronously or asynchronously.

Three notification types are defined in the [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure. Each call to this function can request only one type of notification. To receive multiple notification types, the process must make one call for each notification on the same handle. The WNV driver returns at least one notification of the type specified in each call when the notification events occur.