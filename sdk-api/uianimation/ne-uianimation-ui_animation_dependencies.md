# UI_ANIMATION_DEPENDENCIES enumeration

## Description

Defines which aspects of an interpolator depend on a given input.

## Constants

### `UI_ANIMATION_DEPENDENCY_NONE:0`

No aspect depends on the input.

### `UI_ANIMATION_DEPENDENCY_INTERMEDIATE_VALUES:0x1`

The intermediate values depend on the input.

### `UI_ANIMATION_DEPENDENCY_FINAL_VALUE:0x2`

The final value depends on the input.

### `UI_ANIMATION_DEPENDENCY_FINAL_VELOCITY:0x4`

The final velocity depends on the input.

### `UI_ANIMATION_DEPENDENCY_DURATION:0x8`

The duration depends on the input.

## Remarks

Multiple **UI_ANIMATION_DEPENDENCIES** values can be combined using a bitwise-OR operation.

## See also

[IUIAnimationInterpolator::GetDependencies](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationinterpolator-getdependencies)