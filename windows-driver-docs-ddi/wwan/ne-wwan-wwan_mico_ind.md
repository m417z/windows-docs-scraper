## Description

The **WWAN_MICO_IND** enumeration indicates the use of Mobile Initiated Connection (MICO) mode or the renegotiation of MICO mode. MICO is a mode of operation for 5G devices.

## Constants

### `WwanRaaiTypeRaNotAllocated`

All public land mobile network (PLMN) registration area not allocated.

### `WwanRaaiTypeRaAllocated`

All PLMN registration area allocated.

### `WwanRaaiTypeNotAvailable`

Registration Area Allocation Indication (RAAI) not received from the network. Either the device did not send a MICO mode request, MICO mode is not supported by the network, or the device is not registered.

## Remarks

The RAAI values indicate the MICO mode negotiated with the network. If the device sends a MICO mode request and it is supported and accepted by the network, the network will include a MICO indication response when accepting the registration procedure.

## See also