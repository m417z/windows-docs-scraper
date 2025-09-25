## Description

The **KSCAMERA_EXTENDEDPROP_BACKGROUNDSEGMENTATION_CONFIGCAPS** structure is used to list which stream configurations support background segmentation when using the **KSPROPERTY_CAMERACONTROL_EXTENDED_BACKGROUNDSEGMENTATION** control so that consumer of this DDI knows what to expect when it is leveraged and in which cases it may not take effect.

If a stream configuration is not listed and the control is set to something other than **KSCAMERA_EXTENDEDPROP_BACKGROUNDSEGMENTATION_OFF**, the DDI may have no effect.

## Members

### `Resolution`

The width and height of the output format in pixels for which the **MaxFrameRate** and **MaskResolution** apply.

### `MaxFrameRate`

The maximum frame rate the driver can accommodate for achieving background segmentation for each frame corresponding to **Resolution**.

### `MaxFrameRate.Numerator`

Defines the **LONG** member **Numerator**.

### `MaxFrameRate.Denominator`

Defines the **LONG** member **Denominator**.

### `MaskResolution`

The width and height of the mask produced when streaming with a MediaType corresponding to **Resolution**.

### `SubType`

Optional subtype for which this configuration capability applies. If left to zero, all streams conforming the **Resolution** and **MaxFrameRate** will support background segmentation with the specified **MaskResolution**.

## Remarks

Two **KSPROPERTY_CAMERACONTROL_EXTENDED_BACKGROUNDSEGMENTATION** controls with the same **Resolution** but different **MaxFrameRate** and **MaskResolution** may be specified to express that different frame rates may produce a different mask resolution.

## See also

[KSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_metadata_backgroundsegmentationmask)