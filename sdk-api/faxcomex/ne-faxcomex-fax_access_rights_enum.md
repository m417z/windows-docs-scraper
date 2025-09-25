# FAX_ACCESS_RIGHTS_ENUM enumeration

## Description

The **FAX_ACCESS_RIGHTS_ENUM** enumeration defines access rights to the fax server.

## Constants

### `farSUBMIT_LOW:0x1`

The user can submit low-priority fax jobs. Users can view and manage their jobs in the fax server's queue and their messages in the outgoing fax archive.

### `farSUBMIT_NORMAL:0x2`

The user can submit normal-priority and low-priority fax jobs. Users can view and manage their jobs in the fax server queue and their messages in the outgoing fax archive.

### `farSUBMIT_HIGH:0x4`

The user can submit low-priority, normal-priority, and high-priority fax jobs. Users can view and manage their jobs in the fax server queue and their messages in the outgoing fax archive.

### `farQUERY_JOBS:0x8`

The user can view all incoming and outgoing jobs in the fax server queue.

### `farMANAGE_JOBS:0x10`

The user can manage all incoming and outgoing jobs in the fax server queue.

### `farQUERY_CONFIG:0x20`

The user can view the fax server configuration data.

### `farMANAGE_CONFIG:0x40`

The user can set the fax server configuration data.

### `farQUERY_IN_ARCHIVE:0x80`

The user can view all fax messages in the incoming archive.

### `farMANAGE_IN_ARCHIVE:0x100`

The user can manage all fax messages in the incoming archive.

### `farQUERY_OUT_ARCHIVE:0x200`

The user can view all fax messages in the outgoing archive.

### `farMANAGE_OUT_ARCHIVE:0x400`

The user can manage all fax messages in the outgoing archive.

## See also

[IFaxSecurity::get_GrantedRights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-grantedrights-vb)