# USER_INFO_1020 structure

## Description

The
**USER_INFO_1020** structure contains the times during which a user can log on to the network. This information level is valid only when you call the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Members

### `usri1020_units_per_week`

Specifies a **DWORD** value that indicates the number of equal-length time units into which the week is divided. This value is required to compute the length of the bit string in the **usri1020_logon_hours** member.

This value must be UNITS_PER_WEEK for LAN Manager 2.0. Calls to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions ignore this member.

For service applications, the units must be one of the following values: SAM_DAYS_PER_WEEK, SAM_HOURS_PER_WEEK, or SAM_MINUTES_PER_WEEK.

### `usri1020_logon_hours`

Pointer to a 21-byte (168 bits) bit string that specifies the times during which the user can log on. The user is specified in the *username* parameter to the
**NetUserSetInfo** function.

Each bit in the string represents a unique hour in the week, in Greenwich Mean Time (GMT). The first bit (bit 0, word 0) is Sunday, 0:00 to 0:59; the second bit (bit 1, word 0) is Sunday, 1:00 to 1:59; and so on. Note that bit 0 in word 0 represents Sunday from 0:00 to 0:59 only if you are in the GMT time zone. In all other cases you must adjust the bits according to your time zone offset (for example, GMT minus 8 hours for Pacific Standard Time).

## See also

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)