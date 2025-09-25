# SetManagedExternally function

## Description

Indicates to the MDM agent that the device is managed externally and is not to be registered with an
MDM service.

## Parameters

### `IsManagedExternally` [in]

If **TRUE** this device is not to be registered with an MDM service. If
**FALSE** this device can be registered with an MDM service.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function fails, the returned value describes the error. Possible
values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

## See also

[IsManagementRegistrationAllowed](https://learn.microsoft.com/windows/desktop/api/mdmregistration/nf-mdmregistration-ismanagementregistrationallowed)

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)