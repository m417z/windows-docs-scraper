# IADsPathname::Retrieve

## Description

The **IADsPathname::Retrieve** method retrieves the path of the object with different format types.

## Parameters

### `lnFormatType` [in]

Specifies the format that the path should be retrieved in. This can be one of the values specified in the [ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum) enumeration.

### `pbstrADsPath` [out]

Contains a pointer to a **BSTR** value the receives the object path. The caller must free this memory with the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function when it is no longer required.

## Return value

This method supports the standard return values, as well as the following.

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum)

[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)