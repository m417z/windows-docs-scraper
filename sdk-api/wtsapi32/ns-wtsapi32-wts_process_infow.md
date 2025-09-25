# WTS_PROCESS_INFOW structure

## Description

Contains information about a process running on a Remote Desktop Session Host (RD Session Host) server.

## Members

### `SessionId`

Remote Desktop Services session identifier for the session associated with the process.

### `ProcessId`

Process identifier that uniquely identifies the process on the RD Session Host server.

### `pProcessName`

Pointer to a null-terminated string containing the name of the executable file associated with the process.

### `pUserSid`

Pointer to the user
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) in the process's primary access token. For more information about SIDs and access tokens, see
[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

## See also

[WTSEnumerateProcesses](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTS_PROCESS_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).