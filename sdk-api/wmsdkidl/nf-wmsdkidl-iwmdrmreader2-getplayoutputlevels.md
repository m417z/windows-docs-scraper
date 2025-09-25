# IWMDRMReader2::GetPlayOutputLevels

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetPlayOutputLevels** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetPlayOutputLevels** method retrieves the output protection levels (OPLs) that apply to the play action in the license of the file loaded in the reader.

## Parameters

### `pPlayOPL` [out]

Address of a [DRM_PLAY_OPL](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_play_opl) structure that receives the output levels that apply to playing content. Additional data is appended to the structure. If you pass **NULL**, the method returns the size of the structure in *pcbLength*.

### `pcbLength` [in, out]

Address of a variable that contains the size of the **DRM_PLAY_OPL** structure in bytes. On input set to the size of the allocated buffer. On return the method sets this value to the size of the structure and any appended data.

### `pdwMinAppComplianceLevel` [out]

Address of a variable that receives the minimum application compliance level.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When reading DRM-protected content, you must verify that the destination of the protected content is allowed by the license. Calling this method enables you to check the output protection level required by the license.

Before you call this method, you must call [SetEvaluateOutputLevelLicenses](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader2-setevaluateoutputlevellicenses) to configure the reader to evaluate licenses that contain output protection levels.

If the OPL information returned by this method indicates that you cannot play the content using the desired technology, you can call [TryNextLicense](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader2-trynextlicense) to find out whether there is another license on the computer that you can use.

## See also

[IWMDRMReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader2)

[IWMDRMReader2::GetCopyOutputLevels](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader2-getcopyoutputlevels)