# IMbnSms::SmsSendCdmaPdu

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sends a message in CDMA binary format.

## Parameters

### `message` [in]

Byte array representing the encoded CMDA message as per section 3.4.2.1 "SMS Point-to-Point Message” in 3GPP2 specification C.S0015-A “Short Message Service (SMS) for Wideband Spread Spectrum Systems”. SMS will only support the Wireless Messaging Teleservice (WMT) format.

### `requestID` [out]

A pointer to a request ID issued by the Mobile Broadband service to identify this request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the device was removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |
| **E_INVALIDARG** | *message* is invalid. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support sending SMS messages in the requested format. For example, if this function is called for a GSM device. |

## Remarks

This method is applicable only to CDMA devices.

**SmsSendCdmaPdu** can be used to send a SMS message in binary format encoded as per section 3.4.2.1 of "SMS Point-to-Point Message” in 3GPP2 specification C.S0015-A “Short Message Service (SMS) for Wideband Spread Spectrum Systems”. SMS will only support Wireless Messaging Teleservice (WMT) format.

**SmsSendCdmaPdu** should be called only when the CDMA device supports sending SMS in binary format. The device reports this format by setting **MBN_SMS_PDU_SEND** in [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps).

This is an asynchronous operation and method call will return immediately. If method returns without any error then operation will be performed asynchronously. Windows will notify applications about completion status of operation by calling the [OnSmsSendComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmssendcomplete) method of [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents).

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)