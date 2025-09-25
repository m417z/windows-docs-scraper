# WNV_OBJECT_HEADER structure

## Description

Specifies the major version, minor version, and buffer size of the [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure that is passed to the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function.

## Members

### `MajorVersion`

Type: **UCHAR**

The major version number. This value must be **WNV_API_MAJOR_VERSION_1**.

### `MinorVersion`

Type: **UCHAR**

The minor version number. This value must be **WNV_API_MINOR_VERSION_0**.

### `Size`

Type: **ULONG**

The size of the **Buffer** field in the [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure that is passed to the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function.

## Remarks

There is currently only one version number: "1.0".