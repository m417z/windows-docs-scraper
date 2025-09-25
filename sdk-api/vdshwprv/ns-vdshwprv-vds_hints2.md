# VDS_HINTS2 structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Contains the automagic hints for a LUN in a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Members

### `ullHintMask`

The LUN hint mask. Each of the **BOOL** members of this structure has a corresponding hint flag that can be set in the mask. If the
hint flag is set, the corresponding hint is considered. If the hint flag is not set, the hint is ignored. The
hint flags are described in the following table.

| Value | Meaning |
| --- | --- |
| **VDS_HINT_FASTCRASHRECOVERYREQUIRED**<br><br>0x0000000000000001L | The provider limits the time that is required for recovery. To support fast recovery, the provider uses a change log that enables the provider to recover the LUN without comparing the entire contents of the LUN. |
| **VDS_HINT_MOSTLYREADS**<br><br>0x0000000000000002L | The provider optimizes the LUN for a read-mostly usage pattern, typically by using mirroring rather than parity striping. |
| **VDS_HINT_OPTIMIZEFORSEQUENTIALREADS**<br><br>0x0000000000000004L | The provider optimizes the LUN for a sequential-read usage pattern. If this flag is not set and VDS_HINT_OPTIMIZEFORSEQUENTIALWRITES is also not set, the LUN is optimized for random I/O. |
| **VDS_HINT_OPTIMIZEFORSEQUENTIALWRITES**<br><br>0x0000000000000008L | The provider optimizes the LUN for a sequential-write usage pattern. If this flag is not set and VDS_HINT_OPTIMIZEFORSEQUENTIALREADS is also not set, the LUN is optimized for random I/O. |
| **VDS_HINT_READBACKVERIFYENABLED**<br><br>0x0000000000000010L | The provider verifies the writes to the LUN by using readback. |
| **VDS_HINT_REMAPENABLED**<br><br>0x0000000000000020L | The mapping of LUN extents to drive extents is created and updated automatically by the provider. If this flag is not set, the mapping remains fixed after configuration, except when proactive actions are taken to avoid drive failures. |
| **VDS_HINT_WRITETHROUGHCACHINGENABLED**<br><br>0x0000000000000040L | The provider enables the write-through caching policy on the LUN. |
| **VDS_HINT_HARDWARECHECKSUMENABLED**<br><br>0x0000000000000080L | The provider enables a hardware checksum on the LUN. |
| **VDS_HINT_ISYANKABLE**<br><br>0x0000000000000100L | The provider configures the LUN so that the drives that contribute to it can be physically removed with minimal system disruption. This is normally accomplished by ensuring that the LUN occupies as few drives as possible. |
| **VDS_HINT_ALLOCATEHOTSPARE**<br><br>0x0000000000000200L | The provider allocates a hot spare for the LUN. For more information, see [Hot Sparing](https://learn.microsoft.com/windows/desktop/VDS/hot-sparing), [VDS_DRIVE_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_flag), and [VDS_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_flag). |
| **VDS_HINT_BUSTYPE**<br><br>0x0000000000000400L | The provider uses the specified bus type on the LUN. For more information, see [VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type). |
| **VDS_HINT_USEMIRROREDCACHE**<br><br>0x0000000000000800L | The provider uses a mirrored cache on the LUN. See the **VDS_SF_SUPPORTS_MIRRORED_CACHE** value of the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration. |
| **VDS_HINT_READCACHINGENABLED**<br><br>0x0000000000001000L | The provider enables read caching on the LUN. See the **VDS_LF_READ_CACHE_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **VDS_SF_READ_CACHING_CAPABLE** value of the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration. |
| **VDS_HINT_WRITECACHINGENABLED**<br><br>0x0000000000002000L | The provider enables write caching on the LUN. See the **VDS_LF_WRITE_CACHE_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **VDS_SF_WRITE_CACHING_CAPABLE** value of the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration. |
| **VDS_HINT_MEDIASCANENABLED**<br><br>0x0000000000004000L | The provider enables media scanning on the LUN. See the **VDS_LF_MEDIA_SCAN_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **VDS_SF_MEDIA_SCAN_CAPABLE** value of the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration. |
| **VDS_HINT_CONSISTENCYCHECKENABLED**<br><br>0x0000000000008000L | The provider enables consistency checking on the LUN. See the **VDS_LF_CONSISTENCY_CHECK_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **VDS_SF_CONSISTENCY_CHECK_CAPABLE** value of the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration. |

### `ullExpectedMaximumSize`

The maximum size to which the LUN is expected to grow, in bytes. The value can be equal to, greater than, or
less than the value specified in the *ullSizeInBytes* parameter when the
[IVdsHwProviderStoragePools::CreateLunInStoragePool](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwproviderstoragepools-createluninstoragepool) method is called.
Some providers use this value to reserve space for the LUN. Providers that are unable to reserve space
typically ignore this parameter.

### `ulOptimalReadSize`

The optimal read size for the LUN, in bytes. Zero indicates no optimal read size.

### `ulOptimalReadAlignment`

The optimal read alignment with respect to the first logical block of the LUN. Zero indicates no optimal read
alignment.

### `ulOptimalWriteSize`

The optimal write size for the LUN, in bytes. Zero indicates no optimal write size.

### `ulOptimalWriteAlignment`

The optimal write alignment with respect to the first logical block of the LUN. Zero indicates no optimal
write alignment.

### `ulMaximumDriveCount`

The maximum number of drives to contribute to the LUN. Zero indicates no maximum drive count. This value can be
used to limit the number of stripe interleaves in a stripe set.

### `ulStripeSize`

The mirror or parity stripe interleave size, in bytes. Zero leaves the stripe size unspecified.

### `ulReserved1`

This member is reserved for future use. Do not use.

### `ulReserved2`

This member is reserved for future use. Do not use.

### `ulReserved3`

This member is reserved for future use. Do not use.

### `bFastCrashRecoveryRequired`

If this member is **TRUE**, the recovery time is limited. Set the **VDS_HINT_FASTCRASHRECOVERYREQUIRED**
flag in the **ullHintMask** member to indicate interest in this member.

### `bMostlyReads`

To optimize for a mostly-reads usage pattern (for example, through mirroring rather than parity striping), set
this member to **TRUE**. Otherwise, set it to **FALSE**. Set the **VDS_HINT_MOSTLYREADS** flag in
the **ullHintMask** member to indicate interest in this member.

### `bOptimizeForSequentialReads`

To optimize for a sequential-reads usage pattern, set this member to **TRUE**. Otherwise, set it to **FALSE**. Setting the
**bOptimizeForSequentialReads** and
**bOptimizeForSequentialWrites** members both to **FALSE** optimizes for random I/O. Set the
**VDS_HINT_OPTIMIZEFORSEQUENTIALREADS** flag in
the **ullHintMask** member to indicate interest in this member.

### `bOptimizeForSequentialWrites`

To optimize for a sequential-writes usage pattern, set this member to **TRUE**. Otherwise, set it to **FALSE**. Setting the
**bOptimizeForSequentialReads** and
**bOptimizeForSequentialWrites** members both to **FALSE** optimizes for random I/O. Set the
**VDS_HINT_OPTIMIZEFORSEQUENTIALWRITES** flag in
the **ullHintMask** member to indicate interest in this member.

### `bRemapEnabled`

If this member is **TRUE**, the provider remaps LUN extents to drive extents automatically. If it is **FALSE**, the mapping of LUN extents
to drive extents remains fixed after LUN configuration unless extents are explicitly remapped to avoid
corrupted blocks. Set the **VDS_HINT_REMAPENABLED** flag in
the **ullHintMask** member to indicate interest in this member.

### `bReadBackVerifyEnabled`

If this member is **TRUE**, the provider verifies the writes to the LUN by readback. If it is **FALSE**, the provider does not verify writes.
Set the **VDS_HINT_READBACKVERIFYENABLED** flag in the
**ullHintMask** member to indicate interest in this member.

### `bWriteThroughCachingEnabled`

If this member is **TRUE**, the provider enables write-through caching on the LUN; if it is **FALSE**, the provider does not enable
write-through caching. Set the **VDS_HINT_WRITETHROUGHCACHINGENABLED** flag in
the **ullHintMask** member to indicate interest in this member.

### `bHardwareChecksumEnabled`

If this member is **TRUE**, the provider enables a checksum on the LUN. Set the
**VDS_HINT_HARDWARECHECKSUMENABLED** flag in
the **ullHintMask** member to indicate interest in this member.

### `bIsYankable`

If this member is **TRUE**, the drives that contribute to the LUN can be physically removed without significant disruption to the
system (this is typically true when the LUN is composed of extents from only a few drives). If it is **FALSE**, the LUN
cannot be removed without significant disruption to the system. Set the
**VDS_HINT_ISYANKABLE** flag in the **ullHintMask** member to indicate
interest in this member.

### `bAllocateHotSpare`

**TRUE** if the client wants to allocate a hot spare drive for this LUN, or **FALSE** otherwise. Set the
**VDS_HINT_ALLOCATEHOTSPARE** flag in the **ullHintMask** member to indicate
interest in this member.

### `bUseMirroredCache`

**TRUE** if the client wants this LUN to use a mirrored cache, or **FALSE** otherwise. Set the
**VDS_HINT_USEMIRROREDCACHE** flag in the **ullHintMask** member to indicate
interest in this member.

### `bReadCachingEnabled`

**TRUE** if the client wants the LUN to use read caching, or **FALSE** otherwise. Set the
**VDS_HINT_READCACHINGENABLED** flag in the **ullHintMask** member to indicate
interest in this member.

### `bWriteCachingEnabled`

**TRUE** if the client wants the LUN to use write caching, or **FALSE** otherwise. Set the
**VDS_HINT_WRITECACHINGENABLED** flag in the **ullHintMask** member to indicate
interest in this member.

### `bMediaScanEnabled`

**TRUE** if the client wants to enable media scanning for this LUN, or **FALSE** otherwise. Set the
**VDS_HINT_MEDIASCANENABLED** flag in the **ullHintMask** member to indicate
interest in this member.

### `bConsistencyCheckEnabled`

**TRUE** if the client wants to enable consistency checking for this LUN, or **FALSE** otherwise. Set the
**VDS_HINT_CONSISTENCYCHECKENABLED** flag in the **ullHintMask** member to indicate
interest in this member.

### `BusType`

A
[VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type) enumeration value that specifies the bus type for the LUN. Set the
**VDS_HINT_BUSTYPE** flag in the **ullHintMask** member to indicate
interest in this member.

### `bReserved1`

This member is reserved for future use. Do not use.

### `bReserved2`

This member is reserved for future use. Do not use.

### `bReserved3`

This member is reserved for future use. Do not use.

### `sRebuildPriority`

The rebuild priority for the LUN. The value can range from 0 (lowest priority) through 15 (highest priority).

## Remarks

The [IVdsHwProviderStoragePools::CreateLunInStoragePool](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwproviderstoragepools-createluninstoragepool) method passes
this structure as a parameter to provide hints for creating a LUN in a storage pool. It is passed as a parameter in the
[IVdsLun2::ApplyHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-applyhints2) method to apply a new set of hints to a
LUN. Further, it is returned by the [IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2) method to report hints currently applied
to a LUN or LUN plex, respectively.

Hints are not directives to implementers. While implementers are in general expected to do their best to take hints into consideration,
they are not obligated to follow them. Implementers can opt for alternatives when unable to follow specified hints for
technical reasons or when following them can result in a poor configuration.

## See also

[IVdsLun2::ApplyHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-applyhints2)

[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2)