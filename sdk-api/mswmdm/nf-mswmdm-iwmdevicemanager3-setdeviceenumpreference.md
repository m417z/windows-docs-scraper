# IWMDeviceManager3::SetDeviceEnumPreference

## Description

The **SetDeviceEnumPreference** method sets the device enumeration preferences.

## Parameters

### `dwEnumPref` [in]

Specifies a bitwise **OR** combination of one or more of the following bit values that specify enumeration preference. Each set bit enables the corresponding extended behavior, whereas the absence of that bit disables the extended behavior and specifies the default, backward-compatible enumeration behavior. The possible values for *fuPrefs* are provided in the following table.

| Value | Description |
| --- | --- |
| DO_NOT_VIRTUALIZE_STORAGES_AS_DEVICES | By default, for devices containing multiple storage media (for example, multiple flash memory cards), each of these storages enumerates as a separate pseudo-device. However, when this flag is set, storages are not visible as devices, and only devices are visible as devices. See Remarks for more information. |
| ALLOW_OUTOFBAND_NOTIFICATION | When this flag is set, the service provider can send device arrival and removal by an additional mechanism, such as by using a window message, as well as the default mechanism of calling any application-implemented [IWMDMNotification](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmnotification) interfaces. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *fuPrefs* parameter specifies an unsupported bit value. |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | The method was called after an enumeration operation; it must be called before the enumeration operation. |

## Remarks

This method provides clients the ability to override the default device enumeration behavior of Windows Media Device Manager. In order to override the default behavior, the client application must call this method immediately after creating the device manager object by querying for the **IWMDMDeviceManager3** interface from Media Device Manager. The call must be made before any enumeration occurs, either explicitly or implicitly as a result of another operation.

After a preference flag is set, it cannot be changed for the lifetime of the application (not just the lifetime of the Windows Media Device Manager object). Attempting to change a preference flag will result in an error. Calling this method again with the same flag settings does not return an error, and also does have any effect on enumeration.

The service provider may not honor the DO_NOT_VIRTUALIZE_STORAGES_AS_DEVICES flag. A more robust way to determine if storages are hosted by the same device is to call [IWMDMDevice2::GetCanonicalName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice2-getcanonicalname). Storages from the same device will return identical values, except for the final digit after the last "$" character.

## See also

[IWMDMDevice2::GetCanonicalName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice2-getcanonicalname)