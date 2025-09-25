# _RemoveRADIUSServer_OUT structure

## Description

The RemoveiSNSServer_OUT structure holds the output data for the [RemoveRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/removeradiusserver) method.

## Members

### `Status`

On output from **RemoveRADIUSServer**, the status of the operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[RemoveRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/removeradiusserver)

[RemoveRADIUSServer_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_removeradiusserver_in)