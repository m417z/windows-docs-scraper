# IMAGE_ENCLAVE_CONFIG64 structure

## Description

Defines the format of the enclave configuration for systems running 64-bit Windows.

## Members

### `Size`

The size of the **IMAGE_ENCLAVE_CONFIG64** structure, in bytes.

### `MinimumRequiredConfigSize`

The minimum size of the **IMAGE_ENCLAVE_CONFIG64** structure that the image loader must be able to process in order for the enclave to be usable. This member allows an enclave to inform an earlier version of the image loader that the image loader can safely load the enclave and ignore optional members added to **IMAGE_ENCLAVE_CONFIG64** for later versions of the enclave. If the size of **IMAGE_ENCLAVE_CONFIG64** that the image loader can process is less than **MinimumRequiredConfigSize**, the enclave cannot be run securely.

If **MinimumRequiredConfigSize** is zero, the minimum size of the **IMAGE_ENCLAVE_CONFIG64** structure that the image loader must be able to process in order for the enclave to be usable is assumed to be the size of the structure through and including the **MinimumRequiredConfigSize** member.

### `PolicyFlags`

Flags that indicate the policies that have been set for the enclave. These flags can be set to indicate whether the enclave permits debugging and whether the enclave is restricted to using its own memory space.

| Value | Meaning |
|-------|---------|
| `0x00000000` | The enclave does not permit debugging. |
| **IMAGE_ENCLAVE_POLICY_DEBUGGABLE**<br>`0x00000001` | The enclave permits debugging. |
| **IMAGE_ENCLAVE_POLICY_STRICT_MEMORY**<br>`0x00000002` | This flag restricts access by an enclave to the address space of its containing process. This policy applies to all threads in the enclave. The enclave must use the [EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave) and [EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave) APIs to access containing process memory.<br><br>**Note:** Access to the containing process's address space can also be restricted by calling the [EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess) API. This API can also be used to relax this policy at runtime and restore access to the containing process memory. |

### `NumberOfImports`

The number of images in the array of images that the **ImportList** member points to.

### `ImportList`

The relative virtual address of the array of images that the enclave image may import, with identity information for each image.

### `ImportEntrySize`

The size of each image in the array of images that the **ImportList** member points to.

### `FamilyID`

The family identifier that the author of the enclave assigned to the enclave.

### `ImageID`

The image identifier that the author of the enclave assigned to the enclave.

### `ImageVersion`

The version number that the author of the enclave assigned to the enclave.

### `SecurityVersion`

The security version number that the author of the enclave assigned to the enclave.

### `EnclaveSize`

The expected virtual size of the private address range for the enclave, in bytes.

### `NumberOfThreads`

The maximum number of threads that can be created within the enclave.

### `EnclaveFlags`

A flag that indicates whether the image is suitable for use as the primary image in the enclave.

| Value | Meaning |
|-------|---------|
| `0x00000000` | The image is not suitable for use as the primary image in the enclave. |
| **IMAGE_ENCLAVE_FLAG_PRIMARY_IMAGE**<br>`0x00000001` | The image is suitable for use as the primary image in the enclave. |

## Remarks

The **IMAGE_ENCLAVE_CONFIG** structure is defined as another name for the **IMAGE_ENCLAVE_CONFIG64** structure on systems that run 64-bit Windows.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[IMAGE_ENCLAVE_CONFIG32](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_enclave_config32)

[EnclaveCopyIntoEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyintoenclave)

[EnclaveCopyOutOfEnclave](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclavecopyoutofenclave)

[EnclaveRestrictContainingProcessAccess](https://learn.microsoft.com/windows/win32/api/winenclaveapi/nf-winenclaveapi-enclaverestrictcontainingprocessaccess)