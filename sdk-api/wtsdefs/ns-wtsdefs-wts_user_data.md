# WTS_USER_DATA structure

## Description

Contains select client property values.

## Members

### `WorkDirectory`

A string value that specifies the directory where the client startup program resides. This value corresponds to the **WorkDirectory** member of the [WTS_CLIENT_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_client_data) structure.

### `InitialProgram`

A string value that specifies the name of the initial program. This value corresponds to the **InitialProgram** member of the [WTS_CLIENT_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_client_data) structure.

### `UserTimeZone`

A [WTS_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_time_zone_information) structure that contains client time zone information. This value corresponds to the **ClientTimeZone** member of the [WTS_CLIENT_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_client_data) structure.

## Remarks

This structure is used by the [GetUserData](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-getuserdata) method and is both sent to and returned by the protocol. This structure is initialized with client data by the Remote Desktop Services service. If a value does not exist for a member, the protocol should not provide one.