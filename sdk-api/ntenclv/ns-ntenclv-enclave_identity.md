# ENCLAVE_IDENTITY structure

## Description

Describes the identity of the primary module of an enclave.

## Members

### `OwnerId`

The identifier of the owner for the enclave.

### `UniqueId`

The unique identifier of the primary module for the enclave.

### `AuthorId`

The author identifier of the primary module for the enclave.

### `FamilyId`

The family identifier of the primary module for the enclave.

### `ImageId`

The image identifier of the primary module for the enclave.

### `EnclaveSvn`

The security version number of the primary module for the enclave.

### `SecureKernelSvn`

The security version number of the Virtual Secure Mode (VSM) kernel.

### `PlatformSvn`

The security version number of the platform that hosts the enclave.

### `Flags`

Flags that describe the runtime policy for the enclave.

| Value | Meaning |
|-------|---------|
| **ENCLAVE_FLAG_FULL_DEBUG_ENABLED**<br>`0x00000001` | The enclave supports debugging. |
| **ENCLAVE_FLAG_DYNAMIC_DEBUG_ENABLED**<br>`0x00000002` | The enclave supports dynamic debugging. |
| **ENCLAVE_FLAG_DYNAMIC_DEBUG_ACTIVE**<br>`0x00000004` | Dynamic debugging is turned on for the enclave. |

### `SigningLevel`

This is a reserved field and must be set to zero.

### `EnclaveType`

This is a reserved field and must be set to zero.

## Remarks

Each enclave has an **ENCLAVE_IDENTITY** that's configured when the enclave is created and set when the enclave is initialized. It contains several properties which are described below:

| Property | How is this property generated? | What is the value in validating this property |
|----------|---------------------------------|-----------------------------------------------|
| *OwnerId* | Set when the enclave is created ([CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)) and denotes the owner (creator) of the enclave. | Can be used to distinguish between enclaves that were created by the same owner. |
| *UniqueId* | Uniquely measures the entire content of the enclave image. When an enclave’s primary image is loaded, the digest contained in the PKCS#1 portion of the Authenticode signature is captured as the Enclave Unique ID. | Can be used to distinguish the exact instance of a particular enclave, including the properties of the code running inside the enclave and the signer information. |
| *AuthorId* | A publisher may want to use a given certificate for signing different VBS enclaves and still have a different trust relationship from a sealing perspective. The author ID uniquely identifies an enclave publisher. The author ID is a hash of:<br><br>- The signer ID<br>- The OPUS information in the signature (if one exists). This is added via the `signtool.exe` signing infrastructure. For scenarios where third-party submissions are signed by Microsoft, this is also used to distinguish different submitters. | Can be used to distinguish the enclave publisher for signing purposes. |
| *FamilyId* | A unique identifier (GUID) assigned to the enclave by its author. Denotes enclaves of the same family. | Can be used to distinguish between enclaves with the same family. Can be used to enforce import, sealing, etc. operations to enclaves with the same *FamilyId*. |
| *ImageId* | A unique identifier (GUID) assigned to the enclave by its author. | Can be used to distinguish between enclaves with the same image. Can be used to enforce import, sealing, etc. operations to enclaves with the same *ImageId*. |
| *EnclaveSvn* | The security version number of the primary image within the enclave. | Compared against *MinimumSvn* on module import to determine if import is rejected. It's also used in signing operations. |
| *PlatformSvn* | The security version number of the VSM kernel. | No enclave is permitted to unseal any data which was sealed by a later SVN enclave. |
| *Flags* | Flags describing the runtime policy of the enclave:<br><br>- **ENCLAVE_FLAG_FULL_DEBUG_ENABLED** - Indicates that the enclave supports debugging.<br>- **ENCLAVE_FLAG_DYNAMIC_DEBUG_ENABLED** - Indicates that the enclave supports dynamic debugging.<br>- **ENCLAVE_FLAG_DYNAMIC_DEBUG_ACTIVE** - Indicates that dynamic debugging was activated for the enclave. | Can be used to confirm if the enclave has debugging enabled or if it has been activated. Multiple permutations can be used to validate the state of the enclave. |

## See also

[VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report)

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)