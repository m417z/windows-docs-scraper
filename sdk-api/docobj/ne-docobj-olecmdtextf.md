# OLECMDTEXTF enumeration

## Description

Specifies the type of information that an object should store in the [OLECMDTEXT](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-olecmdtext) structure passed in [IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus). One value from this enumeration is stored the **cmdtextf** member of the **OLECMDTEXT** structure to indicate the desired information.

## Constants

### `OLECMDTEXTF_NONE:0`

No extra information is requested.

### `OLECMDTEXTF_NAME:1`

The object should provide the localized name of the command.

### `OLECMDTEXTF_STATUS:2`

The object should provide a localized status string for the command.

## See also

[IOleCommandTarget::QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus)

[OLECMDTEXT](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-olecmdtext)