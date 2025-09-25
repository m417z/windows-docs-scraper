# EVENT_EXTENDED_ITEM_STACK_TRACE32 structure (evntcons.h)

## Description

Defines a call stack on a 32-bit computer.

## Members

### `MatchId`

A unique identifier that you use to match the kernel-mode calls to the user-mode calls; the kernel-mode calls and user-mode calls are captured in separate events if the environment prevents both from being captured in the same event. If the kernel-mode and user-mode calls were captured in the same event, the value is zero.

Typically, on 32-bit computers, you can always capture both the kernel-mode and user-mode calls in the same event. However, if you use the frame pointer optimization compiler option, the stack may not be captured, captured incorrectly, or truncated.

### `Address`

An array of call addresses on the stack.

## Remarks

The **DataSize** member of [EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item) contains the size of this structure. To determine the number of addresses in the array, subtract `sizeof(ULONG64)` from **DataSize** and then divide by `sizeof(ULONG)`.

## See also

[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)