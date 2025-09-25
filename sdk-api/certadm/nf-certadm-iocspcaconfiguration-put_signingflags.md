# IOCSPCAConfiguration::put_SigningFlags

## Description

The **SigningFlags** property gets or sets a combination of flag values. These values specify the management of signing certificates that belong to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration.

This property is read/write.

## Parameters

## Remarks

The following table lists bit flag values for
**SigningFlags**.

| Flag constant | Flag value | Description |
| --- | --- | --- |
| **OCSP_SF_SILENT** | 0x001 | Acquire a private key silently. |
| **OCSP_SF_USE_CACERT** | 0x002 | Use a CA certificate in this configuration for signing an OCSP response. This option is available only if the responder service is installed on the CA computer. |
| **OCSP_SF_ALLOW_SIGNINGCERT_AUTORENEWAL** | 0x004 | Enable a responder service to automatically transition to a renewed signing certificate. |
| **OCSP_SF_FORCE_SIGNINGCERT_ISSUER_ISCA** | 0x008 | Force a delegated signing certificate to be signed by the CA. |
| **OCSP_SF_AUTODISCOVER_SIGNINGCERT** | 0x010 | Automatically discover a delegated signing certificate. |
| **OCSP_SF_MANUAL_ASSIGN_SIGNINGCERT** | 0x020 | Manually assign a signing certificate. |
| **OCSP_SF_RESPONDER_ID_KEYHASH** | 0x040 | A responder ID includes a hash of the public key of the signing certificate (default). |
| **OCSP_SF_RESPONDER_ID_NAME** | 0x080 | A responder ID includes the name of the subject in a signing certificate. |
| **OCSP_SF_ALLOW_NONCE_EXTENSION** | 0x100 | Enable NONCE extension to be processed by a responder service. |
| **OCSP_SF_ALLOW_SIGNINGCERT_AUTOENROLLMENT** | 0x200 | A responder service can enroll for a signing certificate. |

When setting **SigningFlags**, you must specify one of the values **OCSP_SF_USE_CACERT**, **OCSP_SF_AUTODISCOVER_SIGNINGCERT**, or **OCSP_SF_MANUAL_ASSIGN_SIGNINGCERT**.

If you specify **OCSP_SF_ALLOW_SIGNINGCERT_AUTOENROLLMENT**, you must also specify **OCSP_SF_AUTODISCOVER_SIGNINGCERT**.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)