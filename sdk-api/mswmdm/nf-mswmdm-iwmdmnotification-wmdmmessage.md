# IWMDMNotification::WMDMMessage

## Description

The **WMDMMessage** method is a callback method implemented by a client, and called by Windows Media Device Manager when a Plug and Play compliant device or storage medium is connected or removed.

## Parameters

### `dwMessageType` [in]

A **DWORD** specifying the message type.

The possible values for the event types are the following:

| Message type | Description |
| --- | --- |
| WMDM_MSG_DEVICE_ARRIVAL | A device has been connected. |
| WMDM_MSG_DEVICE_REMOVAL | A device has been removed. |
| WMDM_MSG_MEDIA_ARRIVAL | A storage medium has been inserted in a connected device. |
| WMDM_MSG_MEDIA_REMOVAL | A storage medium has been removed from a connected device. |

### `pwszCanonicalName` [in]

Pointer to a wide-character, null-terminated string specifying the canonical name of the device for which this event is generated. The application does not release this value.

## Return value

The return value is an **HRESULT** in which application can return results of its processing of the message. The return value is ignored by WMDM.

## Remarks

To learn how an application subscribes to receive notifications through this method, see [Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications).

#### Examples

The following C++ code implements the **WMDMMessage** method, and prints out a device or storage arrival or departure notification message.

```cpp

HRESULT WMDMMessage(DWORD  dwMessageType, LPCWSTR  pwszCanonicalName)
{
    switch(dwMessageType)
    {
    case WMDM_MSG_DEVICE_ARRIVAL:
        // TODO: Display a message indicating that a new device has been detected and display the device name.
        break;
    case WMDM_MSG_DEVICE_REMOVAL:
        // TODO: Display a message that the device has been removed and display the device name.
        break;
    case WMDM_MSG_MEDIA_ARRIVAL:
        // TODO: Display a message indicating that storage media has been added to the device and display the device name.
        break;
    case WMDM_MSG_MEDIA_REMOVAL:
        // TODO: Display a message that storage media has been removed from the device and display the device name.
        break;
    default:
        // TODO: Display a message indicating that an unidentified message has been received.
        break;
    }
    return S_OK; // Return value is ignored, and not returned to the application.
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMNotification Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmnotification)