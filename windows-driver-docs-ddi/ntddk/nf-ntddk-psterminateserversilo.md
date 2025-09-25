# PsTerminateServerSilo function

## Description

This routine terminates the specified silo.

## Parameters

### `ServerSilo` [in]

A pointer to the silo being terminated.

### `ExitStatus`

The exit status for the silo.

## Remarks

This routine can be called within or from outside a silo context.
Note that this is different from a BugCheck; this routine will return to
the caller.