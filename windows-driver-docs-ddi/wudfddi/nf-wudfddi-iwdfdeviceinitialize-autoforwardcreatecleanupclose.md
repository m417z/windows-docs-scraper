# IWDFDeviceInitialize::AutoForwardCreateCleanupClose

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AutoForwardCreateCleanupClose** method controls when create, cleanup, and close notifications are forwarded to the next lower driver in the device stack.

## Parameters

### `State` [in]

A WDF_TRI_STATE-typed value that identifies the state of automatic forwarding. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **WdfUseDefault** (0) | The framework uses the default forwarding scheme. For more information, see the following Remarks section. |
| **WdfFalse** (1) | The framework does not forward create, cleanup, and close notifications to the next lower driver. |
| **WdfTrue** (2) | The framework synchronously forwards create, cleanup, and close notifications to the next lower driver. |

## Remarks

If the UMDF driver passes **WdfUseDefault** for the *State* parameter in a call to **AutoForwardCreateCleanupClose**, the framework uses a default forwarding scheme for create, cleanup, and close notifications that depends on whether the driver is a filter or function driver:

* If the driver is a filter driver, the default forwarding scheme is to synchronously forward notifications to the next lower driver.
* If the driver is a function driver, the default forwarding scheme is not to forward notifications to the next lower driver.

If the framework is set up for forwarding, it forwards cleanup and close notifications regardless of whether the driver supports the [IFileCallbackCleanup::OnCleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackcleanup-oncleanupfile) and [IFileCallbackClose::OnCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackclose-onclosefile) interface methods. However, the framework automatically forwards create requests only if the driver does not support the [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) method. If the driver supports **IQueueCallbackCreate::OnCreateFile**, the framework forwards create requests only if the driver explicitly set up forwarding (**WdfTrue**) to the next lower driver.

For more information about how a UMDF driver uses **AutoForwardCreateCleanupClose**, see [Preventing an Imbalance of Create and Close Notifications to a Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/preventing-an-imbalance-of-create-and-close-notifications-to-a-driver).

## See also

[IFileCallbackCleanup::OnCleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackcleanup-oncleanupfile)

[IFileCallbackClose::OnCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackclose-onclosefile)

[IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile)

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)