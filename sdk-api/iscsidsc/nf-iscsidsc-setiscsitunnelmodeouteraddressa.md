# SetIScsiTunnelModeOuterAddressA function

## Description

**SetIscsiTunnelModeOuterAddress** function establishes the tunnel-mode outer address that the indicated initiator Host Bus Adapter (HBA) uses when communicating in IPsec tunnel mode through the specified port.

## Parameters

### `InitiatorName` [in, optional]

The name of the initiator with which the tunnel-mode outer address will be associated. If this parameter is **null**, all HBA initiators are configured to use the indicated tunnel-mode outer address.

### `InitiatorPortNumber` [in]

Indicates the number of the port with which the tunnel-mode outer address is associated. If this parameter contains **ISCSI_ALL_PORTS**, all ports on the indicated initiator are associated with the tunnel-mode outer address.

### `DestinationAddress` [in]

The destination address to associate with the tunnel-mode outer address indicated by *OuterModeAddress*.

### `OuterModeAddress` [in]

The tunnel-mode outer address to associate with indicated initiators and ports.

### `Persist` [in]

When **true**, this parameter indicates that the iSCSI initiator service stores the tunnel-mode outer address in non-volatile memory and that the address will persist across restarts of the initiator and the iSCSI initiator service.

## Return value

Returns ERROR_SUCCESS if the operation succeeds.Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines SetIScsiTunnelModeOuterAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).