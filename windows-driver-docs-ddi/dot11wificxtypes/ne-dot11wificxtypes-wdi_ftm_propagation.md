## Description

The **WDI_FTM_PROPAGATION** enumeration defines the propagation properties of a signal that are estimated by the LE's logic.

## Constants

### `WDI_FTM_PROPAGATION_UNKNOWN:0`

The default value. Nothing is assumed about how the signal was propagated, so the value should not have an effect on how the measurement is treated. This is the same as if the propagation field is not provided.

### `WDI_FTM_PROPAGATION_INDIRECT_PATH:1`

The LE estimated a low confidence measurement due to the detection of the transmission occurring through a Non-Line of Sight without a direct path or the transmission was too low to be properly received. It is assumed the measurement occurred mostly using a reflected signal, so it should not be as trusted as much as other measurements. This could be used as a guidance for upper layers to deprioritize or not use this measurement, so it is important for the detection logic to avoid false positives. False negatives are less problematic but are not desirable.

### `WDI_FTM_PROPAGATION_LINE_OF_SIGHT:2`

The LE estimated a high accurate measurement due to the detection of the transmission occurring in a Line of Sight with a strong direct path. It is assumed that the measurement occurred without intervening obstacles, so it should be a preferred measurement. This could be used as a guidance for upper layers to prioritize this measurement, so it is important for the detection logic to avoid false positives. False negatives are less problematic but are not desirable.

## Remarks

The **WDI_FTM_PROPAGATION** enum is a value in the [**WDI_TLV_FTM_RESPONSE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ftm-response) TLV.

## See also

[**WDI_TLV_FTM_RESPONSE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ftm-response)