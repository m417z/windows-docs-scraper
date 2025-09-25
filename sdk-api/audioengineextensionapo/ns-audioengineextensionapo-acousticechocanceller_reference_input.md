## Description

Contains expanded information pertaining to the current Acoustic Echo Cancellation (AEC) configuration.

## Members

### `apoInitSystemEffects`

An APOInitSystemEffects3 structure that provides audio processing object (APO) initialization parameters.

### `streamProperties`

A bitwise combination of values from the [APO_REFERENCE_STREAM_PROPERTIES](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/ne-audioenginebaseapo-apo_reference_stream_properties) that specify requested loopback stream properties.

## Remarks

This structure is passed to the APO's that implement [IApoAcousticEchoCancellation2](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nn-audioenginebaseapo-iapoacousticechocancellation2) as the *pbyData* parameter in [IApoAuxiliaryInputConfiguration::AddAuxiliaryInput](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iapoauxiliaryinputconfiguration-addauxiliaryinput).

## See also