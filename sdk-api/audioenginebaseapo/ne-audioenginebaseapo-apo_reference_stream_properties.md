## Description

Specifies requested loopback stream properties.

## Constants

### `APO_REFERENCE_STREAM_PROPERTIES_NONE`

No loopback stream properties.

### `APO_REFERENCE_STREAM_PROPERTIES_POST_VOLUME_LOOPBACK`

The loopback stream should be tapped after volume and/or mute are applied, if supported by the audio endpoint.

## Remarks

APOs request loopback stream properties by returning a bitwise combination of flags from this enumeration from an implementation of the [IApoAcousticEchoCancellation2::GetDesiredReferenceStreamProperties](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iapoacousticechocancellation2-getdesiredreferencestreamproperties) method.

## See also