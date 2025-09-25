# DIRECTMANIPULATION_STATUS enumeration

## Description

Defines the possible states of [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal). The viewport can process input in any state unless otherwise noted.

## Constants

### `DIRECTMANIPULATION_BUILDING:0`

The viewport is being initialized and is not yet able to process input.

### `DIRECTMANIPULATION_ENABLED:1`

The viewport was successfully enabled.

### `DIRECTMANIPULATION_DISABLED:2`

The viewport is disabled and cannot process input or callbacks. The viewport can be enabled by calling [Enable](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-enable).

### `DIRECTMANIPULATION_RUNNING:3`

The viewport is currently processing input and updating content.

### `DIRECTMANIPULATION_INERTIA:4`

The viewport is moving content due to inertia.

### `DIRECTMANIPULATION_READY:5`

The viewport has completed the previous interaction.

### `DIRECTMANIPULATION_SUSPENDED:6`

The transient state of the viewport when input has been promoted to an ancestor in the [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) chain.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)