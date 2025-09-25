# IWMRegisteredDevice::Approve

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Approve** method sets the approval state of the device for receiving media data.

## Parameters

### `fApprove` [in]

Set to **TRUE** to approve the device for receiving media data; set to **FALSE** to indicate that the device is not approved.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Approval is a mechanism by which your application can approve a device for playback or prohibit it from being used for playback. A typical scenario would be to ask the user whether the device should be used, and to set approval accordingly.

To receive data, a device must be opened, validated, and approved.

You can find out whether the device is open by calling [IsOpened](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isopened). To open the device call [Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-open).

The device is valid only if proximity detection has been performed on it within the past 48 hours. You can check the validity of the device by calling [IsValid](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isvalid). For more information, see the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) interface.

Call the [IsApproved](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isapproved) method to determine whether the device is approved. Use **Approve** to approve or restrict the device.

## See also

[IWMRegisteredDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice)

[IWMRegisteredDevice::IsApproved](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isapproved)