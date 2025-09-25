# EVENT_EXTENDED_ITEM_STACK_KEY64 structure (evntcons.h)

## Description

Defines an extended item stack key on a 64-bit computer.

## Members

### `MatchId`

A unique identifier that you use to match the kernel-mode calls to the user-mode calls; the kernel-mode calls and user-mode calls are captured in separate events if the environment prevents both from being captured in the same event. If the kernel-mode and user-mode calls were captured in the same event, the value is zero.

### `StackKey`

The key.

## Remarks

## See also