# IMAPI_FORMAT2_TAO_WRITE_ACTION enumeration

## Description

Defines values that indicate the current state of the write operation when using the [IDiscFormat2TrackAtOnceEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonceeventargs) interface.

## Constants

### `IMAPI_FORMAT2_TAO_WRITE_ACTION_UNKNOWN:0`

Indicates an unknown state.

### `IMAPI_FORMAT2_TAO_WRITE_ACTION_PREPARING:0x1`

Preparing to write the track.

### `IMAPI_FORMAT2_TAO_WRITE_ACTION_WRITING:0x2`

Writing the track.

### `IMAPI_FORMAT2_TAO_WRITE_ACTION_FINISHING:0x3`

Closing the track or closing the session.

### `IMAPI_FORMAT2_TAO_WRITE_ACTION_VERIFYING:0x4`

## See also

[DDiscFormat2TrackAtOnceEvents::Update](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-ddiscformat2trackatonceevents-update)