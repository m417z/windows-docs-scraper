# VDS_FILE_SYSTEM_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of file-system events.

## Members

### `ulEvent`

Determines the file-system event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_FILE_SYSTEM_MODIFY**<br><br>203 | A member was changed in the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure for the file system. For example, a volume received a new label, or a file system was extended or shrunk; does not include a change to the file-system compression flags. |
| **VDS_NF_FILE_SYSTEM_FORMAT_PROGRESS**<br><br>204 | A file system volume is being formatted. |

### `volumeId`

The GUID of the volume object containing the file system that triggered the event.

### `dwPercentCompleted`

The completed format progress as a percentage of the whole.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this structure as a member.

An application can receive file-system events by implementing the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)