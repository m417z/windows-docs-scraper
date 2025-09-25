# _WWAN_PCO_TYPE enumeration

## Description

The **WWAN_PCO_TYPE** enumeration indicates whether the header of a PCO structure is partial, meaning only a subset of the complete PCO value from the network is being passed up to the host. This type will help the upper edge logic know the validity of the header of the PCO structure.

## Constants

### `WwanPcoTypeComplete`

Specifies that the complete PCO structure will be passed up as received from the network and the header realistically reflects the protocol in octet 3 of the PCO structure, defined in the 3GPP TS24.008 spec. To see the full PCO structure, see [WWAN_PCO_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pco_value).

### `WwanPcoTypePartial`

Specifies that the modem will only be passing up a subset of PCO structures that it received from the network. The header matches the 3GPP TS24.008 specification for the PCO structure, as shown on **WWAN_PCO_VALUE**, but the “Configuration protocol” of octet 3 may not be valid.

### `WwanPcoTypeMax`

The maximum value for this enumeration.

## Remarks

Currently, in Windows 10, version 1709, some modems can only pass up operator specific PCO elements. These will have the type is set as **WwanPcoTypePartial**, and the header should have the following:

* Octet1: IEI = 27H
* Octet2: PCO value length (total number of octets in the PCO structure -2)
* Octet3: 0x80 for partial header

The OS will not check if the PCO data is valid and leaves the validation to the MO application.

## See also

[MB Protocol Configuration Options (PCO) operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-protocol-configuration-options-pco-operations)

[WWAN_PCO_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pco_value)