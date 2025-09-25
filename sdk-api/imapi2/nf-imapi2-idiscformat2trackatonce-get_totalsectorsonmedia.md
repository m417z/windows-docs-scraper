# IDiscFormat2TrackAtOnce::get_TotalSectorsOnMedia

## Description

Retrieves the total sectors available on the media if writing one continuous audio track.

## Parameters

### `value` [out]

Number of all sectors on the media that can be used for audio if one continuous audio track was recorded.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED** | The media is not prepared (IDiscFormat2TrackAtOnce::PrepareMedia has not been called).<br><br>Value: 0xC0AA0502 |

## Remarks

This property can be retrieved at any time; however, during writing, the value is cached.

## See also

[IDiscFormat2Data::get_FreeSectorsOnMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_freesectorsonmedia)

[IDiscFormat2Data::get_TotalSectorsOnMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_totalsectorsonmedia)

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::get_FreeSectorsOnMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_freesectorsonmedia)

[IDiscFormat2TrackAtOnce::get_UsedSectorsOnMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_usedsectorsonmedia)