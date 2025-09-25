# FAX_ACCESS_RIGHTS_ENUM_2 enumeration

## Description

Defines access rights on the fax server.

## Constants

### `far2SUBMIT_LOW:0x1`

The user can submit low-priority fax jobs. Users can view and manage their jobs in the fax server's queue and their messages in the outgoing fax archive.

### `far2SUBMIT_NORMAL:0x2`

The user can submit normal-priority and low-priority fax jobs. Users can view and manage their jobs in the fax server queue and their messages in the outgoing fax archive.

### `far2SUBMIT_HIGH:0x4`

The user can submit low-priority, normal-priority, and high-priority fax jobs. Users can view and manage their jobs in the fax server queue and their messages in the outgoing fax archive.

### `far2QUERY_OUT_JOBS:0x8`

The user can query outgoing jobs belonging to all accounts, including other user's accounts.

### `far2MANAGE_OUT_JOBS:0x10`

The user can manage outgoing jobs belonging to all accounts, including other user's accounts.

### `far2QUERY_CONFIG:0x20`

The user can view and query the fax server's configuration data.

### `far2MANAGE_CONFIG:0x40`

The user can view and set the fax server's configuration data.

### `far2QUERY_ARCHIVES:0x80`

The user can query archived messages belonging to all accounts, including other user's accounts.

### `far2MANAGE_ARCHIVES:0x100`

The user can manage archived messages belonging to all accounts, including other user's accounts.

### `far2MANAGE_RECEIVE_FOLDER:0x200`

The user can manage all the messages in the server's receive folder. This includes the right to [reassign](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) and delete messages.

## See also

[IFaxSecurity2::GrantedRights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-grantedrights-vb)