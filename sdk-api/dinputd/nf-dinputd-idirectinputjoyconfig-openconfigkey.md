# IDirectInputJoyConfig::OpenConfigKey

## Description

The **IDirectInputJoyConfig8::OpenConfigKey**  method opens IDirectInputJoyConfig the registry key associated with a joystick configuration. Control panel applications can use this key to store per-joystick persistent information, such as button mappings. Such private information should be kept in a subkey named **OEM**; do not store private information in the main configuration key. The application should use **RegCloseKey** to close the registry key.

## Parameters

### `unnamedParam1`

Indicates a zero-based joystick identification number.

### `unnamedParam2`

Specifies a registry security access mask. This can be any of the values permitted by the **RegOpenKeyEx** function. If write access is requested, then joystick configuration must first be acquired. If only read access is requested, then acquisition is not required. At least one access mask must be specified.

### `unnamedParam3`

Points to the opened registry key on success.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values:

| Return code | Description |
| --- | --- |
| **DIERR_NOTACQUIRED** | Joystick configuration has not been acquired. You must call [IDirectInputJoyConfig8::Acquire](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-acquire) before you can open a joystick type configuration key for writing. |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **DIERR_NOTFOUND** | The application attempted to open the configuration key for reading, but no configuration key for the joystick had been created. Applications should proceed as if the key were empty. |
| **MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ErrorCode)** | A Win32 error code if access to the key is denied because of inappropriate registry permissions or some other external factor. |