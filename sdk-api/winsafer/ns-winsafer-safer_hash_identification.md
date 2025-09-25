# SAFER_HASH_IDENTIFICATION structure

## Description

The **SAFER_HASH_IDENTIFICATION** structure represents a hash identification rule.

## Members

### `header`

A [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure containing the structure header. The **dwIdentificationType** member of the header must be **SaferIdentityTypeImageHash**, and the **cbStructSize** member of the header must be sizeof(SAFER_HASH_IDENTIFICATION).

### `Description`

A description of the hash identification rule provided by the user.

### `FriendlyName`

A human-readable name for the hash identification rule.

### `HashSize`

The size of the **ImageHash** member in bytes. For example, if the algorithm specified by the **HashAlgorithm** member is MD5, the size is 16.

### `ImageHash`

The computed hash of the code image.

### `HashAlgorithm`

The algorithm used to compute the hash.

### `ImageSize`

The size of the original file in bytes.

### `dwSaferFlags`

Reserved for future use.