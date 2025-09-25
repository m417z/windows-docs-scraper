# MF_TOPONODE_DRAIN_MODE enumeration

## Description

Defines at what times a transform in a topology is drained.

## Constants

### `MF_TOPONODE_DRAIN_DEFAULT:0`

The transform is drained when the end of a stream is reached. It is not drained when markout is reached at the end of a segment.

### `MF_TOPONODE_DRAIN_ALWAYS`

The transform is drained whenever a topology ends.

### `MF_TOPONODE_DRAIN_NEVER`

The transform is never drained.

## See also

[MF_TOPONODE_DRAIN](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-drain-attribute)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)