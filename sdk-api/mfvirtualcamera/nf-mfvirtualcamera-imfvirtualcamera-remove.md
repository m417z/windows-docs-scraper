## Description

Disables and unregisters the virtual camera from the system. This is the equivalent to physically removing an external camera and uninstalling the driver.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_ACCESSDENIED | The virtual camera is a system wide camera and the caller does not have permissions to remove it. |

## Remarks

Applications that create virtual cameras during their lifetime should ensure that their virtual cameras are removed when the application is uninstalled.

Calling **Remove** while the virtual camera is in use will result in those applications receiving a MF_E_VIDEO_RECORDING_DEVICE_INVALIDATED error.

## See also