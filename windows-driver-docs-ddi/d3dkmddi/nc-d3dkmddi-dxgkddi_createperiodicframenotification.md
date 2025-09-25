# DXGKDDI_CREATEPERIODICFRAMENOTIFICATION callback function

## Description

Used to create a periodic frame notification.

## Parameters

### `pCreatePeriodicFrameNotification`

A structure of type *PDXGKARG_CREATEPERIODICFRAMENOTIFICATION* containing the arguments needed to create a periodic frame notification.

## Return value

DXGKDDI_CREATEPERIODICFRAMENOTIFICATION returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|When a periodic frame notification has been successfully created.|
|STATUS_NO_MEMORY|When a periodic frame notification does not have enough memory to be allocated.|
|STATUS_INVALID_PARAMETER|Indicates that there was an invalid parameter passed to the call.|
|STATUS_UNSUCCESSFUL|When a periodic frame notification has not been successfully created.|