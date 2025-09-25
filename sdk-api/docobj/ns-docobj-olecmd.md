# OLECMD structure

## Description

Associates command flags from the [OLECMDF](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdf) enumeration with a command identifier through a call to [IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus).

## Members

### `cmdID`

A command identifier; taken from the [OLECMDID](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdid) enumeration.

### `cmdf`

Flags associated with **cmdID**; taken from the [OLECMDF](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdf) enumeration.

## See also

[IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus)

[OLECMDF](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdf)