# IOCTL_BTHHFP_DEVICE_GET_VOLUMEPROPERTYVALUES IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_VOLUMEPROPERTYVALUES**
IOCTL returns [KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values) data for the [KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel) property.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

A buffer containing a [KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values) structure followed by any other data referenced by this structure.

### Output buffer length

The size of a [KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values) structure and referenced data.

### Input/output buffer

### Input/output buffer length

### Status block

N/A

## Remarks

The audio driver’s KS filter topology includes a KS node of type [KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume) for both input and output if the [BTHHFP_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ns-bthhfpddi-_bthhfp_descriptor) descriptor indicates volume support. The audio driver’s [KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor) structure for this node includes a [PKSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item) for the **KSPROPERTY_AUDIO_VOLUMELEVEL** property. The audio driver sets the **PKSPROPERTY_ITEM**.*Values* member to the [KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values) structured returned by this request.

This allows the Handsfree profile (HFP) driver to almost entirely handle the problem of mapping **KSPROPERTY_AUDIO_VOLUMELEVEL** property values to the Bluetooth Handsfree profile. The audio driver’s property Get and Set handlers for this property simply call the HFP driver.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)

[KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)

[KSPROPERTY_VALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)