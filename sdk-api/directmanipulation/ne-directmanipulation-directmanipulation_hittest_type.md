# DIRECTMANIPULATION_HITTEST_TYPE enumeration

## Description

Defines how hit testing is handled by [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) when using a dedicated hit-test thread registered through [RegisterHitTestTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager-registerhittesttarget).

## Constants

### `DIRECTMANIPULATION_HITTEST_TYPE_ASYNCHRONOUS:0`

The hit-test thread receives [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages and specifies whether to call [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact). If **SetContact** is not called, the contact will not be associated with a viewport.

### `DIRECTMANIPULATION_HITTEST_TYPE_SYNCHRONOUS:0x1`

The UI thread always receives [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages after the hit-test thread. A call to [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) is not required.

### `DIRECTMANIPULATION_HITTEST_TYPE_AUTO_SYNCHRONOUS:0x2`

The UI thread receives [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages only when [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) isn't called by the hit-test thread.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)