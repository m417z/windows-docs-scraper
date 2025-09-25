# IADsObjectOptions::SetOption

## Description

The **IADsOptions.SetOption** method sets a provider-specific option for manipulating a directory object.

## Parameters

### `lnOption`

Indicates the provider-specific option to set. This parameter can be any value in the [ADS_OPTION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_option_enum) enumeration except **ADS_OPTION_SERVERNAME** or **ADS_OPTION_MUTUAL_AUTH_STATUS**.

### `vValue`

Specifies the value to set for the option specified in the *lnOption* parameter.

## Return value

The method supports the standard return values, including **S_OK** for a successful operation and **E_ADS_BAD_PARAMETER** when the user has supplied an invalid *pValue* parameter. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)