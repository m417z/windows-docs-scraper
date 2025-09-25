# IDTFilter3::LicenseHasExpirationDate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **LicenseHasExpirationDate** method queries whether the license for the content has an expiration date.

## Parameters

### `pfLicenseHasExpirationDate` [out]

Receives a Boolean value. If **TRUE**, the license has an expiration date. If **FALSE**, the license does not expire.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## See also

[IDTFilter3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter3)