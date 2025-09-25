## Description

The **ACX_CONSTRICTOR_OPTION** enumeration defines the options for the loopback protection status of a stream audio engine node.

## Constants

### `AcxConstrictorOptionNone`

This is the default state for the loopback protection status of a stream. When all active streams are in this state it indicates that the loopback tap contains meaningful data.

### `AcxConstrictorOptionMute`

When an active stream is in this state it indicates that the loopback tap for the audio output will emit silence.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)