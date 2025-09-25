# IsManagementRegistrationAllowed function

## Description

Checks whether MDM registration is allowed by local policy.

## Parameters

### `pfIsManagementRegistrationAllowed` [out]

Address of a **BOOL** that receives a value indication whether registration is allowed.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** and the **BOOL** pointed to by the *pfIsManagementRegistrationAllowed* parameter contains **TRUE** or **FALSE**. If the function fails, the returned value describes the error. Possible
values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)

[SetManagedExternally](https://learn.microsoft.com/windows/desktop/api/mdmregistration/nf-mdmregistration-setmanagedexternally)