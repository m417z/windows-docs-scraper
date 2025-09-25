# VDS_SAN_POLICY enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid disk SAN policy flags.

## Constants

### `VDS_SP_UNKNOWN:0`

The SAN policy is unknown.

### `VDS_SP_ONLINE:0x1`

All newly discovered disks are brought online and made read-write.

### `VDS_SP_OFFLINE_SHARED:0x2`

All newly discovered disks that do not reside on a shared bus are brought online and made read-write.

### `VDS_SP_OFFLINE:0x3`

All newly discovered disks remain offline and read-only.

### `VDS_SP_OFFLINE_INTERNAL:0x4`

### `VDS_SP_MAX:0x5`

## Remarks

The SAN policy determines whether a newly discovered disk is brought online or remains offline, and whether it is made read/write or remains read-only. When a disk is offline, the disk layout can be read, but no volume devices are surfaced through Plug and Play (PnP). This means that no file system can be mounted on the disk. When a disk is online, one or more volume devices are installed for the disk.

To query the current SAN policy, use the [IVdsServiceSAN::GetSANPolicy](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservicesan-getsanpolicy) method.

To set the SAN policy, use the [IVdsServiceSAN::SetSANPolicy](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservicesan-setsanpolicy) method.

This enumeration supersedes the **NoAutoMount** registry key, which can be found under the following registry path:

**HKEY_LOCAL_MACHINE**\**System**\**CurrentControlSet**\**Services**\**Mountmgr**\**NoAutoMount**

The value of this key is a REG_DWORD value that is set to 0x00000000 to enable the Windows automount feature or a nonzero value to disable it. If the automount feature is enabled, Windows automatically mounts the file system for a new basic volume when it is added to the system and then assigns a drive letter to the volume. In system area network configurations, disabling automount prevents Windows from automatically mounting or assigning drive letters to any new basic volumes that are added to the system.

On Windows Server 2016, the default SAN policy is **VDS_SP_OFFLINE_SHARED**. This applies to all editions and installation types, including Nano Server.

On Windows Server 2008 Enterprise and Windows Server 2008 Datacenter, the default SAN policy is **VDS_SP_OFFLINE_SHARED**. On all other Windows Server 2008 editions, the default SAN policy is **VDS_SP_ONLINE**.

For an upgrade from an earlier version of Windows, if the **NoAutoMount** registry key was set before the upgrade, the upgrade will clear this registry key and set the SAN policy to **VDS_SP_OFFLINE_SHARED**. (The **NoAutoMount** registry key is set by default on Windows Server 2008 Enterprise and Windows Server 2008 Datacenter.) If the **NoAutoMount** registry key was not set before the upgrade, the upgrade will set the SAN policy to **VDS_SP_ONLINE**. In addition, the upgrade checks each disk to determine whether the volumes on the disk are online or offline. If a disk is online before the upgrade and has one or more online volumes, the upgrade will bring that disk and all of its volumes online, regardless of the SAN policy or whether the disk resides on a shared bus. For example, suppose that an online disk with two offline volumes and one online volume resides on a shared bus, and the **NoAutoMount** registry key is set before the upgrade. After the upgrade, the SAN policy will be **VDS_SP_OFFLINE_SHARED**, the disk will be brought online, and all three volumes will be brought online.

For a clean installation of Windows, the SAN policy determines whether a disk is online or offline after Windows is installed.

**Note** Additional constants might be added to the **VDS_SAN_POLICY** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_SAN_POLICY** enumeration constant.

## See also

[IVdsServiceSAN::GetSANPolicy](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservicesan-getsanpolicy)

[IVdsServiceSAN::SetSANPolicy](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservicesan-setsanpolicy)