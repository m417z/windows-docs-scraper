# SetupDiLoadDeviceIcon function

## Description

The **SetupDiLoadDeviceIcon** function retrieves an icon for a specified device.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element that represents the device for which to retrieve an icon.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `cxIcon` [in]

The width, in pixels, of the icon to be retrieved. Use the system metric index SM_CXICON to specify a default-sized icon or use the system metric index SM_CXSMICON to specify a small icon. The system metric indexes are defined in *Winuser.h*, and their associated values can be retrieved by a call to the [GetSystemMetrics](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getsystemmetrics) function. (The **GetSystemMetrics** function is documented in the Microsoft Windows SDK.)

### `cyIcon` [in]

The height, in pixels, of the icon to be retrieved. Use SM_CXICON to specify a default-sized icon or use SM_CXSMICON to specify a small icon.

### `Flags` [in]

Not used. Must set to zero.

### `hIcon` [out]

A pointer to a handle to an icon that receives a handle to the icon that this function retrieves. After the application that calls this function is finished using the icon, the application must call [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) to delete the icon. (**DestroyIcon** is documented in the Microsoft Windows SDK.)

## Return value

**SetupDiLoadDeviceIcon** returns **TRUE** if the function succeeds in retrieving the icon for the specified device. Otherwise, the function returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiLoadDeviceIcon** attempts to retrieve an icon for the device as follows:

* If the [DEVPKEY_DrvPkg_Icon](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-drvpkg-icon) device property of the device includes a list of resource-identifier strings, the function attempts to retrieve the icon that is specified by the first resource-identifier string in the list.

  The [device property data type](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers) of the DEVPKEY_DrvPkg_Icon device property is [DEVPROP_TYPE_STRING_LIST](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-list).

  The format of a resource-identifier string is

  ```
  [filepath\]filename,-resourceID
  ```

  Where:

  + *filepath,* followed by the backslash character (\\)*,* is optional and specifies a path of the file that contains the icon.
  + *FileName*, followed by the comma character (",") specifies the name of the file that contains the icon.
  + *ResourceID*, preceded by a dash character ("-"), specifies the resource ID of the icon.
* If the function cannot retrieve a device-specific icon, it will then attempt to retrieve the class icon for the device. For information about class icons, see [SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon).
* If the function cannot retrieve the class icon for the device, it will then attempt to retrieve the icon for the Unknown [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes), where the icon for the Unknown device setup class includes the image of a question mark (?).

## See also

[DEVPROP_TYPE_STRING_LIST](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-list)

[SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon)