# IMAGE_ENCLAVE_IMPORT structure

## Description

Defines a entry in the array of images that an enclave can import.

## Members

### `MatchType`

The type of identifier of the image that must match the value in the import record.

| Value | Meaning |
|-------|---------|
| **IMAGE_ENCLAVE_IMPORT_MATCH_NONE**<br>`0x00000000` | None of the identifiers of the image need to match the value in the import record. |
| **IMAGE_ENCLAVE_IMPORT_MATCH_UNIQUE_ID**<br>`0x00000001` | The value of the enclave unique identifier of the image must match the value in the import record. Otherwise, loading of the image fails. |
| **IMAGE_ENCLAVE_IMPORT_MATCH_AUTHOR_ID**<br>`0x00000002` | The value of the enclave author identifier of the image must match the value in the import record. Otherwise, loading of the image fails. If this flag is set and the import record indicates an author identifier of all zeros, the imported image must be part of the Windows installation. |
| **IMAGE_ENCLAVE_IMPORT_MATCH_FAMILY_ID**<br>`0x00000003` | The value of the enclave family identifier of the image must match the value in the import record. Otherwise, loading of the image fails. |
| **IMAGE_ENCLAVE_IMPORT_MATCH_IMAGE_ID**<br>`0x00000004` | The value of the enclave image identifier of the image must match the value in the import record. Otherwise, loading of the image fails. |

### `MinimumSecurityVersion`

The minimum enclave security version that each image must have for the image to be imported successfully. The image is rejected unless its enclave security version is equal to or greater than the minimum value in the import record. Set the value in the import record to zero to turn off the security version check.

### `UniqueOrAuthorID`

The unique identifier of the primary module for the enclave, if the **MatchType** member is **IMAGE_ENCLAVE_IMPORT_MATCH_UNIQUE_ID**. Otherwise, the author identifier of the primary module for the enclave..

### `FamilyID`

The family identifier of the primary module for the enclave.

### `ImageID`

The image identifier of the primary module for the enclave.

### `ImportName`

The relative virtual address of a NULL-terminated string that contains the same value found in the import directory for the image.

### `Reserved`

Reserved.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)