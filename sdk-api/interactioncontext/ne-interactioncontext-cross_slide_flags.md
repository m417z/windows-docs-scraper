# CROSS_SLIDE_FLAGS enumeration

## Description

Specifies the state of the cross-slide interaction.

## Constants

### `CROSS_SLIDE_FLAGS_NONE:0x00000000`

No cross-slide interaction.

### `CROSS_SLIDE_FLAGS_SELECT:0x00000001`

Cross-slide interaction has crossed a distance threshold and is in select mode.

### `CROSS_SLIDE_FLAGS_SPEED_BUMP:0x00000002`

Cross-slide interaction is in speed bump mode.

### `CROSS_SLIDE_FLAGS_REARRANGE:0x00000004`

Cross-slide interaction has crossed the speed bump threshold and is in rearrange (drag and drop) mode.

### `CROSS_SLIDE_FLAGS_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[INTERACTION_ARGUMENTS_CROSS_SLIDE structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_arguments_cross_slide)