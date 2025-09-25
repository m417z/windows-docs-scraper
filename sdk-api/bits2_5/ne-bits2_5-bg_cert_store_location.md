# BG_CERT_STORE_LOCATION enumeration

## Description

Defines constants that specify the location of the certificate store.

## Constants

### `BG_CERT_STORE_LOCATION_CURRENT_USER:0`

Use the current user's certificate store.

### `BG_CERT_STORE_LOCATION_LOCAL_MACHINE`

Use the local computer's certificate store.

### `BG_CERT_STORE_LOCATION_CURRENT_SERVICE`

Use the current service's certificate store.

### `BG_CERT_STORE_LOCATION_SERVICES`

Use a specific service's certificate store.

### `BG_CERT_STORE_LOCATION_USERS`

Use a specific user's certificate store.

### `BG_CERT_STORE_LOCATION_CURRENT_USER_GROUP_POLICY`

Use the current user's group policy certificate store. In a network setting, stores in this location are downloaded to the client computer from the Group Policy Template (GPT) during computer startup, or user logon.

### `BG_CERT_STORE_LOCATION_LOCAL_MACHINE_GROUP_POLICY`

Use the local computer's certificate store. In a network setting, stores in this location are downloaded to the client computer from the Group Policy Template (GPT) during computer startup, or user logon.

### `BG_CERT_STORE_LOCATION_LOCAL_MACHINE_ENTERPRISE`

Use the enterprise certificate store. The enterprise store is shared across domains in the enterprise, and downloaded from the global enterprise directory.

## Remarks

For more information, see [System store locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations).

## See also

* [IBackgroundCopyJobHttpOptions::GetClientCertificate method](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getclientcertificate)
* [IBackgroundCopyJobHttpOptions::SetClientCertificateByID method](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid)
* [IBackgroundCopyJobHttpOptions::SetClientCertificateByName method](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname)