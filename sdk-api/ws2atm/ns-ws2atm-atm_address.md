# ATM_ADDRESS structure

## Description

The
**ATM_ADDRESS** structure holds ATM address data for ATM-based sockets.

## Members

### `AddressType`

Type of end-system ATM address.

### `NumofDigits`

Number of digits in the **Addr** parameter.

### `Addr`

Array representing the ATM address.

## Remarks

For ATM_E164, enter the numbered digits in the same order in which they would be entered on a numeric keypad; that is, the number digit that would be entered first is located in **addr**. Digits are coded in IA5 characters. Bit 8 is set to zero.

For ATM_NSAP, code the address using Binary Coded Decimal (BCD) as defined in the ATM Forum UNI 3.1. The **NumofDigits** field is ignored in this case, and the NSAP-style address always contains 20 bytes.

A value of SAP_FIELD_ANY in **AddressType** indicates that the **satm_number** field is a wildcard. There are two more specialized wildcard values: SAP_FIELD_ANY_AESA_SEL and SAP_FIELD_ANY_AESA_REST. SAP_FIELD_ANY_AESA_SEL means that this is an NSAP-style ATM Endsystem Address and the selector octet is set as a wildcard. SAP_FIELD_ANY_AESA_REST means that this is an NSAP-style ATM Endsystem Address and all the octets except for the selector octet are set as wildcards.

## See also

[sockaddr_atm](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-sockaddr_atm)