# IObjectId::InitializeFromName

## Description

The **InitializeFromName** method initializes the object from a [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid) enumeration value. This method is web enabled.

## Parameters

### `Name` [in]

A [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid) enumeration value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The OID information could not be found. |
| **CRYPT_E_UNKNOWN_ALGO** | The algorithm name is not recognized. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

Every [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid) value is associated with an ASN.1 object identifier. For example, the value **XCN_OID_ECDSA_SHA1** is associated with a string that contains 1.2.840.10045.4.1. This is the dotted decimal representation of the iso(1)member-body(2)us(840)10045 signatures(4)sha1(1) object identifier.

The **InitializeFromName** method searches the registry for information associated with the ASN.1 object identifier. If information is found, the method internally populates a [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure and associates it with the object. The method also uses the local information to initialize, if possible, the display name of the object.

You can call the following properties to retrieve information about an initialized [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object:

* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_friendlyname)
* [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_name)
* [Value](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_value)

## See also

[FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_friendlyname)

[IObjectID](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)