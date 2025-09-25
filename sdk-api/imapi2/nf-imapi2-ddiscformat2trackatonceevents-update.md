# DDiscFormat2TrackAtOnceEvents::Update

## Description

Implement this method to receive progress notification of the current track-writing operation.

## Parameters

### `object` [in]

The [IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce) interface that initiated the write operation.

This parameter is a **MsftDiscFormat2TrackAtOnce** object in script.

### `progress` [in]

An [IDiscFormat2TrackAtOnceEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonceeventargs) interface that you use to determine the progress of the write operation.

This parameter is a **MsftDiscFormat2TrackAtOnce** object in script.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling the [IDiscFormat2TrackAtOnce::AddAudioTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-addaudiotrack) method.

To stop the write process, call the [IDiscFormat2TrackAtOnce::CancelAddTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-canceladdtrack) method.

## See also

[DDiscFormat2TrackAtOnceEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2trackatonceevents)

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::CancelAddTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-canceladdtrack)