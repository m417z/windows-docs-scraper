# VDS_DRIVE_LETTER_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of drive-letter events.

## Members

### `ulEvent`

Determines the drive-letter event for which an application will be notified, as one of the following
values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_DRIVE_LETTER_FREE**<br><br>201 | The drive letter of an uninitialized disk is free. |
| **VDS_NF_DRIVE_LETTER_ASSIGN**<br><br>202 | The drive letter of an uninitialized disk is assigned. |

### `wcLetter`

The drive letter that triggered the event.

### `volumeId`

The GUID of the volume to which the drive letter is assigned. If the drive letter is freed, the volume
identifier is GUID_NULL.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive drive-letter events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)