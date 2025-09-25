# DD_ATTACHLIST structure

## Description

The DD_ATTACHLIST structure maintains a list of attached surfaces for Microsoft DirectDraw.

## Members

### `lpLink`

Points to the next attached surface.

### `lpAttached`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that contains the attached surface local object.