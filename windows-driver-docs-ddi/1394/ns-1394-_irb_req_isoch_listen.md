# _IRB_REQ_ISOCH_LISTEN structure

## Description

This structure contains the fields necessary to carry out a ReqIsochListen request.

## Members

### `hResource`

Specifies the resource handle to use in reading data.

### `fulFlags`

Reserved. Device drivers must set this to zero.

### `StartTime`

Specifies the cycle time to begin reading data. This member is used only if the driver specified the RESOURCE_SYNCH_ON_TIME flag when it allocated the resource handle passed in **u.IsochListen.hResource**. (The timing resolution is per isochronous cycle, so the **CycleOffset** member of **StartTime** is not used.)

## Remarks

The bus driver completes this request once it has successfully scheduled the isochronous listen operation. It does not wait for the data transfer to finish, or even begin, before it completes the request.

Listening on a channel may begin immediately, or it may be synchronized to an event. If the driver set the RESOURCE_SYNCH_ON_TIME flag on the REQUEST_ISOCH_ALLOCATE_RESOURCES request that returned the resource handle, then the listen begins on the cycle count specified in **StartTime**. Additional synchronization options may be set for each buffer within that buffer's ISOCH_DESCRIPTOR structure.