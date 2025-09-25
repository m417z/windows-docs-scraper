# _WWAN_PCO_VALUE structure

## Description

The **WWAN_PCO_VALUE** structure represents the PCO information payload from the network as defined in the 3GPP TS24.008 spec.

## Members

### `Size`

The length of the PCO value that is valid in **PcoData**, which will be octets 3 (octet 1 to 3) + (m * protocol element length) + (n * container element length). This is defined in the 3GPP TS24.008 spec, Section 10.5 because PCO is Type 4 information.

### `Type`

Indicates whether the PCO value being passed up is the original structure that was received by the modem or a subset of the full PCO structure and has the header synthesized. For more info, see [WWAN_PCO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pco_type).

### `PcoData`

The payload of the PCO structure that is received from the operator. The modem should surface the PCO with the complete structure as specified by the 3G TS24.008 spec. *WWAN_PCO_OCT_BUF_LEN* is defined as *256*, given that the longest a PCO structure could be is 253 octets.

## Remarks

Because some modems can currently only pass up operator specific PCO elements, the modem should pass up the information following the structure defined by 3GPP TS24.008 with the accurate synthesized header values for the content that is being passed up to the host.

For example, if the modem received a PCO with 3 protocols and 3 containers, and is only passing up the 2 operator specific element containers to the host, the modem will make changes to the header that indicates the length of the PCO structure. This is to reflect the fact that there are only the two containers by subtracting the length of the 3 protocols.

The following figure shows a full PCO structure as defined in the 3G TS24.008 spec.

![Full PCO structure.](https://learn.microsoft.com/windows-hardware/drivers/ddi/images/pco_structure_small.png)

## See also

[MB Protocol Configuration Options (PCO) operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-protocol-configuration-options-pco-operations)

[NDIS_WWAN_PCO_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_pco_status)

[WWAN_PCO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pco_type)