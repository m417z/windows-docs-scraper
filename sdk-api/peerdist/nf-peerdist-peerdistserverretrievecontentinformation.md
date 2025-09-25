# PeerDistServerRetrieveContentInformation function

## Description

The **PeerDistServerRetrieveContentInformation** function retrieves the encoded content information associated with a handle returned by [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation).

## Parameters

### `hPeerDist` [in]

A PEERDIST_INSTANCE_HANDLE returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentInfo` [in]

The handle returned by [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation).

### `cbMaxNumberOfBytes`

The maximum number of bytes to read.

### `pBuffer` [in, out]

Pointer to the buffer that receives the content information data.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. This function does not allow the caller to specify the start Offset in the content. The offset is implicitly maintained per hContentInfo. The Offset and OffsetHigh are reserved and must be zero.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hContentInfo* handle is invalid. |
| **PEERDIST_ERROR_NO_MORE** | EOF on the content information has been reached. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

On the success of the **PeerDistServerRetrieveContentInformation** operation, the **Offset** and **OffsetHigh** fields of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure will be populated with the **ULONGLONG** offset in the content information that was retrieved. The **OffsetHigh** member will be set to the higher 32 bits of the offset and the **Offset** member will be set to the lower 32 bits of the offset.

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) will populate *lpNumberOfBytesTransferred* with the number of bytes transferred. In the event the caller is using a completion port to process Peer Distribution API completions, the *lpNumberOfBytes* argument of [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) will be populated with the number of bytes transferred.

## See also

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)