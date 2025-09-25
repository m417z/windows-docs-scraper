# IMAPI_CD_TRACK_DIGITAL_COPY_SETTING enumeration

## Description

Defines the digital copy setting values available for a given track.

## Constants

### `IMAPI_CD_TRACK_DIGITAL_COPY_PERMITTED:0`

Digital copies of the given track are allowed.

### `IMAPI_CD_TRACK_DIGITAL_COPY_PROHIBITED:0x1`

Digital copies of the given track are not allowed using consumer electronics CD recorders. This condition typically has no effect on PC-based CD players.

### `IMAPI_CD_TRACK_DIGITAL_COPY_SCMS:0x2`

The given track is a digital copy of a copy protected track. No further copies using consumer electronics CD recorders will be allowed. This condition typically has no effect on PC-based CD players.