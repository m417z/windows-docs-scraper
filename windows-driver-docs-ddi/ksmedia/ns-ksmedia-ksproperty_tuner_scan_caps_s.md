# KSPROPERTY_TUNER_SCAN_CAPS_S structure

## Description

The KSPROPERTY_TUNER_SCAN_CAPS_S structure describes the hardware scanning capabilities of a tuning device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `fSupportsHardwareAssistedScanning`

A Boolean value that indicates whether the driver or firmware for a tuner supports hardware-assisted scanning operations. **TRUE** indicates that the driver or firmware for a tuner supports hardware-assisted scanning operations. **FALSE** indicates that the driver or firmware does not support hardware-assisted scanning operations.

### `SupportedBroadcastStandards`

The number of broadcast video standard types that the tuning device can support. A hybrid tuner can support multiple types.

### `GUIDBucket`

An array of GUIDs for the network types that the tuning device supports.

Based on the supported number in **SupportedBroadcastStandards** that is returned in the initial call to the [KSPROPERTY_TUNER_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-scan-caps) property, the analog or digital tuner filter then allocates an array of GUIDs. The driver uses this allocated user buffer to return all the supported GUIDs in the next call to KSPROPERTY_TUNER_SCAN_CAPS. The driver must call the [ProbeForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforwrite) function to validate this user buffer and must ensure that the length of the buffer is valid. Although unlikely, if the driver will access this buffer in an arbitrary thread, it should map the buffer into kernel space. Currently, scanning capabilities are defined for supporting the analog standard. If the driver supports analog and the application intends to start a scanning session for analog, the corresponding capabilities are defined by the [KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-networktype-scan-caps) property. Other scanning capabilities to support other broadcast standards (for example, DVB-S) are not yet supported.

### `lengthofBucket`

The number of GUIDs in the **GUIDBucket** array.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-networktype-scan-caps)

[KSPROPERTY_TUNER_SCAN_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-scan-caps)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)