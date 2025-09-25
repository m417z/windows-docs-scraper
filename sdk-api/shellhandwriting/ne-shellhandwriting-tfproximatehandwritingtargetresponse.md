# TfProximateHandwritingTargetResponse enumeration

## Description

Specifies the supported handwriting behaviors based on the proximate location of a handwriting target object.

## Constants

### `TF_NO_HANDWRITING_TARGET_PROXIMATE`

No valid handwriting target is proximate to the target point and the input should be released for non-handwriting purposes.

### `TF_HANDWRITING_TARGET_PROXIMATE`

There is a valid handwriting target proximate to the target point and the system should start the handwriting experience.

### `TF_USE_SYSTEM_TARGETING`

Unable to determine whether a valid handwriting target is proximate so the system should perform default determination logic (the [IHandwritingInputRoutingCallback interface](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nn-shellhandwriting-ihandwritinginputroutingcallback) implementation is still called).

### `TF_USE_POINTER_DELIVERY`

Use pointer input for the handwriting experience.

## Remarks

## See also