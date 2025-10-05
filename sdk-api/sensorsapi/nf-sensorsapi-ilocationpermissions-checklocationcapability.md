# ILocationPermissions::CheckLocationCapability

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Gets the location capability of the Windows Store app of the given thread

## Parameters

### `dwClientThreadId`

Thread Id of the app to check the location capability of

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded and the app is location enabled. |
| **E_ACCESSDENIED** | The app has not declared location capability or the user has declined or revoked location access. |
| **E_ILLEGAL_METHOD_CALL** | An invalid client thread was provided. |

## Remarks

**Note** **CheckLocationCapability** is available in Windows 8.

For more information on location settings in Windows 8 see [Location settings](https://learn.microsoft.com/previous-versions/windows).

## See also

[ILocationPermissions](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-ilocationpermissions)