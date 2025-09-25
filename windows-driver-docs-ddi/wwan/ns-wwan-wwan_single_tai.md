## Description

The **WWAN_SINGLE_TAI** structure represents a single Tracking Area Identity (TAI). The TAI contains the Mobile Country Code (MCC), Mobile Network Code (MNC) and Tracking Area Code (TAC)).

## Members

### `Mcc`

Mobile Country Code of 3 decimal digits. The least significant 12 bits contains BCD-encoded 3 decimal digits sequentially for the MCC, with the last digit of the MCC in the least significant 4 bits. The unused bits in the UINT16 integer must be zeros.

### `Mnc`

Mobile Network Code of either 3 or 2 decimal digits. The most significant bit indicates whether the MNC has 2 decimal digits or 3 decimal digits. If this bit has 1, the MNC has 2 decimal digits and the least significant 8 bits contains them in BCD-encoded form sequentially, with the last digit of the MNC in the least significant 4 bits. If the most significant bit has 0, the MNC has 3 decimal digits and the least significant 12 bits contains them in BCD-encoded form sequentially, with the last digit of the MNC in the least significant 4 bits. The unused bits in the UINT16 integer must be zeros.

### `Tac`

Tracking Area Code. If TAC is unknown or invalid, entire TAI is unknown and the MCC component of the field above should be set as mentioned above.

## Remarks

## See also

[MB Packet Service Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-packet-service-attach-operations)

[OID_WWAN_PACKET_SERVICE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-packet-service)

[NDIS_STATUS_WWAN_PACKET_SERVICE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-packet-service)