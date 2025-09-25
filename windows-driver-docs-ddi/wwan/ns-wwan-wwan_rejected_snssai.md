## Description

The **WWAN_REJECTED_SNSSAI** structure contains information about a single Network Slice Selection Assistance Information (S-NSSAI) that was rejected.

## Members

### `CauseCode`

A 16-bit integer containing a standardized code indicating why the S-NSSAI was rejected.

### `SliceServiceType`

The *SliceServiceType* field may have standardized and non-standardized values. The standardized range contains values from 0 to 127. The operator-specific range contains values from 128 to 255.

| Standardized value | Description |
|--- |--- |
| 1 | Enhanced mobile broadband |
| 2 | Ultra-reliable low latency communications |
| 3 | Massive Internet of Things (IoT) |

### `SliceDifferentiator`

The *SliceDifferentiator* field is optional information that complements the *SliceServiceType* to differentiate among multiple network slices.

If not specified this will be WWAN_SNSSAI_NO_SD_VALUE_ASSOCIATED_WITH_SST (0x00FFFFFF).

## Remarks

## See also

[WWAN_SINGLE_NSSAI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai)