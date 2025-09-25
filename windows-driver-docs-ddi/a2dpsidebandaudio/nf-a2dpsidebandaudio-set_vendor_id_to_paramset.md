# SET_VENDOR_ID_TO_PARAMSET

## Description

This macro to set the Vendor ID from the VENDOR PARAMS SET derived from SIDEBAND_PARAMS_SET_A2DP_VENDOR_BASE is defined as follows.

```cpp
#define VENDOR_ID_MASK 0x0000FFFF

#define SET_VENDOR_ID_TO_PARAMSET(paramSet, vendorId) ((paramSet).Data1 = ((vendorId) & VENDOR_ID_MASK))
```

## Parameters

### `paramSet`

A parameter set. (Additional Information Pending)

### `vendorId`

The Vendor ID (Additional Information Pending)

## Remarks

## See also

[GET_VENDOR_ID_FROM_PARAMSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/nf-a2dpsidebandaudio-get_vendor_id_from_paramset)

[A2DPSidebandAudio](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/)