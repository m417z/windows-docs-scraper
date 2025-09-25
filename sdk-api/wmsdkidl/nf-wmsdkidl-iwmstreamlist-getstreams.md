# IWMStreamList::GetStreams

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreams** method retrieves an array of stream numbers that make up the list.

## Parameters

### `pwStreamNumArray` [out]

Pointer to a **WORD** array containing the stream numbers. Pass **NULL** to retrieve the required size of the array.

### `pcStreams` [in, out]

On input, a pointer to a variable containing the size of the *pwStreamNumArray* array. On output, if the method succeeds, this variable contains the number of stream numbers entered into *pwStreamNumArray* by the method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pcStreams* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The input value of *pcStreams* is not large enough. |

## Remarks

You should make two calls to **GetStreams**. On the first call, pass **NULL** as *pwStreamNumArray*. On return, the value pointed to by *pcStreams* is set to the number of stream numbers in the stream number array. Then you can allocate the required amount of memory for the array and pass a pointer to it as *pwStreamNumArray* on the second call.

Stream numbers are in the range of 1 through 63.

## See also

[IWMStreamList Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamlist)