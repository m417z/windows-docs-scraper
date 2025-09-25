# EapCredentialType enumeration

## Description

The **EapCredentialType** enumeration defines the set of possible EAP credentials that can be passed to the [EapPeerGetConfigBlobAndUserBlob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetconfigblobanduserblob) function.

## Constants

### `EAP_EMPTY_CREDENTIAL:0`

The EAP method has no credential passed to it. The method must attempt a machine authentication.

### `EAP_USERNAME_PASSWORD_CREDENTIAL`

The EAP method uses a username and password for authentication. The credentials are passed using the [EapUsernamePasswordCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapusernamepasswordcredential) structure.

### `EAP_WINLOGON_CREDENTIAL`

The EAP method uses the logged-on user credentials for authentication.

### `EAP_CERTIFICATE_CREDENTIAL`

The EAP method uses a certificate present on the system for authentication. The credential is passed as an [EapCertificateCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcertificatecredential) structure.

### `EAP_SIM_CREDENTIAL`

The EAP method uses a SIM for authentication. This is passed as an [EapSimCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapsimcredential) structure.

## See also

[EapCertificateCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcertificatecredential)

[EapPeerGetConfigBlobAndUserBlob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetconfigblobanduserblob)

[EapSimCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapsimcredential)

[EapUsernamePasswordCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapusernamepasswordcredential)