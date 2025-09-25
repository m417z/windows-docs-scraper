# IMAPI_FORMAT2_RAW_CD_WRITE_ACTION enumeration

## Description

Defines values that indicate the current state of the write operation when using the [IDiscFormat2RawCDEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcdeventargs) interface.

## Constants

### `IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_UNKNOWN:0`

Indicates an unknown state.

### `IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_PREPARING:0x1`

Preparing to write the session.

### `IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_WRITING:0x2`

Writing session data.

### `IMAPI_FORMAT2_RAW_CD_WRITE_ACTION_FINISHING:0x3`

Synchronizing the drive's cache with the end of the data written to disc.

## See also

[DDiscFormat2RawCDEvents::Update](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-ddiscformat2rawcdevents-update)