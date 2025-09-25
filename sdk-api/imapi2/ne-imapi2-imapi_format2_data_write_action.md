# IMAPI_FORMAT2_DATA_WRITE_ACTION enumeration

## Description

Defines values that indicate the current state of the write operation when using the [IDiscFormat2DataEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2dataeventargs) interface.

## Constants

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_VALIDATING_MEDIA:0`

Validating that the current media is supported.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_FORMATTING_MEDIA:0x1`

Formatting media, when required.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_INITIALIZING_HARDWARE:0x2`

Initializing the hardware, for example, setting drive write speeds.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_CALIBRATING_POWER:0x3`

Optimizing laser intensity for writing to the media.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_WRITING_DATA:0x4`

Writing data to the media.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_FINALIZATION:0x5`

Finalizing the write. This state is media dependent and can include items such as closing the track or session, or finishing background formatting.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_COMPLETED:0x6`

Successfully finished the write process.

### `IMAPI_FORMAT2_DATA_WRITE_ACTION_VERIFYING:0x7`

Verifying the integrity of the burned media.

## See also

[IDiscFormat2DataEventArgs::get_CurrentAction](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2dataeventargs-get_currentaction)