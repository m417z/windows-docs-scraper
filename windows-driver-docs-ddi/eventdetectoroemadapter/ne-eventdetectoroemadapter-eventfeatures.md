# EVENTFEATURES enumeration

## Description

Enumeration that defines event features.

## Constants

### `EVENTFEATURES_NoEventFeatures`

0x0 - No event features.

### `EVENTFEATURES_SupportsUserTraining`

0x1 - SpeakerID support.

### `EVENTFEATURES_SupportUserCustomization`

0x2 - User defined keyword.

### `EVENTFEATURES_ArmPatternRequiresArmState`

0x4 - Is active arm state required for BuildArmingPatternData (Global only feature).

### `EVENTFEATURES_SupportsSingleLanguage`

0x8 - Does detector support a single language for all keywords.

## Remarks

This enumeration is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)