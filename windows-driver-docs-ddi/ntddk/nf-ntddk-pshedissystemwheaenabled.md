# PshedIsSystemWheaEnabled function

## Description

The **PshedIsSystemWheaEnabled** function returns a Boolean value that indicates whether the system is WHEA-enabled.

## Return value

A Boolean value that indicates whether the system is WHEA-enabled.

## Remarks

A PSHED plug-in can call the **PshedIsSystemWheaEnabled** function before it calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to verify that the system is WHEA-enabled.

## See also

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)