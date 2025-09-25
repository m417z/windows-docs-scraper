## Description

The **WWAN_SNSSAI_LIST** structure represents a list of single Network Slice Selection Assistance Information (S-NSSAIs) that are allowed in the current PLMN or registration area.

## Members

### `ElementCount`

The number of elements in the S-NSSAI list.

### `Snssais`

An array of [**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai) structures that represent the allowed S-NSSAIs.

## Remarks

## See also

[**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai)