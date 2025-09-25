# _SYNTH_BUFFER structure

## Description

The SYNTH_BUFFER structure specifies DLS data that is being downloaded to a synthesizer.

## Members

### `BufferSize`

Specifies the size in bytes of the buffer that **BufferAddress** points to.

### `BufferAddress`

Pointer to a user-mode address that needs to be converted for kernel use.

## Remarks

A [KSPROPERTY_SYNTH_DLS_DOWNLOAD](https://learn.microsoft.com/previous-versions/ff537396(v=vs.85)) set-property request uses the SYNTH_BUFFER structure for its property value.

## See also

[KSPROPERTY_SYNTH_DLS_DOWNLOAD](https://learn.microsoft.com/previous-versions/ff537396(v=vs.85))