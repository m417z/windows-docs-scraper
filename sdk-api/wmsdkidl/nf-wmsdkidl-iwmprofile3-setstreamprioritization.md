# IWMProfile3::SetStreamPrioritization

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetStreamPrioritization** method assigns a stream prioritization object to the profile. A profile can contain only one stream prioritization object at a time.

## Parameters

### `pSP` [in]

Pointer to the [IWMStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamprioritization) interface of the stream prioritization object you want to assign to the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALID_ARG** | *pSP* is **NULL**.<br><br>OR<br><br>The method was unable to validate the stream prioritization object. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory in the profile for the object. |

## Remarks

If there is already a stream prioritization object in the profile, it will be lost.

## See also

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::GetStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-getstreamprioritization)

[IWMProfile3::RemoveStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-removestreamprioritization)