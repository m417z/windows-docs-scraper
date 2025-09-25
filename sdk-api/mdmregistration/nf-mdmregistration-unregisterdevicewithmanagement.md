# UnregisterDeviceWithManagement function

## Description

Unregisters a device with the MDM service

## Parameters

### `RemoveEnterpriseData` [in]

**TRUE** if resources are to be removed during unregistration,
**FALSE** otherwise.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function
fails, the returned value describes the error. Possible
values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)