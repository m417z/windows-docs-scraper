# KSPROPERTY_CAMERACONTROL_NODE_FOCAL_LENGTH_S structure

## Description

The KSPROPERTY_CAMERACONTROL_NODE_FOCAL_LENGTH_S structure returns node-specific data requested using the [KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-focal-length) property.

## Members

### `NodeProperty`

Specifies both the target node and the property to *get*. This member is an initialized structure of type [KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty).

### `lOcularFocalLength`

Specifies a value of type LONG containing the focal length of the lens closest to the camera user.

### `lObjectiveFocalLengthMin`

Specifies a value of type LONG containing the minimum focal length of the lens closest to the camera subject.

### `lObjectiveFocalLengthMax`

Specifies a value of type LONG containing the maximum focal length of the lens closest to the camera subject.

## Remarks

If the camera has only one lens, these values can be used to represent zoom ratios. See [KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-focal-length).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-focal-length)

[KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_cameracontrol_focal_length_s)

[PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol)