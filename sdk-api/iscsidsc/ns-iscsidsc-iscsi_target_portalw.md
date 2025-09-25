# ISCSI_TARGET_PORTALW structure

## Description

The **ISCSI_TARGET_PORTAL** structure contains information about a portal.

## Members

### `SymbolicName`

A string representing the name of the portal.

### `Address`

A string representing the IP address or DNS name of the portal.

### `Socket`

The socket number of the portal.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_TARGET_PORTAL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).