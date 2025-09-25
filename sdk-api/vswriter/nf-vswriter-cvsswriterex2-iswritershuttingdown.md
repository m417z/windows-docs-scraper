# CVssWriterEx2::IsWriterShuttingDown

## Description

Determines whether the writer is shutting down.

## Return value

Returns **true** if the writer is shutting down, or **false** otherwise.

## Remarks

The writer implementation should call this method periodically during long-running events where the writer is performing a large amount of processing or looping. If this method returns **true** during the event, the writer should do the following:

1. Log an error to the Application Event Log event. This is optional, but recommended.
2. Call [SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) or [SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex), passing a non-retryable error code for the *hr* or *hrWriter* parameter.

## See also

[CVssWriterEx2](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex2)