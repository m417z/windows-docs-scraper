# IWDFIoTarget::GetTargetFile

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **GetTargetFile** method retrieves the framework file object that is associated with the I/O target object.

## Parameters

### `ppWdfFile` [out]

Pointer to a buffer that receives a pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the I/O target's file object.

## Remarks

If a framework file object is associated with an I/O target object, the framework includes the file object with I/O requests that the driver sends to the I/O target object.

When a driver formats an I/O request, an I/O target object enables the driver to use either the same file that the request started with or a new file.

The default I/O target has no file object, so a call to **GetTargetFile** for the default I/O target retrieves **NULL**.

For more information about I/O targets, see [Using I/O Targets in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf).

### Examples

For a code example of how to use the **GetTargetFile** method, see [IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite).

## See also

- [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)
- [Using I/O Targets in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf)
- [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)
- [IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite)