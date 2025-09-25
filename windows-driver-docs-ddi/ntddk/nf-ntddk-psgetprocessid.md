# PsGetProcessId function

## Description

The **PsGetProcessId** routine returns the process identifier (process ID) that is associated with a specified process.

## Parameters

### `Process` [in]

A pointer to a process object structure.

## Return value

**PsGetProcessId** returns the process ID of the process that the **Process** parameter specifies.

## Remarks

The EPROCESS-typed process object structure is an opaque data structure that the operating system uses internally. To obtain a pointer to the EPROCESS structure for the current process, a driver can call [**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess). To obtain a pointer to the EPROCESS structure for a different process, the driver can call [**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle).

## See also

[**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)