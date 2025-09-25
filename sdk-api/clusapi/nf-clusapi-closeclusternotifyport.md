# CloseClusterNotifyPort function

## Description

Closes a notification port established through [CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport). The **PCLUSAPI_CLOSE_CLUSTER_NOTIFY_PORT** type defines a pointer to this function.

## Parameters

### `hChange` [in]

Handle to the notification port to close.

## Return value

This function always returns **TRUE**.

## See also

[CreateClusterNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyport)

[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify)

[RegisterClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-registerclusternotify)