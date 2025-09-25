# ConvertIpv4MaskToLength function

## Description

The
**ConvertIpv4MaskToLength** function converts an IPv4 subnet mask to an IPv4 prefix length.

## Parameters

### `Mask` [in]

The IPv4 subnet mask.

### `MaskLength` [out]

A pointer to a **UINT8** value to hold the IPv4 prefix length, in bits, when the function returns successfully.

## Return value

On success,
**ConvertIpv4MaskToLength** returns **NO_ERROR**. Any nonzero return value indicates failure.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters was invalid. This error is returned if the *Mask* parameter was invalid. |

## Remarks

The **ConvertIpv4MaskToLength** function is available on Windows Vista and later.

## See also

[ConvertLengthToIpv4Mask](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertlengthtoipv4mask)