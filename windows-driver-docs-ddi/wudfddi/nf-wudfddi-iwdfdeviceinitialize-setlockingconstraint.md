# IWDFDeviceInitialize::SetLockingConstraint

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetLockingConstraint** method sets the synchronization (or locking) model for callback functions into the driver.

## Parameters

### `LockType` [in]

A value of type [WDF_CALLBACK_CONSTRAINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_callback_constraint) that identifies the locking model.

## Remarks

The default value of the *LockType* parameter is **WdfDeviceLevel**, which is currently the only supported value.

#### Examples

For a code example of how to use the **SetLockingConstraint** method, see [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)