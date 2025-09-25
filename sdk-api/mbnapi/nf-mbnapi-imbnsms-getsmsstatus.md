# IMbnSms::GetSmsStatus

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the SMS status for a device.

## Parameters

### `smsStatusInfo` [out]

A pointer to a [MBN_SMS_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_status_info) structure, containing the status information for the device.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The SMS status is not available. The Mobile Broadband service is probing the device for the information. The calling application can be notified when the SMS status is available by registering for the [OnSmsStatusChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsstatuschange) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface. |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get this information. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

For recoverable errors such as **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for this information when error condition is over. For example, if the device required a PIN to be entered to retrieve this information then it will return **E_MBN_PIN_REQUIRED**. When an application enters the PIN to unlock the device then the Mobile Broadband service will again try to get this information from the device. The Mobile Broadband service will call the [OnSmsStatusChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsstatuschange) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface

The SMS Message store status can change because of new message received by the system. On any change in the message store status, the Mobile Broadband service will call the [OnSmsStatusChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsstatuschange) method of the [IMbnSmsEvent](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

Application issued operations such as the reading or deleting of messages may reset **flag** in [MBN_SMS_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_status_info) structure. A change in the SMS store caused by this reset will not result in the calling of any notification method.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)