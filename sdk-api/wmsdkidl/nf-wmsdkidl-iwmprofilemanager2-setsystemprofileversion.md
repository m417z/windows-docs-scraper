# IWMProfileManager2::SetSystemProfileVersion

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetSystemProfileVersion** method specifies the version number of the system profiles that the profile manager enumerates.

## Parameters

### `dwVersion`

One member of the [WMT_VERSION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_version) enumeration type.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Because there are no system profiles for the Windows Media 9 Series codecs, this method is primarily useful for obtaining version 8 system profiles that you will convert to custom profiles using the Windows Media 9 Series codecs. For more information, see [Reusing Stream Configurations](https://learn.microsoft.com/windows/desktop/wmformat/reusing-stream-configurations).

WMT_VER_4_0 is the default for backward-compatibility only, so be sure to set this to a newer version if it is required. Typically you should set this to WMT_VER_8_0 in order to retrieve the version 8 profiles to use as a starting point for creating your own Windows Media 9 Series profile. If you set it to WMT_VER_9_0, zero profiles will be enumerated.

## See also

[IWMProfileManager2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager2)

[IWMProfileManager2::GetSystemProfileVersion](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager2-getsystemprofileversion)