# DsValidateSubnetNameW function

## Description

The **DsValidateSubnetName** function validates a subnet name in the form xxx.xxx.xxx.xxx/YY. The Xxx.xxx.xxx.xxx portion must be a valid IP address. Yy must be the number of leftmost significant bits included in the mask. All bits of the IP address that are not covered by the mask must be specified as zero.

## Parameters

### `SubnetName` [in]

Pointer to a null-terminated string that specifies the name of the subnet to validate.

## Return value

If the function returns account information, the return value is **NO_ERROR**.

If the function fails, the return value is the following error code.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[DsGetSiteName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetsitenamea)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DsValidateSubnetName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).