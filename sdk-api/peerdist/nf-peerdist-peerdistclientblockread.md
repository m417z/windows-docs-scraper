# PeerDistClientBlockRead function

## Description

The **PeerDistClientBlockRead** function reads content data blocks.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentHandle` [in]

A content handle opened by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent) function call.

### `cbMaxNumberOfBytes`

The maximum number of bytes to read. If the *cbMaxNumberOfBytesToRead* is equal to 0, it indicates that the **PeerDistClientBlockRead** function is querying the length of available consecutive content bytes in the local cache at the current block read offset. The query will neither download content from the peers, nor return the count of bytes present in the peer cache.

### `pBuffer` [in, out, optional]

Pointer to the buffer that receives the data from the local cache. This buffer must remain valid for the duration of the read operation. The caller must not use this buffer until the read operation is completed. If the *cbMaxNumberOfBytesToRead* argument is equal to 0, the *pBuffer* parameter can be **NULL**

### `dwTimeoutInMilliseconds`

Timeout value for the read, in milliseconds. There are two special values that may be specified:

| Value | Meaning |
| --- | --- |
| **PEERDIST_READ_TIMEOUT_LOCAL_CACHE_ONLY** | Specifies that a read should not cause any additional network traffic by contacting peers or a Hosted Cache. |
| **PEERDIST_READ_TIMEOUT_DEFAULT** | Specifies the default timeout of 5 seconds. |

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. The start offset for read is specified by setting the **Offset** and **OffsetHigh** members of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The **OffsetHigh** member should be set to the higher 32 bits of the start offset and the **Offset** member should be set to the lower 32 bits of the start offset.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hContent* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

**PeerDistClientBlockRead** queues the read and immediately returns to the caller. As a result, multiple reads can be issued simultaneously.
**PeerDistClientBlockRead** will complete a read as soon as any data is available and will not wait for the buffer to fill completely.

If the **PeerDistClientBlockRead** function operation completes successfully, the **Offset** and **OffsetHigh** fields of the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure will be populated with the **ULONGLONG** offset at which the read started. The OffsetHigh member will be set to the higher 32 bits of the offset and the Offset member will be set to the lower 32 bits of the offset. [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) will populate *lpNumberOfBytesTransferred* with the number of bytes transferred. In the event the caller is using a completion port to process Peer Distribution API completions then the *lpNumberOfBytes* argument of [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) will be populated with the number of bytes transferred.

If the *cbMaxNumberOfBytesToRead* argument is equal to 0, and the **PeerDistClientBlockRead** function completes successfully, the number of bytes transferred (obtained via either [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)) will contain the actual length of content available in the local cache.

When this API completes with error values **PEERDIST_ERROR_MISSING_DATA** or **ERROR_TIMEOUT**, the **Offset** and **OffsetHigh** fields of the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure specify the **ULONGLONG** offset at which the missing data range begins. The OffsetHigh member will be set to the higher 32 bits of the offset and the Offset member will be set to the lower 32 bits of the offset. This missing data range is the start offset (relative to start of the content) and length, in bytes, which needs to be retrieved from an alternate source, like the original content server. In order to allow the Peer Distribution service to satisfy the same read in the future, add this data to the local cache by calling PeerDistClientAddData. The length of the missing data range is specified by the number of bytes transferred (obtained via [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)).

It is important to note that the missing data range can start at any offset in the content and be any length up to the end of the content. In the event the content information passed to [PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation) was generated in response to a range request, then the missing data range will be constrained to the range request bounds. This occurs when the call to [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation) on the content server specified an offset and a length which was a sub-range of the content as a whole. A completion with **ERROR_NO_MORE** in this case indicates that the read offset is outside of the sub-range of the content.

### Range Requests

If a client is interested in only a portion of the original content, a range request can be used to retrieve that portion. A range request contains an offset and length of the original content. The size of the content information is directly proportional to the size of the content requested.

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation) supports generating content information for a range request via the ullContentOffset and *cbContentLength* parameters. The *ullContentOffset* parameter represents the offset in the original content where the range begins and *cbContentLength* represents the length of the range.

Once a client obtains content information representing a particular content range, that content information works seamlessly with the [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent), [PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation) and [PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation) APIs. The content information can be passed to [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation) and will associate the **PEERDIST_CONTENT_HANDLE** with the content range. [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) is constrained by the *ullContentOffset* offset and *cbContentLength* length specified in the server side call to [PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation). **PeerDistClientStreamRead** will begin at *ullContentOffset* and will complete with the error code **PEERDIST_ERROR_NO_MORE** when the end of the content range is reached at *ullContentOffset* + *cbContentLength*. **PeerDistClientBlockRead** will complete with the error code **PEERDIST_ERROR_NO_MORE** if the offset specified in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) parameter is less than *ullContentOffset* or greater than *ullContentOffset* + *cbContentLength*. **PeerDistClientStreamRead** and **PeerDistClientBlockRead** both limit the amount of missing data reported to the content range specified in the content information associated with the **PEERDIST_CONTENT_HANDLE**. For example, if the content information represents only the first half of the content, missing data will be limited to the first half of the content. In all other respects, **PeerDistClientBlockRead** and **PeerDistClientStreamRead** work with content ranges in exactly the same manner in which they work with the content as a whole.

A client can use [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) or **PeerDistClientBlockRead** to retrieve the content from the offset specified by the *ullContentOffset* up to the length specified by *cbContentLength* in the [PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation) call. Both **PeerDistClientStreamRead** and **PeerDistClientBlockRead** will complete with **PEERDIST_ERROR_NO_MORE** if the client tries to read beyond the range specified by the *ullContentOffset* and *cbContentLength*. Additionally, **PeerDistClientBlockRead** will also complete with the error code **PEERDIST_ERROR_NO_MORE** if the offset specified in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) parameter is less than *ullContentOffset*

If the read cannot not be completed from either the local cache or the peer cache, both [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) and **PeerDistClientBlockRead** will report **PEERDIST_ERROR_MISSING_DATA**. When using the ranged content information, **PeerDistClientStreamRead** will report a missing data from the start offset of the range up to the end of the range. **PeerDistClientBlockRead** will report missing data from start offset of the range up to the end of the range.

[PeerDistClientAddData](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientadddata) allows content data to be added even if it lies outside the content range. This extended data will be validated after the corresponding content information has been added to the local cache. Once validated, it becomes available to peers. In other words, if a client adds only content information for the first half of content, **PeerDistClientAddData** still allows the client to add data for the entire content. However, the second half of the content will not be validated until the corresponding content information for the second half has been added. No other Peer Distribution APIs are affected by range requests.

## See also

[PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)