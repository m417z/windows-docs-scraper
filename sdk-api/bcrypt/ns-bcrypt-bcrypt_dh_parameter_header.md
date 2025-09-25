# BCRYPT_DH_PARAMETER_HEADER structure

## Description

The **BCRYPT_DH_PARAMETER_HEADER** structure is used to contain parameter header information for a Diffie-Hellman key. This structure is used with the [BCRYPT_DH_PARAMETERS](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers) property in the [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) function.

## Members

### `cbLength`

The total size, in bytes, of this structure and the buffer that immediately follows this structure in memory.

### `dwMagic`

The magic value for the key.

This member must be the following value.

#### BCRYPT_DH_PARAMETERS_MAGIC (0x4d504844)

### `cbKeyLength`

The size, in bytes, of the key that this structure applies to.

## Remarks

This structure is used as a header for a larger buffer. The single memory block consists of this structure followed by a buffer of **cbKeyLength** size that contains the Diffie-Hellman prime number, and another buffer of **cbKeyLength** size that contains the Diffie-Hellman generator number. Both of these numbers are in big-endian format.

The following example shows how to calculate the sizes needed for this buffer and how to fill in the members of this structure.

```cpp
// In this example, the rgbModulus variable is a byte array that contains the modulus in big-endian byte order.
// The rgbGenerator variable is a byte array that contains the generator in big-endian byte order.

ULONG cbDHParams = sizeof(BCRYPT_DH_PARAMETER_HEADER) +     (cbKeySize * 2);
PBYTE pbDHParams = (PBYTE)malloc(cbDHParams);
if(!pbDHParams)
{
    status = STATUS_NO_MEMORY;
    goto Cleanup;
}

BCRYPT_DH_PARAMETER_HEADER *pDHParamHeader;
pDHParamHeader = (BCRYPT_DH_PARAMETER_HEADER*)pbDHParams;
pDHParamHeader->cbLength = cbDHParams;
pDHParamHeader->cbKeyLength = cbKeySize;
pDHParamHeader->dwMagic = BCRYPT_DH_PARAMETERS_MAGIC;

// Add the modulus to the parameters.
// The rgbModulus argument is a byte array that contains the modulus.
PBYTE pbTemp = (PBYTE)pbDHParams + sizeof(BCRYPT_DH_PARAMETER_HEADER);
CopyMemory(pbTemp, rgbModulus, pDHParamHeader->cbKeyLength);

// Add the generator to the parameters.
// The rgbGenerator argument is a byte array that contains the generator.
pbTemp += pDHParamHeader->cbKeyLength;
CopyMemory(pbTemp, rgbGenerator, pDHParamHeader->cbKeyLength);

```

## See also

[BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty)

[Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers)