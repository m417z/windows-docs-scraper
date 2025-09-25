# IoGetCurrentProcess function

## Description

The **IoGetCurrentProcess** routine returns a pointer to the current process. Call **PsGetCurrentProcess** instead of **IoGetCurrentProcess**.

## Return value

**IoGetCurrentProcess** returns a pointer to the current process.

## Remarks

This routine is identical to **PsGetCurrentProcess**.

``#define PsGetCurrentProcess IoGetCurrentProcess``

## See also

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)