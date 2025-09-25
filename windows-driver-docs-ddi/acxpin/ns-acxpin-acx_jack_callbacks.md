## Description

The **ACX_JACK_CALLBACKS** structure specifies audio jack event callback functions.

## Members

### `Size`

The size of all of the data in the **ACX_JACK_CALLBACKS** structure in bytes.

### `EvtAcxJackRetrievePresenceState`

A pointer to the callback function that determines if the jack is present on the system.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)