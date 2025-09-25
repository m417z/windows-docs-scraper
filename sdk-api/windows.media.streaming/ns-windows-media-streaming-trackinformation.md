# TrackInformation structure

## Description

Contains the current track number and duration as part of the [PositionInformation](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828991(v=vs.85)) obtained from the DMR.

## Members

### `streaming.TrackInformation.Track`

### `streaming.TrackInformation.TrackId`

### `streaming.TrackInformation.TrackDuration`

### `Track`

The current track number as reported by DMR. If the DMR does not have a concept of track numbers, this value will be 0.

### `TrackDuration`

The duration of the current track.