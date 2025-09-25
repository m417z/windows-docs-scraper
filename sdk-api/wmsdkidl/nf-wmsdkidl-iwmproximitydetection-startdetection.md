# IWMProximityDetection::StartDetection

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**StartDetection** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **StartDetection** method begins the proximity detection process. After calling this method, do not release the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) until you receive the WMT_PROXIMITY_COMPLETED message.

## Parameters

### `pbRegistrationMsg` [in]

Address of the registration message in memory. This message is received by your application from the device.

### `cbRegistrationMsg` [in]

Size of registration message in bytes.

### `pbLocalAddress` [in]

Address of a **SOCKADDR_STORAGE** structure that contains the address of the local network interface to be used during proximity detection. If the *dwExtraPortsAllowed* parameter is not 0, the port number specified in the SOCKADDR_STORAGE structure identifies the beginning of the range of ports that will be tried.

### `cbLocalAddress` [in]

Size of the structure pointed to by *pbLocalAddress*. Set to `sizeof(SOCKADDR_STORAGE)`.

### `dwExtraPortsAllowed` [in]

Specifies the number of additional ports that the method will attempt to use if the previous ports were not successfully used. The method always attempts to use the port specified in the *pbLocalAddress* parameter first. If that attempt fails, then the method makes a number of additional attempts up to the value of this parameter. On each subsequent attempt, the port number is incremented. So if the port number in *pbLocalAddress* is 5000, and *dwExtraPortsAllowed* is set to 20, the method will start with port 5000 and, if necessary, try ports 5001 through 5020.

### `ppRegistrationResponseMsg` [out]

Address of a variable that receives the address of the [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface on the buffer object containing the registration response message. You must send this message data to the device.

### `pCallback` [in]

Address of the [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface that will receive proximity detection status messages.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback. You can use this parameter to differentiate between messages from different objects when sharing a single status callback.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is asynchronous. When proximity detection is complete, a WMT_PROXIMITY_RESULT message is sent to the callback specified by *pCallback*. The completion message is accompanied by an **HRESULT** indicating success or failure.

Regardless of whether the proximity detection completes, the listening thread runs for two minutes, then send the WMT_PROXIMITY_COMPLETED message. Do not release the [IWMProximityDetection](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection) interface until you receive this message.

If this method returns a failure code, no messages are sent to the callback.

## See also

[IWMProximityDetection Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection)