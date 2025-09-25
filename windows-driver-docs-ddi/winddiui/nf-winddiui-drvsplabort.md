# DrvSplAbort function

## Description

The **DrvSplAbort** function is obsolete, and is supported only so that user-mode rendering DLLs, optionally supplied with Windows NT 4.0 drivers, will execute under Windows 2000 and later.

Use [DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent) instead of this function.

The **DrvSplAbort** function enables a user-mode rendering DLL to respond to a request to cancel a print job.

## Parameters

### `hDriver`

The handle of the driver object.

## Remarks

To supply user-mode image-rendering code for printers, see [Choosing User Mode or Kernel Mode](https://learn.microsoft.com/windows-hardware/drivers/print/choosing-user-mode-or-kernel-mode).