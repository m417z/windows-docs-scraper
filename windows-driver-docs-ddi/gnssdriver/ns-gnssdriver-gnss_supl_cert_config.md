# GNSS_SUPL_CERT_CONFIG structure

## Description

This structure contains SUPL certificate information.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `CertAction`

A [GNSS_SUPL_CERT_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_supl_cert_action) enumeration value that specifies the action to take on the certificate.

| Action | Description |
|--|--|
| GNSS_SUPL_CERT_INJECT | Inject the certificate. |
| GNSS_SUPL_CERT_DELETE | Delete the certificate specified by **SuplCertName**. The values of **CertSize** and **CertData** are ignored. |
| GNSS_SUPL_CERT_PURGE | Delete all the certificates injected to the GNSS driver previously. The values of **SuplCertName** , **CertSize**, and **CertData** are ignored. |

### `SuplCertName`

String containing the certificate name.

### `CertSize`

The size of the certificate in bytes.

### `Unused`

Padding buffer.

### `CertData`

The binary content of the certificate. The total size of the bytes is defined by **CertSize**. The certificate is Base64 encoded.