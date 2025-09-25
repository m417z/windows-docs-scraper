# DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION callback function

## Description

Used to destroy a periodic frame notification.

## Parameters

### `pDestroyPeriodicFrameNotification`

A structure of type *PDXGKARG_DESTROYPERIODICFRAMENOTIFICATION* containing the arguments needed to destroy a periodic frame notification.

## Return value

DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|When a periodic frame notification has been successfully created.|
|STATUS_INVALID_PARAMETER|Indicates that there was an invalid parameter passed to the call.|