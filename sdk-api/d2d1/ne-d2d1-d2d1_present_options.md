# D2D1_PRESENT_OPTIONS enumeration

## Description

Describes how a render target behaves when it presents its content. This enumeration allows a bitwise combination of its member values.

## Constants

### `D2D1_PRESENT_OPTIONS_NONE:0x00000000`

The render target waits until the display refreshes to present and discards the frame upon presenting.

### `D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS:0x00000001`

The render target does not discard the frame upon presenting.

### `D2D1_PRESENT_OPTIONS_IMMEDIATELY:0x00000002`

The render target does not wait until the display refreshes to present.

### `D2D1_PRESENT_OPTIONS_FORCE_DWORD:0xffffffff`