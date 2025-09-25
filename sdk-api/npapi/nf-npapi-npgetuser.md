# NPGetUser function

## Description

Retrieves the value of the current default user name or the user name used to establish a network connection.

## Parameters

### `lpName` [in]

Pointer to the name of the local device the caller is interested in, or a remote name for a resource that the user has made a connection to. This parameter may be **NULL** or the empty string if the caller is interested in the name of the user currently logged on to the system. If a remote name for a resource is passed in, and the user is connected to that resource using different names, it is possible that a provider cannot resolve which user name to return. In this case the provider may make an arbitrary choice amongst the possible user names.

### `lpUserName` [out]

Pointer to a buffer to receive the user name. This should be a name that can be passed into the
[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection) or
[NPAddConnection3](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection3) function to re-establish the connection with the same user name.

### `lpnBufferLen` [in, out]

Pointer to the size, in characters, of the *lpUserName* buffer. If the call fails because the buffer is not big enough, this location will be used to return the required buffer size.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise it should return an error code, which can be one of the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_CONNECTED** | The value in the *lpName* parameter is not the name of a redirected device or a connected remote name. |
| **WN_MORE_DATA** | The buffer, *lpUserName*, is too small. |
| **WN_NO_NETWORK** | The network is not present. |