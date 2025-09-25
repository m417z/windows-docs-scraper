# IMDServiceProvider3::SetDeviceEnumPreference

## Description

The **SetDeviceEnumPreference** method sets the device enumeration preferences.

## Parameters

### `dwEnumPref` [in]

Contains a bitwise **OR** combination of one or more of the following bit values that specify enumeration preference. Each set bit enables the corresponding extended behavior, whereas the absence of that bit disables the extended behavior and specifies the default, backward-compatible enumeration behavior. The possible values for *dwEnumPref* are provided in the following table.

| Value | Description |
| --- | --- |
| DO_NOT_VIRTUALIZE_STORAGES_AS_DEVICES | By default, for devices containing multiple storage media, each of these storages enumerates as a separate pseudo-device. However, when this bit is set, storages are not visible as devices, and only devices are visible as devices. |
| ALLOW_OUTOFBAND_NOTIFICATION | By default, the [IWMDMNotification](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmnotification) callback mechanism provides applications with device arrival and removal events. When this bit is set, the service provider is free to notify the application by a separate mechanism, such as by using a window message. This behavior is in addition to the Windows Media Device Manager notifications. This flag does not suppress Windows Media Device Manager notifications. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwEnumPref* parameter contains an unsupported bit value. |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | The method was called after an enumeration operation. It must be called before the enumeration operation. |

## Remarks

This API provides clients the ability to override the default device enumeration behavior of Windows Media Device Manager.

Client applications must call this method immediately after creating the device manager object by querying for the [IWMDeviceManager](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager) interface from Windows Media Device Manager. The call must be made before any enumeration occurs, either explicitly or implicitly as a result of another operation.

After a preference flag is set, it cannot be changed for the lifetime of the application (not just the lifetime of the Windows Media Device Manager object). Attempting to change a preference flag will result in an error. Calling this API again with the same flag settings does not return an error, and also does have any effect on enumeration.

The DO_NOT_VIRTUALIZE_STORAGES_AS_DEVICES flag has to be honored by the service provider to take effect. It is possible that, despite this flag, some devices are enumerated as a device-per-storage.

## See also

[IMDServiceProvider3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider3)