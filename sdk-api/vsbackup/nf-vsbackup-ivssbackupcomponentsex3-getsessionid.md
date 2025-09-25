# IVssBackupComponentsEx3::GetSessionId

## Description

Returns the requester's session identifier.

## Parameters

### `idSession` [out]

A pointer to a variable that receives the session identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The session identifier is an opaque value that uniquely identifies a backup or restore session. It is used to distinguish the current session among multiple parallel backup or restore sessions.

As a best practice, writers and requesters should include the session ID in all diagnostics messages used for event logging and tracing.

## See also

[CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid)

[IVssBackupComponentsEx3](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex3)