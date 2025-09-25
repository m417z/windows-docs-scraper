# STPFLAG enumeration

## Description

Used by the [ITaskbarList4::SetTabProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist4-settabproperties) method to specify tab properties.

## Constants

### `STPF_NONE:0`

No specific property values are specified. The default behavior is used: the tab window provides a thumbnail and peek image, either live or static as appropriate.

### `STPF_USEAPPTHUMBNAILALWAYS:0x1`

Always use the thumbnail provided by the main application frame window rather than a thumbnail provided by the individual tab window. Do not combine this value with STPF_USEAPPTHUMBNAILWHENACTIVE; doing so will result in an error.

### `STPF_USEAPPTHUMBNAILWHENACTIVE:0x2`

When the application tab is active and a live representation of its window is available, use the main application's frame window thumbnail. At other times, use the tab window thumbnail. Do not combine this value with STPF_USEAPPTHUMBNAILALWAYS; doing so will result in an error.

### `STPF_USEAPPPEEKALWAYS:0x4`

Always use the peek image provided by the main application frame window rather than a peek image provided by the individual tab window. Do not combine this value with STPF_USEAPPPEEKWHENACTIVE; doing so will result in an error.

### `STPF_USEAPPPEEKWHENACTIVE:0x8`

When the application tab is active and a live representation of its window is available, show the main application frame in the peek feature. At other times, use the tab window. Do not combine this value with STPF_USEAPPPEEKALWAYS; doing so will result in an error.