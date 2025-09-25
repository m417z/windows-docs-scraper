# KS_DVDCOPYSTATE enumeration

## Description

The KS_DVDCOPYSTATE enumeration describes the progress of the DVD copyright protection initialization, authentication and key negotiation sequence.

## Constants

### `KS_DVDCOPYSTATE_INITIALIZE`

Indicates that the full copyright protection sequence is starting.

### `KS_DVDCOPYSTATE_INITIALIZE_TITLE`

Indicates that a title key copyright protection sequence is starting.

### `KS_DVDCOPYSTATE_AUTHENTICATION_NOT_REQUIRED`

Indicates that no authentication is required.

### `KS_DVDCOPYSTATE_AUTHENTICATION_REQUIRED`

Indicates that authentication is required.

### `KS_DVDCOPYSTATE_DONE`

Indicates that the copyright protection sequence is complete.

## See also

[KSPROPERTY_DVDCOPY_SET_COPY_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-set-copy-state)

[KS_DVDCOPY_SET_COPY_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_dvdcopy_set_copy_state)