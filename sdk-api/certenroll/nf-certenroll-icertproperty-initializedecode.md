# ICertProperty::InitializeDecode

## Description

The **InitializeDecode** method initializes the object from a byte array that contains the property value. The byte array is represented by a Unicode-encoded string.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string.

### `strEncodedData` [in]

A **BSTR** variable that contains the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded property value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

Specify the property to initialize by calling the [PropertyId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-get_propertyid) property. You can call the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-get_rawdata) property to retrieve the encoded property value. Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property value with a certificate.

If the **InitializeDecode** method fails, the [ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty) object is not initialized and the input property value is not saved. However, the [PropertyId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-get_propertyid) property retains the specified identifier.

The **InitializeDecode** method is provided to enable you to initialize custom properties and properties identified in the [CERTENROLL_PROPERTYID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_propertyid) enumeration for which there exist no specific interface. Each of the supported values in that enumeration contains information about the type of data, usually a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)), that you must supply to the **InitializeDecode** method. You can use the [IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter) interface to convert a byte array to a string.

The following interfaces simplify creation of the most common properties:

* [ICertPropertyArchived](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchived)
* [ICertPropertyArchivedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchivedkeyhash)
* [ICertPropertyAutoEnroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyautoenroll)
* [ICertPropertyBackedUp](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertybackedup)
* [ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription)
* [ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)
* [ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname)
* [ICertPropertyKeyProvInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertykeyprovinfo)
* [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal)
* [ICertPropertyRequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrequestoriginator)
* [ICertPropertySHA1Hash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertysha1hash)

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)