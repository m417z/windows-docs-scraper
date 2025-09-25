# MANIPULATION_PROCESSOR_MANIPULATIONS enumeration

## Description

The **MANIPULATION_PROCESSOR_MANIPULATIONS** enumeration different kinds of manipulation which can be applied on a target object.

## Constants

### `MANIPULATION_NONE:0`

Indicates that no manipulations are performed.

### `MANIPULATION_TRANSLATE_X:0x1`

Indicates manipulation by moving the target across the horizontal axis.

### `MANIPULATION_TRANSLATE_Y:0x2`

Indicates manipulation by moving the target across the vertical axis.

### `MANIPULATION_SCALE:0x4`

Indicates manipulation by making the target larger or smaller.

### `MANIPULATION_ROTATE:0x8`

Indicates manipulation by rotating the target.

### `MANIPULATION_ALL:0xf`

Indicates all manipulations are enabled.

## Remarks

Use this enumeration with the [SupportedManipulations](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-get_supportedmanipulations) property to get and
set the kind of manipulation data you want to receive from the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) interface.
You can combine different kinds of manipulations by a bitwise OR.

#### Examples

```cpp

        CoInitialize(0);

        hr = spIManipProc.CoCreateInstance(CLSID_ManipulationProcessor, NULL, CLSCTX_ALL);

        MANIPULATION_PROCESSOR_MANIPULATIONS mpm;
        spIManipProc->get_SupportedManipulations(&mpm);

```

## See also

[Enumerations](https://learn.microsoft.com/windows/desktop/wintouch/rts-functions)