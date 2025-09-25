# IADsPropertyValue2::PutObjectProperty

## Description

The **IADsPropertyValue2::PutObjectProperty** method sets an attribute value.

## Parameters

### `lnADsType` [in]

Contains one of the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) values that specifies the data format of the value set. This value must correspond to the *pvProp* variant type. For more information and a list of the *lnADsType* values and corresponding *pvProp* variant types, see [IADsPropertyValue2](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue2).

### `vProp` [in]

Pointer to a **VARIANT** that contains the new attribute value. The variant type of this data must correspond to the value in *lnADsType*. For more information and a list of the *lnADsType* values and corresponding *pvProp* variant types, see [IADsPropertyValue2](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue2).

## Return value

Returns **S_OK** if successful or an error code otherwise. The following are the most common error codes.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[IADsPropertyValue](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue)

[IADsPropertyValue2](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue2)