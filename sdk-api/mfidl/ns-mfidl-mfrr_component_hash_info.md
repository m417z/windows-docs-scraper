# MFRR_COMPONENT_HASH_INFO structure

## Description

Contains information about a revoked component.

## Members

### `ulReason`

Specifies the reason for the revocation. The following values are defined.

| Value | Meaning |
| --- | --- |
| **MF_BOOT_DRIVER_VERIFICATION_FAILED** | A boot driver could not be verified. |
| **MF_COMPONENT_CERT_REVOKED** | A certificate in a trusted component's certificate chain was revoked. |
| **MF_COMPONENT_HS_CERT_REVOKED** | The high-security certificate for authenticating the protected environment (PE) was revoked.<br><br>The high-security certificate is typically used by ITAs that handle high-definition content and next-generation formats such as HD-DVD. |
| **MF_COMPONENT_INVALID_EKU** | A certificate's extended key usage (EKU) object is invalid. |
| **MF_COMPONENT_INVALID_ROOT** | The root certificate is not valid. |
| **MF_COMPONENT_LS_CERT_REVOKED** | The low-security certificate for authenticating the PE was revoked.<br><br>The low-security certificate is typically used by ITAs that handle standard-definition content and current-generation formats. |
| **MF_COMPONENT_REVOKED** | A trusted component was revoked. |
| **MF_GRL_ABSENT** | The GRL was not found. |
| **MF_GRL_LOAD_FAILED** | Could not load the global revocation list (GRL). |
| **MF_INVALID_GRL_SIGNATURE** | The GRL signature is invalid. |
| **MF_MINCRYPT_FAILURE** | A certificate chain was not well-formed, or a boot driver is unsigned or is signed with an untrusted certificate. |
| **MF_TEST_SIGNED_COMPONENT_LOADING** | A component was signed by a test certificate. |

In addition, one of the following flags might be present, indicating the type of component that failed to load.

| Value | Meaning |
| --- | --- |
| **MF_USER_MODE_COMPONENT_LOAD** | User-mode component. |
| **MF_KERNEL_MODE_COMPONENT_LOAD** | Kernel-mode component. |

### `rgHeaderHash`

Contains a hash of the file header.

### `rgPublicKeyHash`

Contains a hash of the public key in the component's certificate.

### `wszName`

File name of the revoked component.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)