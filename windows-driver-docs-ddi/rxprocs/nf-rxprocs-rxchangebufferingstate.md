# RxChangeBufferingState function

## Description

**RxChangeBufferingState** is called to process a buffering state change request.

## Parameters

### `SrvOpen`

A pointer to the SRV_OPEN data structure to be changed.

### `Context`

A pointer to the context parameter for use by the network mini-redirector callback.

### `ComputeNewState`

The value that indicates if the new buffering state is to be computed. When this value is set to **TRUE**, the new buffering state is determined by calling the network mini-redirector to compute the new buffering state. When this value is **FALSE**, the new buffering state is determined by the *BufferingFlags* member of the passed in *SrvOpen* structure.

## Return value

**RxChangeBufferingState** always returns STATUS_SUCCESS whether this routine was successful or if an error occurs. If an error occurs, the buffering state is changed so that no buffering is enabled.

## Remarks

If local buffering is disabled for this FCB (FCB_STATE_DISABLE_LOCAL_BUFFERING is set in the FcbState structure member of the FCB), this will disable local buffering independent of the open mode on the FCB and any default buffering options. When FCB_STATE_DISABLE_LOCAL_BUFFERING is set, the new buffering state set by **RxChangeBufferingState** will be to disable all buffering.

If *ComputeNewState* is **TRUE**, then the **MRxComputeNewBufferingState** routine exported by the network mini-redirector is called to compute the new buffering state to use.

If the FCB is acquired exclusively and *ComputeNewState* is **FALSE**. then **RxChangeBufferingState** will set the following buffering state options:

* FCB_STATE_WRITECACHING_ENABLED
* FCB_STATE_FILESIZECACHEING_ENABLED
* FCB_STATE_FILETIMECACHEING_ENABLED
* FCB_STATE_WRITEBUFFERING_ENABLED
* FCB_STATE_LOCK_BUFFERING_ENABLED
* FCB_STATE_READBUFFERING_ENABLED
* FCB_STATE_READCACHING_ENABLED

To acquire the FCB exclusively requires that the FCB must not be opened with any of the following values:

* ShareAccess.SharedRead
* ShareAccess.SharedWrite
* ShareAccess.SharedDelete

RDBSS does not currently use a number of possible buffering options, so these options are ignored internally by RDBSS when they are set off using **RxChangeBufferingState**. These ignored buffering options include the following:

* FCB_STATE_WRITEBUFFERING_ENABLED
* FCB_STATE_READBUFFERING_ENABLED
* FCB_STATE_OPENSHARING_ENABLED
* FCB_STATE_COLLAPSING_ENABLED
* FCB_STATE_FILESIZECACHEING_ENABLED
* FCB_STATE_FILETIMECACHEING_ENABLED

If the FCB_STATE_WRITECACHING_ENABLED buffering state is changed to off, any FCB in the system cache is flushed.

On exit from **RxChangeBufferingState**, there is no change in resource ownership.

## See also

[RxIndicateChangeOfBufferingState](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxindicatechangeofbufferingstate)

[RxIndicateChangeOfBufferingStateForSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxindicatechangeofbufferingstateforsrvopen)

[The SRV_OPEN Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-open-structure)