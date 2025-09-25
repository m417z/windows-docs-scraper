# IWMDRMReader::MonitorLicenseAcquisition

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**MonitorLicenseAcquisition** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **MonitorLicenseAcquisition** method, in nonsilent license acquisition, informs the application when a license has been successfully acquired.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method should be used whenever nonsilent license acquisition has been initiated for DRM version 7 content. It is an asynchronous call that returns immediately. This method creates a thread that periodically checks the local license store to determine when the requested license has been received. To cancel the attempt, call **CancelMonitorLicenseAcquisition**.

When the license acquisition is completed (whether successful or otherwise), the application is notified through a **WMT_LICENSE_ACQUIRE** event that is sent to the application's [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method.

## See also

[Handling License Acquisition Events](https://learn.microsoft.com/windows/desktop/wmformat/handling-license-acquisition-events)

[IWMDRMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader)

[IWMDRMReader::CancelMonitorLicenseAcquisition](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader-cancelmonitorlicenseacquisition)

[IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus)