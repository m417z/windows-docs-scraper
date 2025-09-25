# VDS_ASYNC_OUTPUT_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of operations that objects can process.

## Constants

### `VDS_ASYNCOUT_UNKNOWN:0`

The value is reserved.

### `VDS_ASYNCOUT_CREATEVOLUME:1`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the newly
created [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object). For operation details, see the
[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume) method.

### `VDS_ASYNCOUT_EXTENDVOLUME:2`

The operation expands the size of the current volume by adding disk extents to each member of each plex.
For operation details, see the
[IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend) method.

### `VDS_ASYNCOUT_SHRINKVOLUME:3`

The operation reduces the size of the volume and all plexes and returns the released extents to free
space. For operation details, see the
[IVdsVolume::Shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-shrink) method.

### `VDS_ASYNCOUT_ADDVOLUMEPLEX:4`

The operation adds a volume as a plex to the current volume. For operation details, see the
[IVdsVolume::AddPlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-addplex) method.

### `VDS_ASYNCOUT_BREAKVOLUMEPLEX:5`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the
hidden [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object). For operation details, see the
[IVdsVolume::BreakPlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-breakplex) method.

### `VDS_ASYNCOUT_REMOVEVOLUMEPLEX:6`

The operation removes one or more specified plexes from the current volume, releasing the extents. For
operation details, see the
[IVdsVolume::RemovePlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-removeplex) method.

### `VDS_ASYNCOUT_REPAIRVOLUMEPLEX:7`

The operation repairs a fault-tolerant volume plex by moving bad members to good disks. For operation
details, see the
[IVdsVolumePlex::Repair](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-repair) method.

### `VDS_ASYNCOUT_RECOVERPACK:8`

The operation returns a failing or failed pack to a healthy state, if possible. For operation details, see
the [IVdsPack::Recover](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-recover) method.

### `VDS_ASYNCOUT_REPLACEDISK:9`

This value is reserved for future use.

### `VDS_ASYNCOUT_CREATEPARTITION:10`

The operation creates a new partition on a basic disk. For operation details, see the
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition)
method.

### `VDS_ASYNCOUT_CLEAN:11`

[IVdsAdvancedDisk::Clean](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-clean)

### `VDS_ASYNCOUT_CREATELUN:50`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the newly
created [LUN object](https://learn.microsoft.com/windows/desktop/VDS/lun-object). For operation details, see the
[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method.

### `VDS_ASYNCOUT_ADDLUNPLEX:52`

The operation adds a LUN to the target LUN as a new plex. For operation details, see the
[IVdsLun::AddPlex](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-addplex) method.

### `VDS_ASYNCOUT_REMOVELUNPLEX:53`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the
removed [LUN object](https://learn.microsoft.com/windows/desktop/VDS/lun-object). For operation details, see the
[IVdsLun::RemovePlex](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-removeplex) method.

### `VDS_ASYNCOUT_EXTENDLUN:54`

The operation extends a LUN by a specified number of bytes. For operation details, see the
[IVdsLun::Extend](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-extend) method.

### `VDS_ASYNCOUT_SHRINKLUN:55`

The operation shrinks a LUN by a specified number of bytes. For operation details, see the
[IVdsLun::Shrink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-shrink) method.

### `VDS_ASYNCOUT_RECOVERLUN:56`

The operation starts a recovery operation on a LUN. For operation details, see the
[IVdsLun::Recover](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-recover) method.

### `VDS_ASYNCOUT_LOGINTOTARGET:60`

The operation logs in to a target. For operation details, see the
[IVdsIscsiInitiatorAdapter::LoginToTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-logintotarget)
method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_LOGOUTFROMTARGET:61`

The operation logs out from a target. For operation details, see the
[IVdsIscsiInitiatorAdapter::LogoutFromTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-logoutfromtarget)
method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_CREATETARGET:62`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer
for the newly created target object. For operation details, see the
[IVdsSubSystemIscsi::CreateTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystemiscsi-createtarget) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_CREATEPORTALGROUP:63`

The operation returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer
for the newly created portal group object. For operation details, see the
[IVdsIscsiTarget::CreatePortalGroup](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-createportalgroup) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_DELETETARGET:64`

The operation deletes a target. For operation details, see the
[IVdsIscsiTarget::Delete](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-delete) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_ADDPORTAL:65`

The operation adds a portal to a portal group. For operation details, see the
[IVdsIscsiPortalGroup::AddPortal](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportalgroup-addportal) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_REMOVEPORTAL:66`

The operation removes a portal from a portal group. For operation details, see the
[IVdsIscsiPortalGroup::RemovePortal](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportalgroup-removeportal) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_DELETEPORTALGROUP:67`

The operation deletes a portal group. For operation details, see the
[IVdsIscsiPortalGroup::Delete](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportalgroup-delete) method.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 R2.

### `VDS_ASYNCOUT_FORMAT:101`

The operation formats a volume. For operation details, see the
[IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) method.

### `VDS_ASYNCOUT_CREATE_VDISK:200`

The operation creates a virtual disk. For operation details, see the [IVdsVdProvider::CreateVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdprovider-createvdisk) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_ASYNCOUT_ATTACH_VDISK:201`

The operation attaches a virtual disk. For operation details, see the [IVdsOpenVDisk::Attach](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsopenvdisk-attach) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_ASYNCOUT_COMPACT_VDISK:202`

The operation compacts a virtual disk to reduce the physical size of the backing file. For operation details, see the [IVdsOpenVDisk::Compact](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsopenvdisk-compact) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_ASYNCOUT_MERGE_VDISK:203`

The operation merges a child virtual disk with its parents in the differencing chain. For operation details, see the [IVdsOpenVDisk::Merge](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsopenvdisk-merge) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDS_ASYNCOUT_EXPAND_VDISK:204`

The operation increases the size of a virtual disk to the maximum available on a fixed-size or expandable disk. For operation details, see the [IVdsOpenVDisk::Expand](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsopenvdisk-expand) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

## Remarks

The [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure includes a **VDS_ASYNC_OUTPUT_TYPE**
value as a member to indicate an operation type.

**Note** Additional constants might be added to the **VDS_ASYNC_OUTPUT_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ASYNC_OUTPUT_TYPE** enumeration constant.

## See also

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[IVdsIscsiInitiatorAdapter](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsiscsiinitiatoradapter)

[IVdsIscsiPortalGroup](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsiportalgroup)

[IVdsIscsiTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsitarget)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)

[IVdsPack](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdspack)

[IVdsSubSystem](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystem)

[IVdsSubSystemIscsi](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystemiscsi)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolumePlex](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeplex)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)