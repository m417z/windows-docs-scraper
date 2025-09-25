# BCRYPT_DSA_PARAMETER_HEADER_V2 structure

## Description

The **BCRYPT_DSA_PARAMETER_HEADER_V2** structure is used as a header for a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) parameters [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) containing information for generating a DSA key. This structure is used with the [BCRYPT_DSA_PARAMETERS](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers) property in the [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) function.

## Members

### `cbLength`

The total size, in bytes, of this structure and the buffer that immediately follows this structure in memory.

### `dwMagic`

The magic value for the key.

This member must be the following value.

#### BCRYPT_DSA_PARAMETERS_MAGIC_V2 (0x324d5044)

### `cbKeyLength`

The size, in bytes, of the key that this structure applies to.

### `hashAlgorithm`

A [HASHALGORITHM_ENUM](https://learn.microsoft.com/windows/desktop/api/bcrypt/ne-bcrypt-hashalgorithm_enum) enumeration value that specifies the hashing algorithm to use.

### `standardVersion`

A [DSAFIPSVERSION_ENUM](https://learn.microsoft.com/windows/desktop/api/bcrypt/ne-bcrypt-dsafipsversion_enum) enumeration value that specifies the Federal Information Processing Standard (FIPS) to apply.

### `cbSeedLength`

Length of the seed used to generate the prime number *q* in bytes.

### `cbGroupSize`

Size of the prime number *q*. Currently, when the key exceeds 1024 bits in length, *q* is 32 bytes long.

### `Count`

The number of iterations performed to generate the prime number q from the seed. For more information, see NIST standard FIPS186-3.

## Remarks

When using this structure in a [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) call, to set the parameters for a DSA key created in a [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair) call, (cbKeyLength*8) must equal the previously set dwLength.

The structure applies to DSA keys that exceed 1024 bits in length but are less than or equal to 3072 bits.

This structure is used as a header for a larger buffer. The DSA parameters blob has the following format in contiguous memory. The Seed, q, Modulus, and Generator are in big-endian format.

``` syntax

BCRYPT_DSA_PARAMETER_HEADER_V2
Seed[cbSeedLength]      // Big-endian.
q[cbGroupSize]          // Big-endian.
Modulus[cbKeyLength]    // Big-endian.
Generator[cbKeyLength]  // Big-endian.

```

## See also

[BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair)

[BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty)

[Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers)