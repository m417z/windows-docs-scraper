# KS_AMVP_MODE enumeration

## Description

The KS_AMVP_MODE enumeration defines video port display modes.

## Constants

### `KS_AMVP_MODE_WEAVE`

Specifies the weave method to display interlaced video. In the weave mode, alternating fields are combined to form a single frame.

### `KS_AMVP_MODE_BOBINTERLEAVED`

Specifies the interleaved bob method to display video. In the interleaved bob mode, each field is displayed individually, and the gaps between fields are filled with interpolated values.

### `KS_AMVP_MODE_BOBNONINTERLEAVED`

Specifies the non-interleaved bob method to display video.

### `KS_AMVP_MODE_SKIPEVEN`

Specifies that even video fields should be skipped when displaying video.

### `KS_AMVP_MODE_SKIPODD`

Specifies that odd video fields should be skipped when displaying video.