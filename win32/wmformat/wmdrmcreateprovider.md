# WMDRMCreateProvider function

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMCreateProvider** function creates a class factory that can create the other objects of the Windows Media DRM Client Extended APIs. This function does not require a stub library from Microsoft and creates objects that do not support the protected DRM features.

## Parameters

*ppDRMProvider* \[out\]

Receives a pointer to the [**IWMDRMProvider**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmprovider) interface of the newly created object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|--------------------------------------------------------------------------------------|----------------------------------|
| **S\_OK** | The method succeeded.<br> |

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |
| Library<br> | Wmdrmsdk.lib |
| DLL<br> | Wmdrmsdk.dll |

## See also

[**Functions**](https://learn.microsoft.com/windows/win32/wmformat/drm-functions)

[**WMDRMCreateProtectedProvider**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmcreateprotectedprovider)

