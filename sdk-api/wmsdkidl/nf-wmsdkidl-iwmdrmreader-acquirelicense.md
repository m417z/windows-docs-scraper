# IWMDRMReader::AcquireLicense

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**AcquireLicense** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **AcquireLicense** method begins the license acquisition process.

## Parameters

### `dwFlags` [in]

**DWORD** containing the relevant flags.

| Flag | Description |
| --- | --- |
| 0x1 | Indicates that the method will attempt to acquire the license silently. |
| 0x0 | Indicates that the **OnStatus** callback will return a URL to use on the Web to acquire a license. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to complete the task. |

## Remarks

This is an asynchronous call that returns immediately.

**For silent acquisition:** When the license acquisition is complete, [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) is called with the *status* parameter set to **WMT_ACQUIRE_LICENSE**. If the license acquisition was successful, the *pvalue* parameter is set to a byte pointer to a [WM_GET_LICENSE_DATA](https://learn.microsoft.com/windows/desktop/wmformat/wm-get-license-data) structure. If there was an error during the license acquisition, the **HRESULT** from the **OnStatus** call holds the appropriate error code.

**For nonsilent acquisition:****OnStatus** will return immediately and send a **WMT_ACQUIRE_LICENSE** event to the application. In that case, the **WM_GET_LICENSE_DATA** structure contains information about the URL to be used to acquire the license.

## See also

[Handling License Acquisition Events](https://learn.microsoft.com/windows/desktop/wmformat/handling-license-acquisition-events)

[IWMDRMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader)

[IWMDRMReader::CancelLicenseAcquisition](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader-cancellicenseacquisition)

[WMT_STATUS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_status)