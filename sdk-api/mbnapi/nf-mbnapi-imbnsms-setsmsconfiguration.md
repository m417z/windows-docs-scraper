# IMbnSms::SetSmsConfiguration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Updates the SMS configuration for a device.

## Parameters

### `smsConfiguration` [in]

An [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) interface representing the new SMS configuration to update the device with.

### `requestID` [out]

A pointer to a request ID issued by the Mobile Broadband service to identify this request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on the system. |
| **E_HANDLE** | The interface is invalid, most likely because the device was removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |

## Remarks

An application can use **SetSmsConfiguration** to modify the default SMS Service Center address in the device.

An application should perform following steps for setting SMS configuration of the device.

1. Get an [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) interface by calling [GetSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsms-getsmsconfiguration).
2. Modify the [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) interface obtained from step 1 with the new values that reflect the desired changes to the configuration..
3. Pass the modified [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) to **SetSmsConfiguration**.

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnSetSmsConfigurationComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsetsmsconfigurationcomplete) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)

[IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration)