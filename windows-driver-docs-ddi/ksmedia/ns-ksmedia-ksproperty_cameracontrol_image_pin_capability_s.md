# KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_S structure

## Description

Describes image pin control properties in the **PROPSETID_VIDCAP_CAMERACONTROL_IMAGE_PIN_CAPABILITY** camera control property set.

## Members

### `Capabilities`

Indicates the image pin control capabilities.

#### KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_EXCLUSIVE_WITH_RECORD

If set, the image pin and the record pin cannot function simultaneously.

#### KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_SEQUENCE_EXCLUSIVE_WITH_RECORD

If set, the image pin and the sequence record pin cannot function simultaneously.

### `Reserved0`

Reserved for system use. Do not use in your driver.

## See also

[KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-image-pin-capability-property)