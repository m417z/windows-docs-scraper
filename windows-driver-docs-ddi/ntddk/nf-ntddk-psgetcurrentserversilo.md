# PsGetCurrentServerSilo function

## Description

This routine returns the effective server silo for the thread.

## Return value

A pointer to the current server silo. This pointer is valid for the current thread, but must be referenced before transferring to another thread (for example, via a workitem).