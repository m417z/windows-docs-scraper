# CM_Open_Device_Interface_Key_ExA function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Open_Device_Interface_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_open_device_interface_keyw) instead.]

The **CM_Open_Device_Interface_Key_ExA** function opens the registry subkey that is used by applications and drivers to store information that is specific to a device interface.

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

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Close the handle returned from this function by calling **RegCloseKey**.

> [!NOTE]
> The cfgmgr32.h header defines CM_Open_Device_Interface_Key_Ex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew)

[SetupDiOpenDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfaceregkey)