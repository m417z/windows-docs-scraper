# KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S structure

## Description

The KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S structure describes the scanning capabilities of a broadcast network type that a tuning device supports.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `NetworkType`

A GUID for the broadcast network type for which the tuner filter receives capabilities. The driver returned this GUID as an element in the array that the **GUIDBucket** member of the [KSPROPERTY_TUNER_SCAN_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_tuner_scan_caps_s) structure specifies in a call to the driver's [KSPROPERTY_TUNER_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-scan-caps) property.

### `BufferSize`

The size, in bytes, of the buffer that is required to hold the network capabilities and that the **NetworkTunerCapabilities** member points to.

### `NetworkTunerCapabilities`

A pointer to a buffer to hold the scanning capabilities of a broadcast network type. For example, if the ANALOG_TV_NETWORK_TYPE GUID is set in the **NetworkType** member, the driver fills the buffer with a populated [TUNER_ANALOG_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tuner_analog_caps_s) structure.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-networktype-scan-caps)

[KSPROPERTY_TUNER_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-scan-caps)

[KSPROPERTY_TUNER_SCAN_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_tuner_scan_caps_s)

[TUNER_ANALOG_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tuner_analog_caps_s)