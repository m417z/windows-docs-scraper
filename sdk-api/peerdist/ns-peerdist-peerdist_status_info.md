# PEERDIST_STATUS_INFO structure

## Description

The **PEERDIST_STATUS_INFO** structure contains information about the current status and capabilities of the BranchCache service on the local computer.

## Members

### `cbSize`

Size, in bytes, of the **PEERDIST_STATUS_INFO** structure.

### `status`

Specifies the current status of the BranchCache service. This member should be one of following values defined in the [PEERDIST_STATUS](https://learn.microsoft.com/windows/desktop/api/peerdist/ne-peerdist-peerdist_status) enumeration.

### `dwMinVer`

Specifies the minimum version of the content information format supported by the BranchCache service on the local machine. This member must be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_1**<br><br>1 | Windows 7 compatible content information format. |
| **PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_2**<br><br>2 | Windows 8 content information format. |

### `dwMaxVer`

 Specifies the maximum version of the content information format supported by the BranchCache service on the local machine. This member must be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_1**<br><br>1 | Windows 7 compatible content information format. |
| **PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_2**<br><br>2 | Windows 8 content information format. |

## See also

[PEERDIST_STATUS](https://learn.microsoft.com/windows/desktop/api/peerdist/ne-peerdist-peerdist_status)

[PeerDistGetStatusEx](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistgetstatusex)