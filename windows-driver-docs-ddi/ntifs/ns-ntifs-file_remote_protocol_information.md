# FILE_REMOTE_PROTOCOL_INFORMATION structure

## Description

The **FILE_REMOTE_PROTOCOL_INFORMATION** structure contains file remote protocol information. This structure is returned from [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) when **FileRemoteProtocolInformation** is passed in as the **FileInformationClass** parameter.

## Members

### `StructureVersion`

Version of this structure. Set this member as follows.

| Value | Meaning |
|-------|---------|
| 1 | Communication is between computers running Windows 7 |
| 2 | Communication is between computers running Windows 8 |
| 3 | Communication is between computers running Windows 8.1 |
| 4 | Communication is between computers running Windows 10 or later |

### `StructureSize`

Size of this structure, in bytes. This member should be set to **sizeof**(FILE_REMOTE_PROTOCOL_INFORMATION).

### `Protocol`

One of the **WNNC_NET_*XXX*** remote protocol network types defined in *ntifs.h*.

### `ProtocolMajorVersion`

Major number of the remote protocol.

### `ProtocolMinorVersion`

Minor number of the remote protocol.

### `ProtocolRevision`

Revision of the remote protocol.

### `Reserved`

Should be set to zero. Do not use this member.

### `Flags`

Remote protocol information. This member can be set to zero or more of the following flags.

| Value | Meaning |
| ----- | ------- |
| REMOTE_PROTOCOL_FLAG_LOOPBACK | The remote protocol is using a loopback |
| REMOTE_PROTOCOL_FLAG_OFFLINE | The remote protocol is using an offline cache |
| REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE | The remote protocol is using a persistent handle. This flag is supported only if **StructureVersion** is 2 or higher. |
| REMOTE_PROTOCOL_INFO_FLAG_PRIVACY | The remote protocol is using privacy. This flag is supported only if **StructureVersion** is 2 or higher. |
| REMOTE_PROTOCOL_INFO_FLAG_INTEGRITY | The remote protocol is using integrity so the data is signed. This flag is supported only if **StructureVersion** is 2 or higher. |
| REMOTE_PROTOCOL_INFO_FLAG_MUTUAL_AUTH | The remote protocol is using mutual authentication using Kerberos. This flag is supported only if **StructureVersion** is 2 or higher. |

### `GenericReserved`

Protocol-generic information structure.

### `GenericReserved.Reserved`

Should be set to zero. Do not use this member.

### `ProtocolSpecificReserved`

### `ProtocolSpecificReserved.Reserved`

### `ProtocolSpecific`

### `ProtocolSpecific.Smb2`

### `ProtocolSpecific.Smb2.Server`

### `ProtocolSpecific.Smb2.Server.Capabilities`

### `ProtocolSpecific.Smb2.Share`

### `ProtocolSpecific.Smb2.Share.Capabilities`

### `ProtocolSpecific.Smb2.Share.ShareFlags`

### `ProtocolSpecific.Smb2.Share.CachingFlags`

### `ProtocolSpecific.Smb2.Share.ShareType`

### `ProtocolSpecific.Smb2.Share.Reserved0`

### `ProtocolSpecific.Smb2.Share.Reserved1`

### `ProtocolSpecific.Reserved`

## Remarks

## See also

[FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[FltQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)