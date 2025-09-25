# FILE_REMOTE_PROTOCOL_INFO structure

## Description

Contains file remote protocol information. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileRemoteProtocolInfo** is passed in the *FileInformationClass*
parameter.

## Members

### `StructureVersion`

Version of this structure. This member should be set to 2 if the communication is between
computers running Windows 8, Windows Server 2012, or later and 1 otherwise.

### `StructureSize`

Size of this structure. This member should be set to
`sizeof(FILE_REMOTE_PROTOCOL_INFO)`.

### `Protocol`

Remote protocol (**WNNC_NET_***) defined in Wnnc.h or
Ntifs.h.

#### WNNC_NET_MSNET (0x00010000)

#### WNNC_NET_SMB (0x00020000)

#### WNNC_NET_LANMAN (0x00020000)

#### WNNC_NET_NETWARE (0x00030000)

#### WNNC_NET_VINES (0x00040000)

#### WNNC_NET_10NET (0x00050000)

#### WNNC_NET_LOCUS (0x00060000)

#### WNNC_NET_SUN_PC_NFS (0x00070000)

#### WNNC_NET_LANSTEP (0x00080000)

#### WNNC_NET_9TILES (0x00090000)

#### WNNC_NET_LANTASTIC (0x000A0000)

#### WNNC_NET_AS400 (0x000B0000)

#### WNNC_NET_FTP_NFS (0x000C0000)

#### WNNC_NET_PATHWORKS (0x000D0000)

#### WNNC_NET_LIFENET (0x000E0000)

#### WNNC_NET_POWERLAN (0x000F0000)

#### WNNC_NET_BWNFS (0x00100000)

#### WNNC_NET_COGENT (0x00110000)

#### WNNC_NET_FARALLON (0x00120000)

#### WNNC_NET_APPLETALK (0x00130000)

#### WNNC_NET_INTERGRAPH (0x00140000)

#### WNNC_NET_SYMFONET (0x00150000)

#### WNNC_NET_CLEARCASE (0x00160000)

#### WNNC_NET_FRONTIER (0x00170000)

#### WNNC_NET_BMC (0x00180000)

#### WNNC_NET_DCE (0x00190000)

#### WNNC_NET_AVID (0x001A0000)

#### WNNC_NET_DOCUSPACE (0x001B0000)

#### WNNC_NET_MANGOSOFT (0x001C0000)

#### WNNC_NET_SERNET (0x001D0000)

#### WNNC_NET_RIVERFRONT1 (0x001E0000)

#### WNNC_NET_RIVERFRONT2 (0x001F0000)

#### WNNC_NET_DECORB (0x00200000)

#### WNNC_NET_PROTSTOR (0x00210000)

#### WNNC_NET_FJ_REDIR (0x00220000)

#### WNNC_NET_DISTINCT (0x00230000)

#### WNNC_NET_TWINS (0x00240000)

#### WNNC_NET_RDR2SAMPLE (0x00250000)

#### WNNC_NET_CSC (0x00260000)

#### WNNC_NET_3IN1 (0x00270000)

#### WNNC_NET_EXTENDNET (0x00290000)

#### WNNC_NET_STAC (0x002A0000)

#### WNNC_NET_FOXBAT (0x002B0000)

#### WNNC_NET_YAHOO (0x002C0000)

#### WNNC_NET_EXIFS (0x002D0000)

#### WNNC_NET_DAV (0x002E0000)

#### WNNC_NET_KNOWARE (0x002F0000)

#### WNNC_NET_OBJECT_DIRE (0x00300000)

#### WNNC_NET_MASFAX (0x00310000)

#### WNNC_NET_HOB_NFS (0x00320000)

#### WNNC_NET_SHIVA (0x00330000)

#### WNNC_NET_IBMAL (0x00340000)

#### WNNC_NET_LOCK (0x00350000)

#### WNNC_NET_TERMSRV (0x00360000)

#### WNNC_NET_SRT (0x00370000)

#### WNNC_NET_QUINCY (0x00380000)

#### WNNC_NET_OPENAFS (0x00390000)

#### WNNC_NET_AVID1 (0x003A0000)

#### WNNC_NET_DFS (0x003B0000)

#### WNNC_NET_KWNP (0x003C0000)

#### WNNC_NET_ZENWORKS (0x003D0000)

#### WNNC_NET_DRIVEONWEB (0x003E0000)

#### WNNC_NET_VMWARE (0x003F0000)

#### WNNC_NET_RSFX (0x00400000)

#### WNNC_NET_MFILES (0x00410000)

#### WNNC_NET_MS_NFS (0x00420000)

#### WNNC_NET_GOOGLE (0x00430000)

#### WNNC_NET_NDFS (0x00440000)

### `ProtocolMajorVersion`

Major version of the remote protocol.

### `ProtocolMinorVersion`

Minor version of the remote protocol.

### `ProtocolRevision`

Revision of the remote protocol.

### `Reserved`

Should be set to zero. Do not use this member.

### `Flags`

Remote protocol information. This member can be set to zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **REMOTE_PROTOCOL_FLAG_LOOPBACK**<br><br>0x1 | The remote protocol is using a loopback. |
| **REMOTE_PROTOCOL_FLAG_OFFLINE**<br><br>0x2 | The remote protocol is using an offline cache. |
| **REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE**<br><br>0x4 | The remote protocol is using a persistent handle.<br><br>**Windows 7 and Windows Server 2008 R2:** This flag is not supported before Windows 8 and Windows Server 2012. |
| **REMOTE_PROTOCOL_INFO_FLAG_PRIVACY**<br><br>0x8 | The remote protocol is using privacy. This is only supported if the **StructureVersion** member is 2 or higher.<br><br>**Windows 7 and Windows Server 2008 R2:** This flag is not supported before Windows 8 and Windows Server 2012. |
| **REMOTE_PROTOCOL_INFO_FLAG_INTEGRITY**<br><br>0x10 | The remote protocol is using integrity so the data is signed. This is only supported if the **StructureVersion** member is 2 or higher.<br><br>**Windows 7 and Windows Server 2008 R2:** This flag is not supported before Windows 8 and Windows Server 2012. |
| **REMOTE_PROTOCOL_INFO_FLAG_MUTUAL_AUTH**<br><br>0x20 | The remote protocol is using mutual authentication using Kerberos. This is only supported if the **StructureVersion** member is 2 or higher.<br><br>**Windows 7 and Windows Server 2008 R2:** This flag is not supported before Windows 8 and Windows Server 2012. |

### `GenericReserved`

Protocol-generic information structure.

### `GenericReserved.Reserved`

Should be set to zero. Do not use this member.

### `ProtocolSpecificReserved`

Protocol-specific information structure.

### `ProtocolSpecificReserved.Reserved`

Should be set to zero. Do not use this member.

### `ProtocolSpecific`

### `ProtocolSpecific.Smb2`

### `ProtocolSpecific.Smb2.Server`

### `ProtocolSpecific.Smb2.Server.Capabilities`

### `ProtocolSpecific.Smb2.Share`

### `ProtocolSpecific.Smb2.Share.Capabilities`

### `ProtocolSpecific.Smb2.Share.CachingFlags`

### `ProtocolSpecific.Reserved`

## Remarks

The **FILE_REMOTE_PROTOCOL_INFO**
structure is valid only for use with the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)