# MmQuerySystemSize function

## Description

The **MmQuerySystemSize** routine returns an estimate of the amount of memory in the system.

## Return value

**MmQuerySystemSize** returns one of **MmSmallSystem**, **MmMediumSystem**, or **MmLargeSystem**.

## Remarks

This routine can be called during driver initialization to determine how much memory it is practical to allocate for an internal buffer.

## See also

[MmIsThisAnNtAsSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmisthisanntassystem)