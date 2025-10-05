# ISensorManager::RequestPermissions

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Opens a system dialog box to request user permission to access sensor data.

## Parameters

### `hParent` [in]

For Windows 8, if *hParent* is provided a value, then the dialog will be modal to the parent window. If *hParent* is **NULL**, then the dialog will not be modal. The dialog is always synchronous.

For Windows 7, **HWND** is handle to a window that can act as a parent to the permissions dialog box. Must be **NULL** if *fModal* is **TRUE**.

### `pSensors` [in]

For Windows 8, this value is not used.

For Windows 7, *pSensors* is a pointer to the [ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection) interface that contains the list of sensors for which permission is being requested.

### `fModal` [in]

For Windows 8, this value is not used. Refer to *hParent* for control of modality.

For Windows 7, *fModal* is a **BOOL** that specifies the dialog box mode. Must be **FALSE** if *hParent* is non-null.

| Value | Meaning |
| --- | --- |
| **TRUE** | If *hParent* is **NULL**, the dialog box is modal and therefore has exclusive focus in Windows until the user responds. The call is synchronous. The return code indicates the user choice. See Return Value. <br><br>If *hParent* is non-null, the call is asynchronous and the calling thread will not wait for the dialog box to be closed. The return code indicates whether the call succeeded. See Return Value. |
| **FALSE** | The dialog box is modeless. The call is asynchronous and the calling thread will not wait for the dialog box to be closed. The return code indicates whether the call succeeded. See Return Value.<br><br>The *hParent* parameter is ignored. |

## Return value

The following table describes return codes for synchronous results.

| Return code | Description |
| --- | --- |
| **S_OK** | The user enabled the sensors. |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)** | The user chose to disable the sensors. |
| **HRESULT_FROM_WIN32(ERROR_CANCELLED)** | The user canceled the dialog box or refused elevation of permission to show the dialog box. |

The following table describes return codes for asynchronous results.

| Return code | Description |
| --- | --- |
| **S_OK** | All of the sensors in the sensor collection were displayed for the user to enable. The method succeeded. |
| **S_FALSE** | Some of the sensors in the sensor collection were displayed for the user to enable. Some sensors may have been removed from the collection; for example, because the user had previously chosen to keep them disabled. The method succeeded. |
| **E_INVALIDARG** | An argument is not valid. |
| **E_POINTER** | A pointer is null. |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)** | All sensors in the sensor collection were previously disabled by the user. The dialog box was not shown. |

## Remarks

Making a synchronous call from the user interface (UI) thread of a Windows application can block the UI thread and make the application less responsive. To prevent this, do not call this method from the UI thread with *fModal* set to **TRUE**.

**Note**

If an application or plugin that is running in protected mode, such as a Browser Helper Object (BHO) for Internet Explorer when Internet Explorer is running in protected mode, calls **RequestPermissions**, and the user chooses the **Don't enable this location sensor** option in the dialog box, Windows will display the dialog box again if **RequestPermissions** is called again by the same user. Applications that run in protected mode may choose to avoid calling **RequestPermissions** on startup so that the user will not be subjected to a possible unwanted dialog box each time the application starts.

#### Examples

The following example code requests permissions for all sensors retrieved from the sensor manager, by type, using an asynchronous method call. The platform will only prompt the user to enable sensors that are not already enabled. To determine whether the user enabled any sensors in this case, you must handle the [ISensorEvents::OnStateChanged](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensorevents-onstatechanged) event. For additional examples that demonstrate how to request permissions, see [Requesting User Permissions](https://learn.microsoft.com/windows/desktop/SensorsAPI/requesting-user-permissions).

```cpp
// Get the sensor collection.
hr = pSensorManager->GetSensorsByType(SAMPLE_SENSOR_TYPE_TIME, &pSensorColl);

if(SUCCEEDED(hr))
{
    // Request permissions for all sensors
    // in the collection.
    hr = pSensorManager->RequestPermissions(0, pSensorColl, FALSE);
}

```

## See also

[ISensorManager](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanager)

[Managing User Permissions](https://learn.microsoft.com/windows/desktop/SensorsAPI/managing-user-permissions)

[Requesting User Permissions](https://learn.microsoft.com/windows/desktop/SensorsAPI/requesting-user-permissions)