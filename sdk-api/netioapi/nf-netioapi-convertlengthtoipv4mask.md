# ConvertLengthToIpv4Mask function

## Description

The
**ConvertLengthToIpv4Mask** function converts an IPv4 prefix length to an IPv4 subnet mask.

## Parameters

### `MaskLength` [in]

The IPv4 prefix length, in bits.

### `Mask` [out]

A pointer to a **LONG** value to hold the IPv4 subnet mask when the function returns successfully.

## Return value

On success,
**ConvertLengthToIpv4Mask** returns **NO_ERROR**. Any nonzero return value indicates failure and the *Mask* parameter is set to **INADDR_NONE** defined in the *Ws2def.h* header file.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters was invalid. This error is returned if the *MaskLength* parameter was invalid. |

## Remarks

The **ConvertLengthToIpv4Mask** function is available on Windows Vista and later.

## See also

[ConvertIpv4MaskToLength](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertipv4masktolength)