# OLECMDTEXT structure

## Description

Specifies a text name or status string for a single command identifier.

## Members

### `cmdtextf`

A value from the [OLECMDTEXTF](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdtextf) enumeration describing whether the **rgwz** member contains a command name or status text.

### `cwActual`

The number of characters actually written into the **rgwz** buffer before [IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus) returns.

### `cwBuf`

The number of elements in the **rgwz** array.

### `rgwz`

A caller-allocated array of wide characters to receive the command name or status text.

## See also

[IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus)

[OLECMDTEXTF](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdtextf)