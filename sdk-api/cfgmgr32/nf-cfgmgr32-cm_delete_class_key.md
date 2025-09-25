# CM_Delete_Class_Key function

## Description

The **CM_Delete_Class_Key** function removes the specified installed [device class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) from the system.

## Parameters

### `ClassGuid` [in]

Pointer to the GUID of the device class to remove.

### `ulFlags` [in]

Delete class key flags:

#### CM_DELETE_CLASS_ONLY

Delete the class only if it does not contain any subkeys.

#### CM_DELETE_CLASS_SUBKEYS

Delete the class and all of its subkeys.

#### CM_DELETE_CLASS_INTERFACE (available only in Windows Vista and later)

Indicates that *ClassGuid* specifies a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) and not a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## See also

[CM_Open_Class_Key](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_open_class_keyw)