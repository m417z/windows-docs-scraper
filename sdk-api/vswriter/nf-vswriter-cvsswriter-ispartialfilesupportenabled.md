# CVssWriter::IsPartialFileSupportEnabled

## Description

The
**IsPartialFileSupportEnabled** method determines whether partial file support is enabled or disabled.

**IsPartialFileSupportEnabled** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **true** | The requester supports partial file backups and restores. |
| **false** | The requester supports only the backup and restore of entire files. |

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)