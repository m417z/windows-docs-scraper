## Description

The **WWAN_PLMN** structure represents a Mobile Country Code (MCC) and Mobile Network Code (MNC).

## Members

### `Mcc`

Mobile Country Code of 3 decimal digits. The least significant 12 bits contains BCD-encoded 3 decimal digits sequentially for the MCC, with the last digit of the MCC in the least significant 4 bits. The unused bits in the UINT16 integer must be zeros.

### `Mnc`

Mobile Network Code of either 3 or 2 decimal digits. The most significant bit indicates whether the MNC has 2 decimal digits or 3 decimal digits. If this bit has 1, the MNC has 2 decimal digits and the least significant 8 bits contains them in BCD-encoded form sequentially, with the last digit of the MNC in the least significant 4 bits. If the most significant bit has 0, the MNC has 3 decimal digits and the least significant 12 bits contains them in BCD-encoded form sequentially, with the last digit of the MNC in the least significant 4 bits. The unused bits in the UINT16 integer must be zeros.

## Remarks

## See also

[**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn)