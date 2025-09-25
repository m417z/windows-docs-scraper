# ICertificatePolicy::get_ObjectId

## Description

The **ObjectId** property retrieves an object identifier (OID) for the policy object.

This property is read-only.

## Parameters

## Remarks

The [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object stores information about the OID internally in a CryptoAPI [CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structure. You cannot use this structure directly from the Certificate Enrollment API, but you can use the **IObjectId** interface to retrieve the display name or dotted decimal name of the OID, or the [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid) value.

## See also

[ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies)

[ICertificatePolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicy)