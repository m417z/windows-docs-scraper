# _MSR_ERROR_EVENT structure

## Description

This structure contains the error data that is passed to the [MagneticStripeReaderErrorOccured](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn772151(v=vs.85)) event.

## Members

### `Header`

Track 4 error status.

### `Track1Status`

Track 1 error status.

### `Track2Status`

Track 2 error status.

### `Track3Status`

Track 3 error status.

### `Track4Status`

Track 4 error status.

### `Severity`

Severity of the error.

### `Reason`

Reason for the error.

### `ExtendedReason`

Additional information about the error.

### `CardData`

Data read from a swiped magnetic stripe card.

### `Message`

NULL terminated error message.