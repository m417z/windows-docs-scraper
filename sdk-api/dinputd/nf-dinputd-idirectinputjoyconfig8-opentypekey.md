# IDirectInputJoyConfig8::OpenTypeKey

## Description

The **IDirectInputJoyConfig8::OpenTypeKey**  method opens the registry key associated with a joystick type.

## Parameters

### `unnamedParam1`

Points to the name of the type. The name of the type cannot exceed MAX_PATH characters, including the terminating null character. The name cannot begin with a "#" character. Types beginning with "#" are reserved by DirectInput.

### `unnamedParam2`

Specifies a registry security access mask. This can be any of the values permitted by the **RegOpenKeyEx** function. If write access is requested, then joystick configuration must first have been acquired. If only read access is requested, then acquisition is not required.

### `unnamedParam3`

Points to the opened registry key, on success.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can open a joystick type configuration key for writing. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ErrorCode)** | A Win32 error code if access to the key is denied by registry permissions or some other external factor. |

## Remarks

Control panel applications can use the registry key opened by this method to store per-type persistent information, such as global configuration parameters. Such private information should be kept in a subkey named **OEM**; do not store private information in the main type key. Control panel applications can also use this key to read configuration information, such as the strings to use for device calibration prompts. The application should use **RegCloseKey** to close the registry key.