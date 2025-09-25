# IWMProfile::AddMutualExclusion

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddMutualExclusion** method adds a mutual exclusion object to the profile. Mutual exclusion objects are used to specify a set of streams, only one of which can be output at a time.

## Parameters

### `pME` [in]

Pointer to the [IWMMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion) interface of the mutual exclusion object to include in the profile. You must configure the mutual exclusion object by using the methods of the **IWMMutualExclusion** interface prior to using this method to add the mutual exclusion object to the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The parameter *pME* is **NULL**, or the mutual exclusion type is not CLSID_WMMUTEX_Bitrate. |
| **E_OUTOFMEMORY** | There is not enough available memory to complete this operation. |
| **NS_E_INVALID_STREAM** | A stream number in the mutual exclusion object being added is not part of the profile. |

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile::GetMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-getmutualexclusion)

[IWMProfile::RemoveMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-removemutualexclusion)

[Mutual Exclusion](https://learn.microsoft.com/windows/desktop/wmformat/mutual-exclusion)