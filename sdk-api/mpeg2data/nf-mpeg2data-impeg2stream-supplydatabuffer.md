# IMpeg2Stream::SupplyDataBuffer

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SupplyDataBuffer** method provides a buffer for the **Mpeg2Stream** object to write data.

## Parameters

### `pStreamBuffer` [in]

Pointer to an [MPEG_STREAM_BUFFER](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_stream_buffer) structure allocated by the caller. This structure contains a pointer to the buffer, also allocated by the caller. The buffer must be at least 4096 bytes.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument or **NULL** parameter. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | Failure. |

## Remarks

The first time this method is called, it starts a worker thread that streams data to the buffer. When the data arrives, the **MPEG2Stream** object signals the event that was passed to the [IMpeg2Stream::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-impeg2stream-initialize) method. (Typically an application specifies the event handle when it calls [IMpeg2Data::GetStreamOfSections](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-impeg2data-getstreamofsections).)

When the event is signaled, examine the **hr** field of the **MPEG_STREAM_BUFFER** structure. If this value is a success code, the request was successful and the buffer contains valid data. To get more data, call the **SupplyDataBuffer** method again and wait for the event to be signaled.

The section headers are not converted from network byte order or otherwise processed.

If the object is still waiting for data, this method returns E_FAIL.

## See also

[IMpeg2Stream Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2stream)