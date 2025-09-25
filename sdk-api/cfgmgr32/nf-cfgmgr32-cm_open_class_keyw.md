# CM_Open_Class_KeyW function

## Description

The **CM_Open_Class_Key** function opens the device setup class registry key, the device interface class registry key, or a specific subkey of a class.

## Parameters

### `ClassGuid` [in, optional]

Pointer to the GUID of the class whose registry key is to be opened. This parameter is optional and can be NULL. If this parameter is NULL, the root of the class tree is opened.

### `pszClassName` [in, optional]

Reserved. Must be set to NULL.

### `samDesired` [in]

The registry security access for the key to be opened.

### `Disposition` [in]

Specifies how the registry key is to be opened. May be one of the following values:

#### RegDisposition_OpenAlways

Open the key if it exists. Otherwise, create the key.

#### RegDisposition_OpenExisting

Open the key only if it exists.

### `phkClass` [out]

Pointer to an HKEY that will receive the opened key upon success.

### `ulFlags` [in]

Open class key flags:

#### CM_OPEN_CLASS_KEY_INSTALLER

The key to be opened is for a device setup class.

#### CM_OPEN_CLASS_KEY_INTERFACE

The key to be opened is for a device interface class.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Close the handle returned from this function by calling **RegCloseKey**.

## See also

[CM_Delete_Class_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_delete_class_key)

[SetupDiOpenClassRegKeyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopenclassregkeyexa)