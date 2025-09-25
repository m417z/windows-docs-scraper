# INetwork::GetTimeCreatedAndConnected

## Description

The **GetTimeCreatedAndConnected** method returns the local date and time when the network was created and connected.

## Parameters

### `pdwLowDateTimeCreated` [out]

Pointer to a datetime when the network was created. Specifically, it contains the low DWORD of **FILETIME.dwLowDateTime**.

### `pdwHighDateTimeCreated` [out]

Pointer to a datetime when the network was created. Specifically, it contains the high DWORD of **FILETIME.dwLowDateTime**.

### `pdwLowDateTimeConnected` [out]

Pointer to a datetime when the network was last connected to. Specifically, it contains the low DWORD of **FILETIME.dwLowDateTime**.

### `pdwHighDateTimeConnected` [out]

Pointer to a datetime when the network was last connected to. Specifically, it contains the high DWORD of **FILETIME.dwLowDateTime**.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The pointer passed is **NULL**. |

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)