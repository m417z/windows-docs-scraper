# IWMProfile2::GetProfileID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProfileID** method retrieves the globally unique identifier of a system profile.

## Parameters

### `pguidID` [out]

Pointer to a GUID specifying the ID of the profile. It the profile is not a system profile, this is set to GUID_NULL.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

System profiles have associated identifiers, but custom profiles do not, therefore this method cannot be used to identify any profile that uses the Windows Media® 9 Series codecs. For more information, see [Reusing Stream Configurations](https://learn.microsoft.com/windows/desktop/wmformat/reusing-stream-configurations).

## See also

[IWMProfile2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)