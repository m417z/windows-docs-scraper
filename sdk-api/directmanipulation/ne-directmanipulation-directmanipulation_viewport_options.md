# DIRECTMANIPULATION_VIEWPORT_OPTIONS enumeration

## Description

Defines the input behavior options for the viewport.

## Constants

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_DEFAULT:0`

No special behaviors. This is the default value used to set or revert to default behavior.

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_AUTODISABLE:0x1`

At the end of an interaction, the viewport transitions to [DIRECTMANIPULATION_READY](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_status) and then immediately to **DIRECTMANIPULATION_DISABLED**. The viewport must be explicitly enabled through the [Enable](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-enable) method before the next interaction can be processed.

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_MANUALUPDATE:0x2`

[Update](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationupdatemanager-update) must be called to redraw the content within the viewport. The content is not updated automatically during an input event.

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_INPUT:0x4`

All input from a contact associated with the viewport is passed to the UI thread for processing.

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_EXPLICITHITTEST:0x8`

If set, all [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages are passed to the application for hit testing. Otherwise, [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) will process the messages for hit testing against the existing list of running viewports, and the application will not see the input.

Applies only when viewport state is [DIRECTMANIPULATION_RUNNING](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_status) or **DIRECTMANIPULATION_INERTIA**.

### `DIRECTMANIPULATION_VIEWPORT_OPTIONS_DISABLEPIXELSNAPPING:0x10`

Specifies that pixel snapping during a manipulation is disabled.

Anti-aliasing can create irregular edge rendering. Artifacts, commonly seen as blurry, or semi-transparent, edges can occur when the location of an edge falls in the middle of a device pixel rather than between device pixels.

## Remarks

**DIRECTMANIPULATION_VIEWPORT_OPTIONS** is used in the [SetViewportOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setviewportoptions) method. These flags can be combined to set the input behavior for a viewport.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)