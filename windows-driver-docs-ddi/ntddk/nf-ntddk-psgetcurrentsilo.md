# PsGetCurrentSilo function

## Description

This routine returns the current silo for the calling thread. First the thread is checked to see if it has been attached to a silo. If not, then the thread is checked to see if it is in a silo.

## Return value

A pointer to the **ESILO** object. This pointer is valid for the current thread, but must be referenced before transferring to another thread (for example, via a workitem).