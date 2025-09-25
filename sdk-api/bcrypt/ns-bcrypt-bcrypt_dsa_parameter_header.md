# BCRYPT_DSA_PARAMETER_HEADER structure

## Description

The **BCRYPT_DSA_PARAMETER_HEADER** structure is used as a header for a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) parameters [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) containing information for generating a DSA key. This structure is used with the [BCRYPT_DSA_PARAMETERS](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers) property in the [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) function.

## Members

### `cbLength`

The total size, in bytes, of this structure and the buffer that immediately follows this structure in memory.

### `dwMagic`

The magic value for the key.

This member must be the following value.

#### BCRYPT_DSA_PARAMETERS_MAGIC (0x4d505344)

### `cbKeyLength`

The size, in bytes, of the key that this structure applies to.

### `Count`

The number of iterations performed to generate the prime number *q* from the seed.

### `Seed`

The seed value, in big-endian format, used to generate *q*.

### `q`

The 160-bit prime factor, in big-endian format.

## Remarks

When using this structure in a [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) call, to set the parameters for a DSA key created in a [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair) call, (cbKeyLength*8) must equal the previously set dwLength.

The structure applies to DSA keys that equal or exceed 512 bits in length but are less than or equal to 1024 bits.

This structure is used as a header for a larger buffer. The DSA parameters blob has the following format in contiguous memory. The Modulus and Generator are in big-endian format.

``` syntax

BCRYPT_DSA_PARAMETER_HEADER
Modulus[cbKeyLength]    // Big-endian.
Generator[cbKeyLength]  // Big-endian.

```

## See also

[BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair)

[BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty)

[Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers)