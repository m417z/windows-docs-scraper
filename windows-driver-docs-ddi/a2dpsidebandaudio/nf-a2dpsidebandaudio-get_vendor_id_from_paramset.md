# GET_VENDOR_ID_FROM_PARAMSET

## Description

This macro to get the Vendor ID from the VENDOR PARAMS SET derived from SIDEBAND_PARAMS_SET_A2DP_VENDOR_BASE is defined as follows.

```cpp
#define VENDOR_ID_MASK 0x0000FFFF

#define GET_VENDOR_ID_FROM_PARAMSET(paramSet) ((paramSet).Data1 & VENDOR_ID_MASK)
```

**SIDEBAND_PARAMS_SET_A2DP_VENDOR_BASE**

Base GUID for Vendor-defined A2DP Sideband Set of Parameters

The audio driver sets the 32 bit Data1 element to a Vendor ID. The upper 16 bits shall be set to 0. The lower 16 bit shall be set to a valid Company ID as defined in Bluetooth Assigned Numbers.

For additional information, see https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers

```
{xxxxxxxx-FE37-468B-AF72-411C0E5A3FFC}
DEFINE_GUID(SIDEBAND_PARAMS_SET_A2DP_VENDOR_BASE,
    0x00000000, 0xfe37, 0x468b, 0xaf, 0x72, 0x41, 0x1c, 0xe, 0x5a, 0x3f, 0xfc);
```

## Parameters

### `paramSet`

A parameter set. (Additional Information Pending)

## Remarks

## See also

[A2DPSidebandAudio](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/)

[SET_VENDOR_ID_FROM_PARAMSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/nf-a2dpsidebandaudio-set_vendor_id_to_paramset)