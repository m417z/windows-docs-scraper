# IWMProfile3::CreateNewStreamPrioritization

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateNewStreamPrioritization** method creates a new stream prioritization object. After you create a stream prioritization object, use the methods of the [IWMStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization) interface to configure it. The configured stream prioritization object can then be assigned to the profile with a call to [SetStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-setstreamprioritization).

## Parameters

### `ppSP` [out]

Pointer to receive the address of the **IWMStreamPrioritization** interface of the new object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL was passed as *ppSP*. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for the new object. |

## Remarks

A profile can only contain one stream prioritization. When you assign a new stream prioritization to a profile, the previous one will be lost.

## See also

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[Stream Prioritization Object](https://learn.microsoft.com/windows/desktop/wmformat/stream-prioritization-object)