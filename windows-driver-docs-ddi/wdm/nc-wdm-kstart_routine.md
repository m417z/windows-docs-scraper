# KSTART_ROUTINE callback function

## Description

The *ThreadStart* routine provides an entry point for a driver-created system thread.

## Parameters

### `StartContext` [in]

A caller-supplied pointer to driver-defined context information that is specified in the *StartContext* parameter a previous call to [PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread).

## See also

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)