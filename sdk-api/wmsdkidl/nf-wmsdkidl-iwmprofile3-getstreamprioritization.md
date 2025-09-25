# IWMProfile3::GetStreamPrioritization

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamPrioritization** method retrieves the stream prioritization that exists in the profile.

## Parameters

### `ppSP` [out]

Pointer to receive the address of the [IWMStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization) interface of the stream prioritization object in the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *ppSP* is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for the stream prioritization object |

## Remarks

Many profiles do not have a stream prioritization assigned to them. If you call **GetStreamPrioritization** on such a profile, no error is returned, but the retrieved address is **NULL**.

## See also

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::RemoveStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-removestreamprioritization)

[IWMProfile3::SetStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-setstreamprioritization)

[IWMStreamPrioritization Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization)

[Stream Prioritization Object](https://learn.microsoft.com/windows/desktop/wmformat/stream-prioritization-object)