# SHARE_INFO_1005 structure

## Description

Contains information about the shared resource.

## Members

### `shi1005_flags`

A bitmask of flags that specify information about the shared resource.

| Value | Meaning |
| --- | --- |
| ****SHI1005_FLAGS_DFS****<br><br>0x0001 | The specified share is present in a Dfs tree structure. This flag cannot be set with [NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo). |
| ****SHI1005_FLAGS_DFS_ROOT****<br><br>0x0002 | The specified share is the root volume in a Dfs tree structure. This flag cannot be set with [NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo). |
| ****SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS****<br><br>0x0100 | The specified share disallows exclusive file opens, where reads to an open file are disallowed. |
| ****SHI1005_FLAGS_FORCE_SHARED_DELETE****<br><br>0x0200 | Shared files in the specified share can be forcibly deleted. |
| ****SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING****<br><br>0x0400 | Clients are allowed to cache the namespace of the specified share. |
| ****SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM****<br><br>0x0800 | The server will filter directory entries based on the access permissions that the user on the client computer has for the server on which the files reside. Only files for which the user has read access and directories for which the user has FILE_LIST_DIRECTORY access will be returned. If the user has SeBackupPrivilege, all available information will be returned.<br><br>For more information about file and directory access, see [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).<br><br>For more information about SeBackupPrivilege, see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants).<br><br>**Note** This flag is supported only on servers running Windows Server 2003 with SP1 or later. |
| **SHI1005_FLAGS_FORCE_LEVELII_OPLOCK**<br><br>0x1000 | Prevents exclusive caching modes that can cause delays for highly shared read-only data. <br><br>**Note** This flag is supported only on servers running Windows Server 2008 R2 or later. |
| **SHI1005_FLAGS_ENABLE_HASH**<br><br>0x2000 | Enables server-side functionality needed for peer caching support. Clients on high-latency or low-bandwidth connections can use alternate methods to retrieve data from peers if available, instead of sending requests to the server. This is only supported on shares configured for manual caching (CSC_CACHE_MANUAL_REINT).<br><br>**Note** This flag is supported only on servers running Windows Server 2008 R2 or later. |
| **SHI1005_FLAGS_ENABLE_CA**<br><br>0X4000 | Enables Continuous Availability on a cluster share. Handles that are opened against a continuously available share can survive network failures as well as cluster node failures.<br><br>**Note** This flag can only be set on a scoped share on a server that meets the following conditions:<br><br>* It is running Windows Server 2012 or later.<br>* It is in a cluster configuration.<br>* It has the "Services for Continuously Available shares" role service installed.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008 and Windows Server 2003:** This flag is not supported. |

The CSC_MASK and CSC_MASK_EXT mask values can be used to apply flags that are specific to client-side caching (CSC).

| Value | Meaning |
| --- | --- |
| ****CSC_MASK****<br><br>0x0030 | Provides a mask for the following CSC states.<br><br>**CSC_CACHE_MANUAL_REINT** 0x0000<br><br>Automatic file-by-file reintegration is not allowed.<br><br>**CSC_CACHE_AUTO_REINT** 0x0010<br><br>File-by-file reintegration is allowed.<br><br>**CSC_CACHE_VDO** 0x0020<br><br>File opens do not need to be flowed.<br><br>**CSC_CACHE_NONE** 0x0030<br><br>CSC is disabled for this share. |
| ****CSC_MASK_EXT****<br><br>0x2030 | Provides a mask for the following CSC states and options.<br><br>**CSC_CACHE_MANUAL_REINT** 0x0000<br><br>Automatic file-by-file reintegration is not allowed.<br><br>**CSC_CACHE_AUTO_REINT** 0x0010<br><br>File-by-file reintegration is allowed.<br><br>**CSC_CACHE_VDO** 0x0020<br><br>File opens do not need to be flowed.<br><br>**CSC_CACHE_NONE** 0x0030<br><br>CSC is disabled for this share.<br><br>**SHI1005_FLAGS_ENABLE_HASH** 0x2000<br><br>Enables server-side functionality needed for peer caching support. |

## Remarks

This structure can be retrieved by calling the
[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function. It can be set by calling the [NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function.

## See also

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)