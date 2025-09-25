# IADsPropertyValue2::GetObjectProperty

## Description

The **IADsPropertyValue2::GetObjectProperty** method retrieves an attribute value.

## Parameters

### `lnADsType` [in, out]

Pointer to a variable that, on entry, contains one of the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) values that specifies the data format that the value should be returned.

If the data type is not known, set this to **ADSTYPE_UNKNOWN**. In this case, this method will obtain the attribute value in the default data type and set this variable to the corresponding [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) value. If any other **ADSTYPEENUM** value is specified, ADSI will return the attribute value only if the data type matches the format of the value.

### `pvProp` [out]

Pointer to a **VARIANT** that receives the requested attribute value. The variant type of this data will depend on the value returned in *lnADsType*. For more information and a list of the *lnADsType* values and corresponding *pvProp* variant types, see [IADsPropertyValue2](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue2).

## Return value

Returns **S_OK** if successful or one of the following error codes.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[IADsPropertyValue](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue)

[IADsPropertyValue2](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue2)