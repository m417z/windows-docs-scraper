# IDiscFormat2TrackAtOnce::get_NumberOfExistingTracks

## Description

Retrieves the number of existing audio tracks on the media.

## Parameters

### `value` [out]

Number of completed tracks written to disc, not including the track currently being added.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED** | The media is not prepared (IDiscFormat2TrackAtOnce::PrepareMedia has not been called).<br><br>Value: 0xC0AA0502 |
| **E_IMAPI_DF2TAO_WRITE_IN_PROGRESS** | A write operation is in progress.<br><br>Value: 0xC0AA0500 |

## Remarks

The value is zero if:

* The media is blank
* You call this method outside a writing session

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::AddAudioTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-addaudiotrack)

[IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia)

[IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia)