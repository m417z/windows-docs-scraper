# IDiscFormat2TrackAtOnce::CancelAddTrack

## Description

Cancels the current write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2TAO_WRITE_NOT_IN_PROGRESS** | There is no write operation currently in progress.<br><br>Value: 0xC0AA0501 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

To cancel the write operation, you must call this method from the [DDiscFormat2TrackAtOnceEvents::Update](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-ddiscformat2trackatonceevents-update) event handler that you implemented.

You must also call the [IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia) method after calling this method.

Note that calling this method does not immediately cancel the write operation on all media due to media-specific requirements. For example, when writing to a CD, the write operation can continue for up to three more minutes.

This method may result in a partial audio track having already been recorded. The method will attempt to keep the media in a usable state and will simply treat the canceled track as being shorter than originally described by the **IStream**. Callers should query the number of tracks and track sizes after canceling to determine the disc state.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::AddAudioTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-addaudiotrack)