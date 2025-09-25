# MFSESSION_SETTOPOLOGY_FLAGS enumeration

## Description

Defines the behavior of the [IMFMediaSession::SetTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-settopology) method.

## Constants

### `MFSESSION_SETTOPOLOGY_IMMEDIATE:0x1`

Stop the current presentation, clear all pending presentations, and immediately queue the new topology (specified by the *pTopology* parameter).

If the *pTopology* parameter is **NULL**, this flag has no effect.

### `MFSESSION_SETTOPOLOGY_NORESOLUTION:0x2`

The topology does not need to be resolved. Use this flag if you are setting a full topology.

### `MFSESSION_SETTOPOLOGY_CLEAR_CURRENT:0x4`

**Note** Requires Windows 7.

Clear the current topology, as follows:

* If *pTopology* is not **NULL**, the topology is cleared only if *pTopology* matches the current topology (that is, only if *pTopology* points to the current topology).
* If the *pTopology* parameter is **NULL**, the current topology is cleared, regardless of which topology is current.

Pending topologies are not removed from the playback queue. If there is a pending topology on the queue, that topology will be loaded after the current topology is cleared. Otherwise, playback simply stops.

To remove all of the pending topologies from the queue, call [IMFMediaSession::ClearTopologies](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-cleartopologies).

## Remarks

These flags are optional, and are not mutually exclusive. If no flags are set, the Media Session resolves the topology and then adds it to the queue of pending presentations.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)