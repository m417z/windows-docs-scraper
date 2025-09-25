# IDiscFormat2TrackAtOnce::get_DoNotFinalizeMedia

## Description

Determines if the media is left open for writing after writing the audio track.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the media is left open for writing after writing the audio track; otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia)

[IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia)

[IDiscFormat2TrackAtOnce::put_DoNotFinalizeMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_donotfinalizemedia)