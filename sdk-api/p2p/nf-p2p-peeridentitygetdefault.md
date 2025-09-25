# PeerIdentityGetDefault function

## Description

The **PeerIdentityGetDefault** function retrieves the default peer name set for the current user.

## Parameters

### `ppwzPeerName` [out]

Pointer to the address of a zero-terminated Unicode string that contains the default name of the current user.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NOT_FOUND** | A peer identity that matches the specified name cannot be found. |