# EapCredential structure

## Description

The **EapCredential** structure contains information about the credentials type and the appropriate credentials. This is passed as an input to the [EapPeerGetConfigBlobAndUserBlob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetconfigblobanduserblob) API.

## Members

### `credType`

The [EapCredentialType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eapcredentialtype) for the credentials passed in the *credentials* parameter.

### `credData`

Structure that holds the pointer to the credential data.

If **credType** is set to **EAP_EMPTY_CREDENTIAL**, specify a NULL value for credentials.

If **credType** is set to **EAP_USERNAME_PASSWORD_CREDENTIAL**, use an [EapUsernamePasswordCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapusernamepasswordcredential) structure to specify the username and password to use for the credentials.

If **credType** is set to **EAP_WINLOGON_CREDENTIAL**, specify a NULL value for credentials.

If **credType** is set to **EAP_CERTIFICATE_CREDENTIAL**, use an [EapCertificateCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcertificatecredential) structure for credentials to specify the certificate hash and a password (in case the certificate is password protected).

If **credType** is set to **EAP_SIM_CREDENTIAL**, use an [EapSimCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapsimcredential) structure for credentials to specify the ICC-ID of the selected SIM.

## See also

[EapCertificateCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcertificatecredential)

[EapCredentialType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eapcredentialtype)

[EapPeerGetConfigBlobAndUserBlob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetconfigblobanduserblob)

[EapSimCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapsimcredential)

[EapUsernamePasswordCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapusernamepasswordcredential)