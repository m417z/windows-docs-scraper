# DETECTIONEVENT structure

## Description

Structure to specify uniquely supported detection events available.

## Members

### `EventId`

A unique identifier for the keyword or audio event. This value is provided by Microsoft.

### `EventFeat`

The event features.

### `ProviderId`

The provider Id. This value is provided by Microsoft.

### `DisplayName`

The display name.

### `UserModelValid`

A boolean value indicating if the User Mode Model training is valid. FALSE if user model retraining is required for this event.

## Remarks

This structure is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)