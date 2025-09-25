# IWMRegisteredDevice::IsApproved

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IsApproved** method retrieves the approval status of the device. Approved devices are able to receive and play media data.

## Parameters

### `pfApproved` [out]

Address of a variable that receives the device approval status. **TRUE** indicates approval.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To receive data, a device must be opened, validated, and approved.

You can find out whether the device is open by calling [IsOpened](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isopened). To open the device call [Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-open).

The device is valid only if proximity detection has been performed on it within the past 48 hours. You can check the validity of the device by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isvalid). For more information, see the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) interface.

Use this method to discover whether the device is approved. To approve the device, call the [Approve](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-approve) method.

## See also

[IWMRegisteredDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice)