# IWMDeviceRegistration::GetNextRegisteredDevice

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetNextRegisteredDevice** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetNextRegisteredDevice** method enumerates the registered devices of a specified type.

## Parameters

### `ppDevice` [out]

Address of a variable that receives a pointer to an [IWMRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice) interface. This interface provides access to information about a registered device in the database that matches the type specified by the *dwRegisterType* parameter used in the call to [GetFirstRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdeviceregistration-getfirstregistereddevice). The information applies to the next device in the list (after the device retrieved previously).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more devices of the specified type in the list. When this value is returned, the address pointed to by *ppDevice* is set to **NULL**. |
| **E_INVALIDARG** | The *ppDevice* parameter is **NULL**. |

## Remarks

To enumerate registered devices of a given type, begin by calling [GetFirstRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdeviceregistration-getfirstregistereddevice) to retrieve the first device. Then make repeated calls to this method to get subsequent devices from the list. After all devices of the specified types have been retrieved, the next call to **GetNextRegisteredDevice** returns S_FALSE and the address pointed to by *ppDevice* is set to **NULL**.

## See also

[IWMDeviceRegistration Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdeviceregistration)