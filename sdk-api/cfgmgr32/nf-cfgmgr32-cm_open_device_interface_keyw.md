# CM_Open_Device_Interface_KeyW function

## Description

The **CM_Open_Device_Interface_Key** function opens the registry subkey that is used by applications and drivers to store information that is specific to a device interface.

## Parameters

### `pszDeviceInterface` [in]

Pointer to a string that identifies the device interface instance to open the registry subkey for.

### `samDesired` [in]

The requested registry security access to the registry subkey.

### `Disposition` [in]

Specifies how the registry key is to be opened. May be one of the following values:

#### RegDisposition_OpenAlways

Open the key if it exists. Otherwise, create the key.

#### RegDisposition_OpenExisting

Open the key only if it exists.

### `phkDeviceInterface` [out]

Pointer to an HKEY that will receive the opened key upon success.

### `ulFlags` [in]

Reserved. Must be set to zero.

##### - Disposition.RegDisposition_OpenAlways

Open the key if it exists. Otherwise, create the key.

##### - Disposition.RegDisposition_OpenExisting

Open the key only if it exists.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Close the handle returned from this function by calling **RegCloseKey**.

> [!NOTE]
> The cfgmgr32.h header defines CM_Open_Device_Interface_Key as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiOpenDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfaceregkey)