# IADsObjectOptions::GetOption

## Description

The **IADsOptions.GetOption** method gets a provider-specific option for a directory object.

## Parameters

### `lnOption`

Indicates the provider-specific option to get. This parameter can be any value in the [ADS_OPTION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_option_enum) enumeration.

### `pvValue`

Pointer to a **VARIANT** variable that receives the current value for the option specified in the *lnOption* parameter.

## Return value

The method supports the standard return values, including **S_OK** if the operation is successful, and **E_ADS_BAD_PARAMETER** if the user has supplied an invalid *pvValue* parameter. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_OPTION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_option_enum)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)