# IDiscFormat2TrackAtOnce::put_DoNotFinalizeMedia

## Description

Determines if the media is left open for writing after writing the audio track.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to leave the media open for writing after writing the audio track; otherwise, VARIANT_FALSE. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2TAO_WRITE_IN_PROGRESS** | A write operation is in progress.<br><br>Value: 0xC0AA0500 |
| **E_IMAPI_DF2TAO_MEDIA_IS_PREPARED** | The requested operation is not valid when media has been "prepared" but not released.<br><br>Value: 0xC0AA0503 |
| **E_IMAPI_DF2TAO_PROPERTY_FOR_BLANK_MEDIA_ONLY** | The property cannot be changed once the media has been written to.<br><br>Value: 0xC0AA0504 |

## Remarks

You can set this property before calling the [IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia) method or after calling the [IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia) method; you cannot set it during a track-writing session.

This property is useful to create a multi-session CD with audio in the first session and data in the second session.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia)

[IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia)

[IDiscFormat2TrackAtOnce::get_DoNotFinalizeMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_donotfinalizemedia)