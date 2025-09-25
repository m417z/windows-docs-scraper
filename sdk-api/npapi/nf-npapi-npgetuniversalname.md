# NPGetUniversalName function

## Description

Retrieves the universal name of a network resource. The **NPGetUniversalName** function can retrieve this universal name in UNC format or in the older, remote-name format.

## Parameters

### `lpLocalPath` [in]

Pointer to the local path of an object on a network resource. This is a drive-based path.

### `dwInfoLevel` [in]

The level of detail of information the caller is interested in. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **UNIVERSAL_NAME_INFO_LEVEL** | Retrieves the UNC form of the name, for example: "file:\\server\share" <br><br>If this value is set, the data returned in *lpBuffer* is stored as a [UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa) structure. |
| **REMOTE_NAME_INFO_LEVEL** | Retrieves the remote form of the name, for example: "\\server\share" <br><br>If this value is set, the data returned in *lpBuffer* is stored as a [REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infoa) structure. |

### `lpBuffer` [out]

Pointer to a buffer to receive the information the user has requested. The specific structure returned depends on the information level specified in *dwInfoLevel*.

### `lpBufferSize` [in, out]

Pointer to the size, in bytes, of the *lpBuffer* buffer. If the call fails because the buffer is not big enough, this location will be used to return the required buffer size.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which may be one of the following.

| Return code | Description |
| --- | --- |
| **WN_BAD_LOCALNAME** | The value passed into *lpLocalPath* is not valid. |
| **WN_NOT_CONNECTED** | The value passed into *lpLocalPath* is not a redirected device. |
| **WN_MORE_DATA** | The buffer is too small. |
| **WN_NO_NETWORK** | The network is not present. |