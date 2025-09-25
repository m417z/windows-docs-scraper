# IMbnSms::GetSmsConfiguration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the SMS configuration of a device.

## Parameters

### `smsConfiguration` [out, retval]

An [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) interface representing the SMS configuration of the device.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The SMS configuration is not available. The Mobile Broadband service is probing the device for the information. The calling application can be notified when the SMS configuration is available by registering for the [OnSmsConfigurationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsconfigurationchange) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface. |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get this information. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | SMS is not supported by the device. |

## Remarks

For recoverable errors such as **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for this information when error condition is over. For example, if the device required a PIN to be entered to retrieve this information then it will return **E_MBN_PIN_REQUIRED**. When an application enters the PIN to unlock the device then the Mobile Broadband service will again try to get this information from the device. The Mobile Broadband service will call the [OnSmsConfigurationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsconfigurationchange) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface

SMS configuration can be updated by the network or device without any change request by any application. In such a case, the Mobile Broadband service will notify all the registered applications by calling the [OnSmsConfigurationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsconfigurationchange) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)