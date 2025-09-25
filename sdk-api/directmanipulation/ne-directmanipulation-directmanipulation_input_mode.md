# DIRECTMANIPULATION_INPUT_MODE enumeration

## Description

Defines the threading behavior for [SetInputMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setinputmode) or [SetUpdateMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setupdatemode). The exact meaning of each constant depends on the method called.

## Constants

### `DIRECTMANIPULATION_INPUT_MODE_AUTOMATIC:0`

Input is automatically passed to the viewport in an independent thread.

### `DIRECTMANIPULATION_INPUT_MODE_MANUAL:1`

Input is manually passed by the app on its thread via the [ProcessInput](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-processinput) method.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)