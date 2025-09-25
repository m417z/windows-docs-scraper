# KSPROPERTY_TUNER_IF_MEDIUM_S structure

## Description

The KSPROPERTY_TUNER_IF_MEDIUM_S structure returns the Medium GUID for the pin that is capable of supporting tuning to an intermediate frequency.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `IFMedium`

Specifies the GUID for the pin that is capable of supporting an intermediate frequency. If no pin supports an intermediate frequency, the minidriver should return GUID_NULL.

## Remarks

Support for the [KSPROPERTY_TUNER_IF_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-if-medium) property causes *Kstvtune.ax* to create an additional pin representing an MPEG-2 transport stream. A data packet sent on this pin in user mode consists only of a [KS_TVTUNER_CHANGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_tvtuner_change_info) structure.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_IF_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-if-medium)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)