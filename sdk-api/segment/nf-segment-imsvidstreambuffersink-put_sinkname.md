# IMSVidStreamBufferSink::put_SinkName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_SinkName** method sets the name of the stub file that points to the backing files.

## Parameters

### `Name` [in]

Specifies the file name.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The method succeeded. |

## Remarks

Call this method before calling [NameSetLock](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidstreambuffersink-namesetlock), while the graph is stopped. Otherwise, the method fails and returns E_FAIL.

## See also

[Buffering in the Stream Buffer Engine](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/buffering-in-the-stream-buffer-engine)

[IMSVidStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersink)