# _AddiSNSServer_IN structure

## Description

The AddiSNSServer_IN structure holds the input data for the user-mode **AddISNSServer** method, which is used to add a new iSNS server entry to the list of iSNS server names that the initiator maintains.

## Members

### `iSNSServerName`

The iSNS server name to add to the list of iSNS servers that the iSCSI initiator maintains.

## Remarks

It is optional that you implement this method.

## See also

[AddiSNSServer_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_addisnsserver_out)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)