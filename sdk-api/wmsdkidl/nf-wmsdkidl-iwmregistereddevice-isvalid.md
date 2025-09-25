# IWMRegisteredDevice::IsValid

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IsValid** method retrieves the validation status of the device.

## Parameters

### `pfValid` [out]

Address of a variable that receives the validation status of the device. **TRUE** indicates that the device is valid. **FALSE** indicates that the device is not valid and needs to be revalidated before it can be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To receive data, a device must be opened, validated, and approved.

You can find out whether the device is open by calling [IsOpened](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isopened). To open the device call [Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-open).

A device is validated by performing proximity detection. For more information, see the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) interface.

Call the [IsApproved](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-isapproved) method to determine whether the device is approved. To approve the device, call the [Approve](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-approve) method.

## See also

[IWMRegisteredDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice)