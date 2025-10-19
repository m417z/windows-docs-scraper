# IObjectId::InitializeFromValue

## Description

The **InitializeFromValue** method initializes the object from a string that contains a dotted decimal [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This method is web enabled.

## Parameters

### `strValue` [in]

A **BSTR** variable that contains the dotted decimal representation of the ASN.1 object identifier. For example, the value 1.2.840.10045.4.1. represents the iso(1)member-body(2)us(840)10045 signatures(4)sha1(1) object identifier.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The OID information could not be found. |
| **CRYPT_E_UNKNOWN_ALGO** | The algorithm name is not recognized. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

You can call the following properties to retrieve information about an initialized [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object:

* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_friendlyname)
* [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_name)
* [Value](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_value)

## See also

[IObjectID](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)