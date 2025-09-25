# IX509Attribute::Initialize

## Description

The **Initialize** method initializes the object from an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a value.

## Parameters

### `pObjectId` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that contains the attribute OID.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the attribute value contained in the *strEncodedData* parameter.

### `strEncodedData` [in]

A **BSTR** variable that contains the attribute value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The pointer to the [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface is **NULL**. |

## Remarks

You must initialize the [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object by calling the [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromname) or [InitializeFromValue](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromvalue) methods before using it in this method.

Call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attribute-get_objectid) property to retrieve the OID. Call the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attribute-get_rawdata) property to retrieve the attribute value.

## See also

[ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute)

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)