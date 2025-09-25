# CVssWriterEx2::GetSessionId

## Description

Returns the writer's session identifier.

## Parameters

### `idSession` [out]

A pointer to a variable that receives the session identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The session identifier is an opaque value that uniquely identifies a backup or restore session. It is used to distinguish the current session among multiple parallel backup or restore sessions.

As a best practice, writers and requesters should include the session ID in all diagnostics messages used for event logging and tracing.

If a writer's event handler (such as [CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)) calls this method, it must do so in the same thread that called the event handler. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriterEx2](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex2)

[IVssBackupComponentsEx3::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex3-getsessionid)