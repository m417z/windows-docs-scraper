# _CMP_MONITOR_INFO structure

## Description

The CMP_MONITOR_INFO structure is used in conjunction with the Av61883_MonitorPlugs request to allow a driver to monitor access to local oPCR and iPCR plugs.

## Members

### `State`

The current state of the plug.

### `PlugNum`

The number of the plug that was accessed.

### `PlugType`

The type of plug, either CMP_PlugOut or CMP_PlugIn.

### `Pcr`

The current contents of the plug.

### `Context`

Points to a caller-defined context that was registered with Av61883_MonitorPlugs.

## See also

[AV_61883_REQUEST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)