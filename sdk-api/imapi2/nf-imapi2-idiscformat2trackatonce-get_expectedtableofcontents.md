# IDiscFormat2TrackAtOnce::get_ExpectedTableOfContents

## Description

Retrieves the table of content for the audio tracks that were laid on the media within the track-writing session.

## Parameters

### `value` [out]

Table of contents for the audio tracks that were laid on the media within the track-writing session. Each element of the list is a **VARIANT** of type **VT_BYREF|VT_UI1**. The **pbVal** member of the variant contains a binary blob. For details of the blob, see the READ TOC command at ftp://ftp.t10.org/t10/drafts/mmc5/mmc5r03.pdf.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2TAO_WRITE_IN_PROGRESS** | A write operation is in progress.<br><br>Value: 0xC0AA0500 |
| **E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED** | The media is not prepared (IDiscFormat2TrackAtOnce::PrepareMedia has not been called).<br><br>Value: 0xC0AA0502 |
| **E_IMAPI_DF2TAO_TABLE_OF_CONTENTS_EMPTY_DISC** | The media is blank.<br><br>Value: 0xC0AA0505 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

The property is not accessible outside a track-writing session. Nor is the property accessible if the disc is blank.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia)

[IDiscFormat2TrackAtOnce::ReleaseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-releasemedia)