# SetupDiDeleteDeviceInfo function

## Description

The **SetupDiDeleteDeviceInfo** function deletes a device information element from a device information set. This function does not delete the actual device.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device information element to delete.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device information element in *DeviceInfoSet*  to delete.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified device information element is in use (for example, by a wizard page), the function fails. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_DEVINFO_DATA_LOCKED. This happens if a handle to a wizard page is retrieved with a call to [SetupDiGetWizardPage](https://learn.microsoft.com/windows-hardware/drivers/install/setupdigetwizardpage) with this device information element specified and the DIWP_FLAG_USE_DEVINFO_DATA flag set. To delete this device information element, you must first close the wizard's HPROPSHEETPAGE handle.

## See also

[SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[SetupDiGetWizardPage](https://learn.microsoft.com/windows-hardware/drivers/install/setupdigetwizardpage)

[SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa)