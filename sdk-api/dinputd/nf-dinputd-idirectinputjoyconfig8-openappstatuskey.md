## Description

The **IDirectInputJoyConfig8::OpenAppStatusKey**  method opens the root key of the application status registry keys, and obtains a handle to the key as a return parameter.

## Parameters

### `unnamedParam1`

Points to the address of a variable (of type HKEY) that will contain a registry key handle if the method succeeds. See Remarks for additional usage details.

## Return value

Returns DI_OK if successful; otherwise, returns one of the following COM error values. The following error codes are intended to be illustrative and not necessarily comprehensive.

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |
| **DIERR_NOTFOUND** | The key is missing on this system. Applications should proceed as if the key were empty. |

## Remarks

The registry key handle returned in the *phKey* parameter can be used with the standard Win32 registry functions. The Dinputd.h header file defines the following string constants for use in accessing subkeys and named values contained by the application status root key.