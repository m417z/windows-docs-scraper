# TransportState enumeration

## Description

Defines the available transport states as defined by the UPnP Guidelines.

## Constants

### `TransportState_Unknown:0`

### `TransportState_Stopped:1`

### `TransportState_Playing:2`

### `TransportState_Transitioning:3`

### `TransportState_Paused:4`

### `TransportState_Recording:5`

### `TransportState_NoMediaPresent:6`

### `TransportState_Last:7`

#### - Last

The device’s previous state to the current transport state.

#### - NoMediaPresent

The device’s transport does not have an URI set for playback.

#### - Paused

The device’s transport is in a paused state.

#### - Playing

The device’s transport is in a playing state.

#### - Recording

The device’s transport is in a recording state.

#### - Stopped

The device’s transport is in a stopped state.

#### - Transitioning

The device’s transport is in a transitioning state which will result in another state value.

#### - Unknown

Erroneous device state.