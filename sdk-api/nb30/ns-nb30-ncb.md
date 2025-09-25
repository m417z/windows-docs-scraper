# NCB structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **NCB** structure represents a network control block. It contains information about the command to perform, an optional post routine, an optional event handle, and a pointer to a buffer that is used for messages or other data. A pointer to this structure is passed to the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function.

## Members

### `ncb_command`

Specifies the command code and a flag that indicates whether the **NCB** structure is processed asynchronously. The most significant bit contains the flag. If the ASYNCH constant is combined with a command code (by using the OR operator), the **NCB** structure is processed asynchronously. The following command codes are supported.

| Code | Meaning |
| --- | --- |
| NCBACTION | **Windows Server 2003, Windows XP, Windows 2000, and Windows NT:** Enables extensions to the transport interface. NCBACTION is mapped to **TdiAction**. When this code is specified, the **ncb_buffer** member points to a buffer to be filled with an [ACTION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-action_header) structure, which is optionally followed by data. NCBACTION commands cannot be canceled by using NCBCANCEL. NCBACTION is not a standard NetBIOS 3.0 command. |
| NCBADDGRNAME | Adds a group name to the local name table. This name cannot be used by another process on the network as a unique name, but it can be added by anyone as a group name. |
| NCBADDNAME | Adds a unique name to the local name table. The TDI driver ensures that the name is unique across the network. |
| NCBASTAT | Retrieves the status of either a local or remote adapter. When this code is specified, the **ncb_buffer** member points to a buffer to be filled with an [ADAPTER_STATUS](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-adapter_status) structure, followed by an array of [NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-name_buffer) structures. |
| NCBCALL | Opens a session with another name. |
| NCBCANCEL | Cancels a previous pending command. |
| NCBCHAINSEND | Sends the contents of two data buffers to the specified session partner. |
| NCBCHAINSENDNA | Sends the contents of two data buffers to the specified session partner and does not wait for acknowledgment. |
| NCBDELNAME | Deletes a name from the local name table. |
| NCBDGRECV | Receives a datagram from any name. |
| NCBDGRECVBC | Receives a broadcast datagram from any name. |
| NCBDGSEND | Sends datagram to a specified name. |
| NCBDGSENDBC | Sends a broadcast datagram to every host on the local area network (LAN). |
| NCBENUM | **Windows Server 2003, Windows XP, Windows 2000, and Windows NT:** Enumerates LAN adapter (LANA) numbers. When this code is specified, the ncb_buffer member points to a buffer to be filled with a LANA_ENUM structure. NCBENUM is not a standard NetBIOS 3.0 command. |
| NCBFINDNAME | Determines the location of a name on the network. When this code is specified, the **ncb_buffer** member points to a buffer to be filled with a [FIND_NAME_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_header) structure followed by one or more [FIND_NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_buffer) structures. |
| NCBHANGUP | Closes a specified session. |
| NCBLANSTALERT | **Windows Server 2003, Windows XP, Windows 2000, and Windows NT:** Notifies the user of LAN failures that last for more than one minute. |
| NCBLISTEN | Enables a session to be opened with another name (local or remote). |
| NCBRECV | Receives data from the specified session partner. |
| NCBRECVANY | Receives data from any session corresponding to a specified name. |
| NCBRESET | Resets a LAN adapter. An adapter must be reset before it can accept any other NCB command that specifies the same number in the **ncb_lana_num** member.<br><br>Use the following values to specify how resources are to be freed:<br><br>* If **ncb_lsn** is not 0x00, all resources associated with **ncb_lana_num** are to be freed.<br>* If **ncb_lsn** is 0x00, all resources associated with **ncb_lana_num** are to be freed, and new resources are to be allocated. The **ncb_callname**[0] byte specifies the maximum number of sessions, and the **ncb_callname**[2] byte specifies the maximum number of names. A nonzero value for the **ncb_callname**[3] byte requests that the application use **NAME_NUMBER_1**. |
| NCBSEND | Sends data to the specified session partner. |
| NCBSENDNA | Sends data to specified session partner and does not wait for acknowledgment. |
| NCBSSTAT | Retrieves the status of the session. When this value is specified, the **ncb_buffer** member points to a buffer to be filled with a [SESSION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_header) structure, followed by one or more [SESSION_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_buffer) structures. |
| NCBTRACE | Activates or deactivates NCB tracing. <br><br>This command is not supported. |
| NCBUNLINK | Unlinks the adapter.<br><br>This command is provided for compatibility with earlier versions of NetBIOS. It has no effect in Windows. |

### `ncb_retcode`

Specifies the return code. This value is set to NRC_PENDING while an asynchronous operation is in progress. The system returns one of the following values:

| Value | Meaning |
| --- | --- |
| NRC_GOODRET | The operation succeeded. |
| NRC_BUFLEN | An illegal buffer length was supplied. |
| NRC_ILLCMD | An illegal command was supplied. |
| NRC_CMDTMO | The command was timed out. |
| NRC_INCOMP | The message was incomplete. The application is to issue another command. |
| NRC_BADDR | The buffer address was illegal. |
| NRC_SNUMOUT | The session number was out of range. |
| NRC_NORES | No resource was available. |
| NRC_SCLOSED | The session was closed. |
| NRC_CMDCAN | The command was canceled. |
| NRC_DUPNAME | A duplicate name existed in the local name table. |
| NRC_NAMTFUL | The name table was full. |
| NRC_ACTSES | The command finished; the name has active sessions and is no longer registered. |
| NRC_LOCTFUL | The local session table was full. |
| NRC_REMTFUL | The remote session table was full. The request to open a session was rejected. |
| NRC_ILLNN | An illegal name number was specified. |
| NRC_NOCALL | The system did not find the name that was called. |
| NRC_NOWILD | Wildcards are not permitted in the **ncb_name** member. |
| NRC_INUSE | The name was already in use on the remote adapter. |
| NRC_NAMERR | The name was deleted. |
| NRC_SABORT | The session ended abnormally. |
| NRC_NAMCONF | A name conflict was detected. |
| NRC_IFBUSY | The interface was busy. |
| NRC_TOOMANY | Too many commands were outstanding; the application can retry the command later. |
| NRC_BRIDGE | The **ncb_lana_num** member did not specify a valid network number. |
| NRC_CANOCCR | The command finished while a cancel operation was occurring. |
| NRC_CANCEL | The NCBCANCEL command was not valid; the command was not canceled. |
| NRC_DUPENV | The name was defined by another local process. |
| NRC_ENVNOTDEF | The environment was not defined. A reset command must be issued. |
| NRC_OSRESNOTAV | Operating system resources were exhausted. The application can retry the command later. |
| NRC_MAXAPPS | The maximum number of applications was exceeded. |
| NRC_NOSAPS | No service access points (SAPs) were available for NetBIOS. |
| NRC_NORESOURCES | The requested resources were not available. |
| NRC_INVADDRESS | The NCB address was not valid. |
| NRC_INVDDID | The NCB DDID was invalid.<br><br>This return code is not part of the IBM NetBIOS 3.0 specification and is not returned in the **NCB** structure. Instead, it is returned by the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function. |
| NRC_LOCKFAIL | The attempt to lock the user area failed. |
| NRC_OPENERR | An error occurred during an open operation being performed by the device driver. This error code is not part of the NetBIOS 3.0 specification. |
| NRC_SYSTEM | A system error occurred. |
| NRC_PENDING | An asynchronous operation is not yet finished. |

### `ncb_lsn`

Identifies the local session number. This number uniquely identifies a session within an environment. This number is returned by the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function after a successful NCBCALL command.

### `ncb_num`

Specifies the number for the local network name. This number is returned by [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) after a successful **NCBADDNAME** or **NCBADDGRNAME** command. This number, not the name, must be used with all datagram commands and for **NCBRECVANY** commands.

The number for **NAME_NUMBER_1** is always 0x01. The [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function assigns values in the range 0x02 to 0xFE for the remaining names.

### `ncb_buffer`

Pointer to the message buffer. The buffer must have write access. Its uses are as follows:

| Command | Purpose |
| --- | --- |
| NCBSEND | Contains the message to be sent. |
| NCBRECV | Receives the message. |
| NCBSSTAT | Receives the requested status information. |

### `ncb_length`

Specifies the size, in bytes, of the message buffer. For receive commands, this member is set by the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function to indicate the number of bytes received.

If the buffer length is incorrect, the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function returns the **NRC_BUFLEN** error code.

### `ncb_callname`

Specifies the name of the remote application. Trailing-space characters should be supplied to make the length of the string equal to **NCBNAMSZ**.

### `ncb_name`

Specifies the name by which the application is known. Trailing-space characters should be supplied to make the length of the string equal to **NCBNAMSZ**.

### `ncb_rto`

Specifies the time-out period for receive operations, in 500-millisecond units, for the session. A value of zero implies no time-out. Specify with the **NCBCALL** or **NCBLISTEN** command. Affects subsequent **NCBRECV** commands.

### `ncb_sto`

Specifies the time-out period for send operations, in 500-millisecond units, for the session. A value of zero implies no time-out. Specify with the **NCBCALL** or **NCBLISTEN** command. Affects subsequent **NCBSEND** and **NCBCHAINSEND** commands.

### `ncb_post`

Specifies the address of the post routine to call when the asynchronous command is completed. The post routine is defined as:

 NCB_POST PostRoutine( PNCB *pncb* );

where the *pncb* parameter is a pointer to the completed **NCB** structure.

### `ncb_lana_num`

Specifies the LAN adapter number. This zero-based number corresponds to a particular transport provider using a particular LAN adapter board.

### `ncb_cmd_cplt`

Specifies the command complete flag. This value is the same as the **ncb_retcode** member.

### `ncb_reserve`

Reserved; must be zero.

The length, X, of the **ncb_reserve** array is dependent upon the system architecture. For 64-bit systems, the array contains 18 elements. Otherwise, the array contains 10 elements.

### `ncb_event`

Specifies a handle to an event object that is set to the nonsignaled state when an asynchronous command is accepted, and it is set to the signaled state when the asynchronous command is completed. The event is signaled if the [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) function returns a nonzero value. Only manual reset events should be used for synchronization. A specified event should not be associated with more than one active asynchronous command.

The **ncb_event** member must be zero if the **ncb_command** member does not have the **ASYNCH** flag set or if **ncb_post** is nonzero. Otherwise, [Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios) returns the **NRC_ILLCMD** error code.

## Remarks

Using **ncb_event** to issue asynchronous requests requires fewer system resources than using **ncb_post**. In addition, when **ncb_event** is nonzero, the pending request is canceled if the thread terminates before the request is processed. This is not true for asynchronous requests sent using **ncb_post**.

## See also

[ACTION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-action_header)

[ADAPTER_STATUS](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-adapter_status)

[FIND_NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_buffer)

[FIND_NAME_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-find_name_header)

[LANA_ENUM](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-lana_enum)

[NAME_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-name_buffer)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/api/nb30/nf-nb30-netbios)

[SESSION_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_buffer)

[SESSION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_header)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)