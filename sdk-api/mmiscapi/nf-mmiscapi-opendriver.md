# OpenDriver function

## Description

Opens an instance of an installable driver and initializes the instance using either the driver's default settings or a driver-specific value.

## Parameters

### `szDriverName` [in]

Address of a null-terminated, wide-character string that specifies the filename of an installable driver or the name of a registry value associated with the installable driver. (This value must have been previously set when the driver was installed.)

### `szSectionName` [in]

Address of a null-terminated, wide-character string that specifies the name of the registry key containing the registry value given by the *lpDriverName* parameter. If *lpSectionName* is **NULL**, the registry key is assumed to be **Drivers32**.

### `lParam2` [in]

32-bit driver-specific value. This value is passed as the *lParam2* parameter to the [DriverProc](https://learn.microsoft.com/previous-versions/dd797918(v=vs.85)) function of the installable driver.

## Return value

Returns the handle of the installable driver instance if successful or **NULL** otherwise.

## See also

[Installable Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/installable-driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)