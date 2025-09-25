# _AddRADIUSServer_OUT structure

## Description

The AddRADIUSServer_OUT structure holds the output data for the [AddRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/addradiusserver) method.

## Members

### `Status`

On output from **AddRADIUSServer**, the status of the **AddRADIUSServer** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

## Remarks

It is optional that you implement this method.

## See also

[AddRADIUSServer](https://learn.microsoft.com/windows-hardware/drivers/storage/addradiusserver)

[AddRADIUSServer_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addradiusserver_in)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)