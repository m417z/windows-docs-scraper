# MF_TOPONODE_FLUSH_MODE enumeration

## Description

Defines when a transform in a topology is flushed.

## Constants

### `MF_TOPONODE_FLUSH_ALWAYS:0`

The transform is flushed whenever the stream changes, including seeks and new segments.

### `MF_TOPONODE_FLUSH_SEEK`

The transform is flushed when seeking is performed on the stream.

### `MF_TOPONODE_FLUSH_NEVER`

The transform is never flushed during streaming. It is flushed only when the object is released.

## See also

[MF_TOPONODE_FLUSH](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-flush-attribute)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)