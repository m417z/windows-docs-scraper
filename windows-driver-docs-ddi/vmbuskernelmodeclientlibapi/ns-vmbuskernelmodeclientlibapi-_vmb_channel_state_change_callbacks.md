# _VMB_CHANNEL_STATE_CHANGE_CALLBACKS structure

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VMB_CHANNEL_STATE_CHANGE_CALLBACKS** structure contains callback functions that relate to the state changes for a channel.

## Members

### `Version`

The version.

### `Size`

Size of callbacks.

### `EvtChannelOpened`

The channel opened callback function.

### `EvtChannelClosed`

The channel closed callback function.

### `EvtChannelSuspend`

The channel suspended callback function.

### `EvtChannelStarted`

The channel started callback function.

### `EvtChannelPostStarted`

The channel post started callback function.