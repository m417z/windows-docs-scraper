# OLECMDF enumeration

## Description

Specifies the type of support provided by an object for the command specified in an [OLECMD](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-olecmd) structure.

## Constants

### `OLECMDF_SUPPORTED:0x1`

The command is supported by this object.

### `OLECMDF_ENABLED:0x2`

The command is available and enabled.

### `OLECMDF_LATCHED:0x4`

The command is an on-off toggle and is currently on.

### `OLECMDF_NINCHED:0x8`

Reserved for future use.

### `OLECMDF_INVISIBLE:0x10`

The command is hidden.

### `OLECMDF_DEFHIDEONCTXTMENU:0x20`

The command is hidden on the context menu.

## Remarks

Values from the **OLECMDF** enumeration are used to fill the value of the **cmdf** member of [OLECMD](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-olecmd) structures passed to [IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus).

## See also

[IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus)

[OLECMD](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-olecmd)