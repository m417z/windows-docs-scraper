# _MSiSCSI_PortalInfoClass structure

## Description

The MSiSCSI_PortalInfoClass structure contains information about a collection of iSCSI portals.

## Members

### `PortalInfoCount`

The number of portals that the initiator discovered and for which portal information is available.

### `PortalInformation`

A variable length array of [ISCSI_PortalInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_portalinfo) structures. The number of elements in the array is specified by the **PortalInfoCount** field.

## Remarks

We recommend that you implement this class.

## See also

[ISCSI_PortalInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_portalinfo)

[MSiSCSI_PortalInfoClass WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-portalinfoclass-wmi-class)