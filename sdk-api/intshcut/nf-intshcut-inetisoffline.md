# InetIsOffline function

## Description

Determines whether the system is connected to the Internet.

## Parameters

### `dwFlags`

Type: **DWORD**

The input flags for the function. This must be set to zero.

## Return value

Type: **BOOL**

Returns **TRUE** if the local system is not currently connected to the Internet. Returns **FALSE** if the local system is connected to the Internet or if no attempt has yet been made to connect to the Internet.