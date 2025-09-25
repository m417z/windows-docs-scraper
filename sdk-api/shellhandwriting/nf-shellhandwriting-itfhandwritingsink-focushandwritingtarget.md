# FocusHandwritingTarget function

## Description

Sets focus to the edit control that receives the input.

## Parameters

### `focusHandwritingTargetArgs` [in]

The event arguments

## Return value

A handle to the edit control that receives the input.

## Remarks

This function is called only when a valid handwriting target is identified through the [DetermineProximateHandwritingTarget function](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwritingsink-determineproximatehandwritingtarget) and only when handwriting recognition is to be provided for the input.

The application that implements this function is required to set focus to the most likely edit control based on *focusHandwritingTargetArgs*. This control is where the system will insert the result of handwriting recognition.

## See also