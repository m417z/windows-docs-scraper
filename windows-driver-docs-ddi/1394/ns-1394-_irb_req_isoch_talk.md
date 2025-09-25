# _IRB_REQ_ISOCH_TALK structure

## Description

This structure contains the field necessary to carry out a IsochTalk request.

## Members

### `hResource`

Specifies the resource handle to use for this operation. Resources are acquired through the REQUEST_ISOCH_ALLOCATE_RESOURCES request.

### `fulFlags`

Reserved. Drivers should set this to zero.

### `StartTime`

Specifies the cycle time to begin operation. This member is used only if the driver specified the RESOURCE_SYNCH_ON_TIME flag when it allocated the resource handle passed in **u.IsochTalk.hResource**. (The timing resolution is per isochronous cycle, so the **CycleOffset** member of **StartTime** is not used.)

## Remarks

Talking on a channel may begin immediately, or it may be synchronized to an event. If the driver set the RESOURCE_SYNCH_ON_TIME flag on the REQUEST_ISOCH_ALLOCATE_RESOURCES request that returned the resource handle, then the write operation begins on the specified cycle count. Additional synchronization options can be set for each buffer in the ISOCH_DESCRIPTOR structure.

If successful, the request returns a STATUS_SUCCESS value. The call returns immediately, and does not wait for any synchronization events. The bus driver calls the callback the driver provides in ISOCH_DESCRIPTOR to signal that it has finished processing an attached buffer.