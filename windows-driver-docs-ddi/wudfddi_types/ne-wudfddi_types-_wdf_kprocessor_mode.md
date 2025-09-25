# _WDF_KPROCESSOR_MODE enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_KPROCESSOR_MODE** enumeration type identifies the processor modes in which a thread can execute.

## Constants

### `WdfKProcessorModeInvalid`

Reserved for system use.

### `WdfKernelMode`

The processor mode is kernel mode.

### `WdfUserMode`

The processor mode is user mode.

### `WdfKProcessorModeMaximum`

Valid enumeration values were exceeded.

## Remarks

The **WDF_KPROCESSOR_MODE** enumeration type is return type for [IWDFIoRequest2::GetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getrequestormode).

## See also

[IWDFIoRequest2::GetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getrequestormode)