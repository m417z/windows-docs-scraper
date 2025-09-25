# KSPROPERTY_CROSSBAR_PININFO_S structure

## Description

The KSPROPERTY_CROSSBAR_PININFO_S structure describes the crossbar pin information for a device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Direction`

Specifies the minidriver-provided direction of data flow for the pin specified in **Index**. This value can be either **KSPIN_DATAFLOW_IN** or KSPIN_DATAFLOW_OUT.

### `Index`

Specifies the zero-based index of the pin for which crossbar information is being queried. Input pins are queried separately from output pins.

### `PinType`

Specifies the minidriver-provided type of physical connector. This member must be set to one of the KS_PhysicalConnectorType enumerated values defined in *ksmedia.h*:

KS_PhysConn_Video_Tuner

KS_PhysConn_Video_Composite

KS_PhysConn_Video_Svideo

KS_PhysConn_Video_RGB

KS_PhysConn_Video_YRYBY

KS_PhysConn_Video_SerialDigital

KS_PhysConn_Video_ParallelDigital

KS_PhysConn_Video_SCSI

KS_PhysConn_Video_AUX

KS_PhysConn_Video_Video_1394

KS_PhysConn_Video_USB

KS_PhysConn_Video_VideoDecoder

KS_PhysConn_Video_VideoEncoder

KS_PhysConn_Video_SCART

KS_PhysConn_Audio_Tuner

KS_PhysConn_Audio_Line

KS_PhysConn_Audio_Misc

KS_PhysConn_Audio_AESDigital

KS_PhysConn_Audio_SPDIFDigital

KS_PhysConn_Audio_SCSI

KS_PhysConn_Audio_AUX

KS_PhysConn_Audio_1394

KS_PhysConn_Audio_USB

KS_PhysConn_Audio_AudioDecoder

### `RelatedPinIndex`

Specifies the optional pin index of a pin that is related to the pin specified in **Index**. For example, the minidriver can set the **RelatedPinIndex** to the pin index of the audio stream that goes with a video stream in **Index**. **RelatedPinIndex** applies only to pins of the same direction (input or output) as the pin being queried. If no other pins are related to the current pin, the minidriver should return (-1).

### `Medium`

Specifies a [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structure that represents the hardware connection for the pin. This information is returned by the minidriver.

## Remarks

All index values are zero-based, and input pins are counted separately from output pins.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_CROSSBAR_PININFO](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-crossbar-pininfo)

[PROPSETID_VIDCAP_CROSSBAR](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-crossbar)