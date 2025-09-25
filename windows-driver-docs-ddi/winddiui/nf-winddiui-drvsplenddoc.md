# DrvSplEndDoc function

## Description

The **DrvSplEndDoc** function is obsolete, and is supported only so that user-mode rendering DLLs, optionally supplied with Windows NT 4.0 drivers, will execute under Windows 2000 and later.

Use [DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent) instead of this function.

The **DrvSplEndDoc** function enables a user-mode rendering DLL to perform operations associated with the end of a print job.

## Parameters

### `hDriver`

The handle of the driver object.

## Remarks

To supply user-mode image-rendering code for printers, see [Choosing User Mode or Kernel Mode](https://learn.microsoft.com/windows-hardware/drivers/print/choosing-user-mode-or-kernel-mode).