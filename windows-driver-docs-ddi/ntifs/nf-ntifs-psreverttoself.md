# PsRevertToSelf function

## Description

The **PsRevertToSelf** routine ends the calling thread's impersonation of a client.

## Remarks

A server thread can impersonate a client by calling the [PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient) routine. When the thread is done impersonating the client, it can call the **PsRevertToSelf** routine to end all impersonations.

## See also

[PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient)