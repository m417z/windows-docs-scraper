# IDirectManipulationAutoScrollBehavior::SetConfiguration

## Description

Performs the auto-scroll animation for the viewport this behavior is attached to.

## Parameters

### `motionTypes` [in]

A combination of **DIRECTMANIPULATION_MOTION_TRANSLATEX** and **DIRECTMANIPULATION_MOTION_TRANSLATEY** from [DIRECTMANIPULATION_MOTION_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_motion_types). **DIRECTMANIPULATION_MOTION_NONE** cannot be specified.

### `scrollMotion` [in]

One of the values from [DIRECTMANIPULATION_AUTOSCROLL_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_autoscroll_configuration).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SetConfiguration** takes effect immediately. If the content is not in inertia, and **DIRECTMANIPULATION_AUTOSCROLL_CONFIGURATION_STOP** is specified for *scrollMotion*, then this method returns S_FALSE.

#### Examples

```cpp
spAutoScrollBehavior->SetConfiguration(DIRECTMANIPULATION_MOTION_TRANSLATEX, DIRECTMANIPULATION_AUTOSCROLL_CONFIGURATION_FORWARD));
```

## See also

[IDirectManipulationAutoScrollBehavior](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationautoscrollbehavior)