## Description

Specifies the type of structure that a Remote Desktop Services function has returned in a buffer.

## Constants

### `WTSTypeProcessInfoLevel0`

The buffer contains the server nonce output by *WTSCloudAuthGetServerNonce*.

### `WTSTypeProcessInfoLevel1`

The buffer contains one or more [WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info) structures.

### `WTSTypeSessionInfoLevel1`

The buffer contains the serialized user credential output by [WTSCloudAuthConvertAssertionToSerializedUserCredential](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthduplicateserializedusercredential).

### `WTSTypeCloudAuthServerNonce`

The buffer contains one or more [WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) structures

### `WTSTypeSerializedUserCredential`

The buffer contains one or more [WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures.

## Remarks

## See also