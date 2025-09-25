# NTMS_COMPUTERINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_COMPUTERINFORMATION** structure defines the properties specific to the RSM server.

## Members

### `dwLibRequestPurgeTime`

Number of seconds completed library requests are maintained in the work queue.

### `dwOpRequestPurgeTime`

Number of seconds that completed operator requests are maintained in the operator request queue.

### `dwLibRequestFlags`

Library request options.

| Value | Meaning |
| --- | --- |
| **NTMS_LIBREQFLAGS_NOAUTOPURGE** | Library requests are not purged from the work queue. Set to **NULL** by default. |
| **NTMS_LIBREQFLAGS_NOFAILEDPURGE** | Failed work items are not purged from the work queue. Set to **NULL** by default. |

### `dwOpRequestFlags`

Operator request options.

| Value | Meaning |
| --- | --- |
| **NTMS_OPREQFLAGS_NOAUTOPURGE** | Operator requests are not purged from the work queue. Set to **NULL** by default. |
| **NTMS_OPREQFLAGS_NOFAILEDPURGE** | Operator requests are not purged from the queue. Set to **NULL** by default. |
| **NTMS_OPREQFLAGS_NOALERTS** | The alert pop-up for operator requests is disabled. |
| **NTMS_OPREQFLAGS_NOTRAYICON** | The taskbar icon for operator requests is disabled. |

### `dwMediaPoolPolicy`

Media pool policies.

| Value | Meaning |
| --- | --- |
| **NTMS_POOLPOLICY_PURGEOFFLINESCRATCH** | Any Free media ejected are automatically deleted. Set to **NULL** by default. |
| **NTMS_POOLPOLICY_KEEPOFFLINEIMPORT** | Any Import media ejected is not deleted automatically. Set to **NULL** by default. |

## Remarks

The
**NTMS_COMPUTERINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)