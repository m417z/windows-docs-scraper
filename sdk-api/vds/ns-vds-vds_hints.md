# VDS_HINTS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the automagic hints for a
LUN or LUN plex.

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
| **VDS_HINT_ISYANKABLE**<br><br>0x0000000000000100L | The provider configures LUN so that the drives that contribute to it can be physically removed with minimal system disruption. This is normally accomplished by ensuring that the LUN occupies as few drives as possible. |

### `ullExpectedMaximumSize`

The maximum size to which the LUN is expected to grow, in bytes. The value can be equal to, greater than, or
less than the value specified in *ullSizeInBytes* when the
[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method is called.
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

### `bFastCrashRecoveryRequired`

If this member is TRUE, the recovery time is limited. Set the **VDS_HINT_FASTCRASHRECOVERYREQUIRED**
flag in the **ullHintMask** member to indicate interest in this member.

### `bMostlyReads`

To optimize for a mostly-reads usage pattern (for example, through mirroring rather than parity striping), set
this member to TRUE. Otherwise, set it to **FALSE**. Set the **VDS_HINT_MOSTLYREADS** flag in
the **ullHintMask** member to indicate interest in this member.

### `bOptimizeForSequentialReads`

To optimize for a sequential-reads usage pattern, set this member to **TRUE**. Otherwise, set it to **FALSE**. Setting the
**bOptimizeForSequentialReads** and
**bOptimizeForSequentialWrites** members both to **FALSE** optimizes for random I/O. Set the
**VDS_HINT_OPTIMIZEFORSEQUENTIALREADS** flag in
the **ullHintMask** member to indicate interest in this member.

### `bOptimizeForSequentialWrites`

To optimize for a sequential-writes usage pattern, set to this member to **TRUE**. Otherwise, set it to **FALSE**. Setting the
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

If this member is set to **TRUE**, the provider verifies the writes to the LUN by readback. If it is set to **FALSE**, the provider does not verify writes.
Set the **VDS_HINT_READBACKVERIFYENABLED** flag in
the **ullHintMask** member to indicate interest in this member.

### `bWriteThroughCachingEnabled`

If this member is **TRUE**, the provider enables write-through caching on the LUN. If it is **FALSE**, the provider does not enable
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

### `sRebuildPriority`

The rebuild priority for the LUN. The value can range from 0 (lowest priority) through 15 (highest priority).

## Remarks

The [IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method passes
this structure as a parameter to provide hints for creating a LUN. It is passed as a parameter in the
**ApplyHints** method on both the
[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun) and
[IVdsLunPlex](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslunplex) interfaces to apply a new set of hints to a
LUN or LUN plex, respectively. Further, it is returned by the **QueryHints** method on both
the **IVdsLun** and
**IVdsLunPlex** interfaces to report hints currently applied
to a LUN or LUN plex, respectively.

Hints are not directives to implementers. While implementers are in general expected to do their best to take hints into consideration,
they are not obligated to follow them. Implementers can opt for alternatives when unable to follow specified hints for
technical reasons or when following them can result in a poor configuration.

## See also

[IVdsLun::ApplyHints](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-applyhints)

[IVdsLun::QueryHints](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-queryhints)

[IVdsLunPlex::ApplyHints](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-applyhints)

[IVdsLunPlex::QueryHints](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryhints)

[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)