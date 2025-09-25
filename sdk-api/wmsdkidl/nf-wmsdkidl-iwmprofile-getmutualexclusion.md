# IWMProfile::GetMutualExclusion

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMutualExclusion** method retrieves a mutual exclusion object from the profile.

## Parameters

### `dwMEIndex` [in]

**DWORD** containing the index of the mutual exclusion object.

### `ppME` [out]

Pointer to a pointer to the [IWMMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion) interface of the mutual exclusion object specified by the index passed as *dwMEIndex*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory for this operation. |
| **E_INVALIDARG** | *ppME* is **NULL**, or *dwMEIndex* is outside the range of indexes available. |

## Remarks

You can use this method in conjunction with [GetMutualExclusionCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-getmutualexclusioncount) to step through all of the mutual exclusion objects in the profile.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile::AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-addmutualexclusion)

[IWMProfile::RemoveMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-removemutualexclusion)

[Mutual Exclusion](https://learn.microsoft.com/windows/desktop/wmformat/mutual-exclusion)