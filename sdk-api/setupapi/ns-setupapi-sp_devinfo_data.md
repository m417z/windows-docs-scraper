# SP_DEVINFO_DATA structure

## Description

An SP_DEVINFO_DATA structure defines a device instance that is a member of a device information set.

## Members

### `cbSize`

The size, in bytes, of the SP_DEVINFO_DATA structure. For more information, see the following Remarks section.

### `ClassGuid`

The GUID of the device's setup class.

### `DevInst`

An opaque handle to the device instance (also known as a handle to the [devnode](https://learn.microsoft.com/windows-hardware/drivers/)).

Some functions, such as **SetupDi***Xxx* functions, take the whole SP_DEVINFO_DATA structure as input to identify a device in a device information set. Other functions, such as **CM**_*Xxx* functions like [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status), take this **DevInst** handle as input.

### `Reserved`

Reserved. For internal use only.

## Remarks

An SP_DEVINFO_DATA structure identifies a device in a device information set. For example, when Windows sends a [DIF_INSTALLDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-installdevice) request to a class installer and co-installers, it includes a handle to a device information set and a pointer to an SP_DEVINFO_DATA that specifies the particular device. In addition to DIF requests, this structure is also used in some **SetupDi***Xxx* functions.

**SetupDi***Xxx* functions that take an SP_DEVINFO_DATA structure as a parameter verify that the **cbSize** member of the supplied structure is equal to the size, in bytes, of the structure. If the **cbSize** member is not set correctly for an input parameter, the function will fail and set an error code of ERROR_INVALID_PARAMETER. If the **cbSize** member is not set correctly for an output parameter, the function will fail and set an error code of ERROR_INVALID_USER_BUFFER.

## See also

[SP_DEVINFO_LIST_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_list_detail_data_a)