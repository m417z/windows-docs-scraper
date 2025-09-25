# ICertPropertyBackedUp::Initialize

## Description

The **Initialize** method initializes the object from a Boolean value and a date.

## Parameters

### `BackedUpValue` [in]

A **VARIANT_BOOL** variable that identifies whether the certificate has been backed up.

### `Date` [in]

A **DATE** variable that identifies when a certificate was last backed up.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |
| ****HRESULT_FROM_WIN32(ERROR_INVALID_DATA)**** | The specified time is not valid. |

## Remarks

The date is stored as an 8-byte real value, representing a date between January 1, 1900 and December 31, 9999, inclusive. The value 2.0 represents January 1, 1900; 3.0 represents January 2, 1900. Adding 1 to the value increments the date by a day. The fractional part of the value represents the time of day. Therefore, 2.5 represents 12:00 on January 1, 1900; 3.25 represents 06:00 on January 2, 1900.

For dates between 1950 and 2049 inclusive, the date and time is encoded UTC-time in the form YYMMDDHHMMSS. For dates before 1950 or after 2049, encoded generalized time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four digit year, and is precise to milliseconds.

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. To retrieve the date, call the [BackedUpTime](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertybackedup-get_backeduptime) property. To retrieve the Boolean value that identifies whether a certificate was backed up, call the [BackedUpValue](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertybackedup-get_backedupvalue) property.

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyBackedUp](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertybackedup)