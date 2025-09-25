# ISCSI_TARGET_PORTAL_INFOA structure

## Description

The **ISCSI_TARGET_PORTAL_INFO** structure contains information about a target portal.

## Members

### `InitiatorName`

A string representing the name of the Host-Bus Adapter initiator.

### `InitiatorPortNumber`

The port number on the Host-Bus Adapter (HBA) associated with the portal. This port number corresponds to the source IP address on the HBA

### `SymbolicName`

A string representing the symbolic name of the portal.

### `Address`

A string representing the IP address or DNS name of the portal.

### `Socket`

The socket number.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_TARGET_PORTAL_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).