# IMbnSms::SmsSendPdu

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sends a message in PDU format.

## Parameters

### `pduData` [in]

A string representing the PDU message in hexadecimal format.

### `size` [in]

The size of PDU message in number of bytes before converting to hexadecimal string format and excluding the service center address length.

### `requestID` [out]

A pointer to a request ID issued by the Mobile Broadband service to identify this request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *pduData* or *size* are invalid. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the device was removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support sending SMS messages in the requested format. For example, if this function is called for a CDMA device. |

## Remarks

 This data in *pduData* is compliant to the PDU structure defined in 3GPP TS 27.005 and 3GPP TS 23.040.

The table below shows an example of how a PDU message containing the message "Hello" would be structured.

|  |  |  |  |
| --- | --- | --- | --- |
| Example | 07 | 91198994000010 | 11000A9189945086180000AA05C8329BFD06 |
| Contents | Size of Service Center Address | Service Center Address | PDU in hexadecimal format |
| Size | 1 byte | Variable | Variable |

This function should be called only for GSM devices that support sending SMS in PDU format. A device reports this ability by setting **MBN_SMS_CAPS_PDU_SEND** in [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps).

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnSmsSendComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmssendcomplete) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)