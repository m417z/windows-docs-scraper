# NCryptNotifyChangeKey function

## Description

The **NCryptNotifyChangeKey** function creates or removes a key change notification.

The handle provided by this function is the same handle that is returned by the [FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) function. You use the [wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) to wait for the notification handle to be signaled.

## Parameters

### `hProvider` [in]

The handle of the key storage provider. This handle is obtained by using the [NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider) function.

### `phEvent` [in, out]

The address of a **HANDLE** variable that either receives or contains the key change notification event handle. This is the same handle that is returned by the [FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) function. For more information, see the *dwFlags* parameter description.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This parameter contains a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_REGISTER_NOTIFY_FLAG**<br><br>0x00000001 | Create a new change notification. The *phEvent* parameter will receive the key change notification handle. |
| **NCRYPT_UNREGISTER_NOTIFY_FLAG**<br><br>0x00000002 | Remove an existing change notification. The *phEvent* parameter must contain a valid key change notification handle. This handle is no longer valid after this function is called with this flag and the **INVALID_HANDLE_VALUE** value is placed in this handle. |
| **NCRYPT_MACHINE_KEY_FLAG**<br><br>0x00000020 | Receive change notifications for keys in the machine key store. If this flag is not specified, the change notification events will only occur for keys in the calling user's key store. This flag is only valid when combined with the **NCRYPT_REGISTER_NOTIFY_FLAG** flag. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_HANDLE** | The *hProvider* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa)