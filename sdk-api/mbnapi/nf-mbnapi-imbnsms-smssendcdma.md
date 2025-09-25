# IMbnSms::SmsSendCdma

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sends a message in CDMA format.

## Parameters

### `address` [in]

A null terminated string that contains the receiver's phone number. The maximum size of the string is 15 digits.

### `encoding` [in]

A [MBN_SMS_CDMA_ENCODING](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_cdma_encoding) value that specifies the data encoding.

### `language` [in]

An [MBN_SMS_CDMA_LANG](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_cdma_lang) value that specifies the language.

### `sizeInCharacters` [in]

The number of encoded characters in the message. This can be different from the size of the message array.

### `message` [in]

An array of bytes containing the encoded CDMA message.

The maximum size of this array is the [CdmaShortMsgSize](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsconfiguration-get_cdmashortmsgsize) property of [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration), however this can be no larger than **MBN_CDMA_SHORT_MSG_SIZE_MAX** (160).

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
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support sending SMS messages in the requested format. For example, if this function is called for a GSM device. |

## Remarks

This method can be used to send a SMS message for a CDMA device. However, this is only when the CDMA device supports sending SMS. A calling application can learn if the device supports this format by calling the [GetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getinterfacecapability) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface). It can then look for **MBN_SMS_CAPS_TEXT_SEND** in the **smsCaps** member of [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps).

The *address* parameter can be in either of these formats.

* "+ <International Country Code> <SMS Service Center Number>\0"
* "<SMS Service Center Number>\0"

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnSmsSendComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmssendcomplete) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)