# SBE2_STREAM_DESC structure

## Description

Describes a stream produced by the stream buffer engine.

## Members

### `Version`

The version number of the stream. Currently the following value is defined.

#### SBE2_STREAM_DESC_VERSION

### `StreamId`

The identifier of the stream.

### `Default`

Specifies whether the steam is the default for the current media type. If the value is nonzero, the stream is the default. If the value is zero, the stream is not the default.

### `Reserved`

Reserved.

## See also

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)

[Stream Buffer Engine Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-structures)