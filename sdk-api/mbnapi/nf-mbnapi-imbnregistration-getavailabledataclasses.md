# IMbnRegistration::GetAvailableDataClasses

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the available data classes in the current network.

## Parameters

### `availableDataClasses` [out]

A pointer to a bitwise OR combination of [MBN_DATA_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_data_class) values. This parameter is meaningful only if the function returns **S_OK**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_PENDING** | The data classes are not available. the Mobile Broadband service is currently probing the device for the information. When the data classes are available, the Mobile Broadband service will call the [OnPacketServiceStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onpacketservicestatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the data classes. |

## Remarks

**GetAvailableDataClasses** returns the set of data class possible in the current network. These values can be set to **MBN_DATA_CLASS_NONE** if value is not known.

Available data classes can change automatically as a device moves from one cell to another. Whenever such a change occurs, the Mobile Broadband service will notify applications by calling the [OnPacketServiceStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onpacketservicestatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

For the recoverable error **E_MBN_PIN_REQUIRED**, the Mobile Broadband service will again try to fetch this information from the device when the error condition is over (when a PIN is entered). Afterwards, the Mobile Broadband service will call the [OnPacketServiceStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onpacketservicestatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)