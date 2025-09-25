# WKSTA_INFO_502 structure

## Description

The
**WKSTA_INFO_502** structure is obsolete. The structure contains information about a workstation environment.

## Members

### `wki502_char_wait`

Type: **DWORD**

The number of seconds the computer waits for a remote resource to become available.

### `wki502_collection_time`

Type: **DWORD**

The number of milliseconds the computer collects data before sending the data to a character device resource. The workstation waits the specified time or collects the number of characters specified by the **wki502_maximum_collection_count** member, whichever comes first.

### `wki502_maximum_collection_count`

Type: **DWORD**

The number of bytes of information the computer collects before sending the data to a character device resource. The workstation collects the specified number of bytes or waits the period of time specified by the **wki502_collection_time** member, whichever comes first.

### `wki502_keep_conn`

Type: **DWORD**

The number of seconds the server maintains an inactive connection to a server's resource.

### `wki502_max_cmds`

Type: **DWORD**

The number of simultaneous network device driver commands that can be sent to the network.

### `wki502_sess_timeout`

Type: **DWORD**

The number of seconds the server waits before disconnecting an inactive session.

### `wki502_siz_char_buf`

Type: **DWORD**

The maximum size, in bytes, of a character pipe buffer and device buffer.

### `wki502_max_threads`

Type: **DWORD**

The number of threads the computer can dedicate to the network.

### `wki502_lock_quota`

Type: **DWORD**

Reserved.

### `wki502_lock_increment`

Type: **DWORD**

Reserved.

### `wki502_lock_maximum`

Type: **DWORD**

Reserved.

### `wki502_pipe_increment`

Type: **DWORD**

Reserved.

### `wki502_pipe_maximum`

Type: **DWORD**

Reserved.

### `wki502_cache_file_timeout`

Type: **DWORD**

Reserved.

### `wki502_dormant_file_limit`

Type: **DWORD**

Reserved.

### `wki502_read_ahead_throughput`

Type: **DWORD**

Reserved.

### `wki502_num_mailslot_buffers`

Type: **DWORD**

Reserved.

### `wki502_num_srv_announce_buffers`

Type: **DWORD**

Reserved.

### `wki502_max_illegal_datagram_events`

Type: **DWORD**

Reserved.

### `wki502_illegal_datagram_event_reset_frequency`

Type: **DWORD**

Reserved.

### `wki502_log_election_packets`

Type: **BOOL**

Reserved.

### `wki502_use_opportunistic_locking`

Type: **BOOL**

Reserved.

### `wki502_use_unlock_behind`

Type: **BOOL**

Reserved.

### `wki502_use_close_behind`

Type: **BOOL**

Reserved.

### `wki502_buf_named_pipes`

Type: **BOOL**

Reserved.

### `wki502_use_lock_read_unlock`

Type: **BOOL**

Reserved.

### `wki502_utilize_nt_caching`

Type: **BOOL**

Reserved.

### `wki502_use_raw_read`

Type: **BOOL**

Reserved.

### `wki502_use_raw_write`

Type: **BOOL**

Reserved.

### `wki502_use_write_raw_data`

Type: **BOOL**

Reserved.

### `wki502_use_encryption`

Type: **BOOL**

Reserved.

### `wki502_buf_files_deny_write`

Type: **BOOL**

Reserved.

### `wki502_buf_read_only_files`

Type: **BOOL**

Reserved.

### `wki502_force_core_create_mode`

Type: **BOOL**

Reserved.

### `wki502_use_512_byte_max_transfer`

Type: **BOOL**

Reserved.

## See also

[NetWkstaGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstagetinfo)

[NetWkstaSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstasetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)