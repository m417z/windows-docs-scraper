# UFX_ENDPOINT_CALLBACKS_INIT function

## Description

The **UFX_ENDPOINT_CALLBACKS_INIT** macro initializes the [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure.

**Note**

Note that there are currently no endpoint callback functions defined in the [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to the [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure.

## Remarks

The **UFX_ENDPOINT_CALLBACKS_INIT** macro will set all fields of the [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure to zero and set the size field appropriately.

**Note** Note that there are currently no endpoint callback functions defined in the [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure.