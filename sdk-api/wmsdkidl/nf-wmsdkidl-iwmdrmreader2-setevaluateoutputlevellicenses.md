# IWMDRMReader2::SetEvaluateOutputLevelLicenses

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**SetEvaluateOutputLevelLicenses** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **SetEvaluateOutputLevelLicenses** method sets the reader to evaluate licenses that use output protection levels (OPLs).

## Parameters

### `fEvaluate` [in]

Flag specifying whether to handle files with licenses that use output protection levels.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If your application supports reading DRM-protected files with licenses that use output protection levels, you must call this method and set *fEvaluate* to **TRUE**. The call must be made before opening the file.

When a file is opened with OPL support enabled, you must call either [GetCopyOutputLevels](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader2-getcopyoutputlevels) or [GetPlayOutputLevels](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader2-getplayoutputlevels), depending on the actions your application performs. These methods provide minimum OPLs for the associated action.

If you do not call this method, the reader object will not open DRM-protected files that have licenses specifying output protection levels.

## See also

[IWMDRMReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader2)