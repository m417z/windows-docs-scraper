# CLUS_SCSI_ADDRESS structure

## Description

Contains [SCSI](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) address data. It is
used as the data member of a [CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
structure and as the return value of some [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes)
operations.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.PortNumber`

Identifies the SCSI controller. This corresponds to the
[PortNumber](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-portnumber) property of the
[ClusScsiAddress](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object) object.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.PathId`

Identifies the bus on the SCSI controller specified by **PortNumber**. This
corresponds to the [PathId](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-pathid) property of the
[ClusScsiAddress](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object) object.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.TargetId`

Identifies the target device on the SCSI bus specified by **PathId**. This
corresponds to the [TargetId](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-targetid) property of
the [ClusScsiAddress](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object) object.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Lun`

Identifies the individual logical unit at the target device specified by
**TargetId**. This corresponds to the
[Lun](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-lun) property of the
[ClusScsiAddress](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object) object.

### `DUMMYUNIONNAME.dw`

Numeric value that describes the SCSI address as a combination of the **PortNumber**,
**PathId**, **TargetId**, and **Lun**
values.

## Remarks

A **CLUS_SCSI_ADDRESS** structure can also be returned
by [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) when the
*dwControlCode* parameter is set to
[CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info)
and can be returned by
[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol) when
*dwControlCode* is set to
[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks).

#### Examples

See
[Creating Physical Disk Resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-physical-disk-resources).

## See also

[CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info)

[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks)

[CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)

[ClusScsiAddress Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol)