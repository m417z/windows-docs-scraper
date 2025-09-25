# IWDFDeviceInitialize::SetPowerPolicyOwnership

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPowerPolicyOwnership** method sets the ownership of the power policy to a driver or removes ownership from the driver.

## Parameters

### `fTrue` [in]

A BOOL value that specifies whether to set power-policy ownership to the driver or remove ownership from the driver. **TRUE** indicates to set power-policy ownership to the driver; **FALSE** indicates to remove ownership from the driver.

## Remarks

By default, UMDF drivers are not registered as power-policy owners for their device stack. To register itself as the power-policy owner for its device stack, a UMDF driver must explicitly call **SetPowerPolicyOwnership** and pass **TRUE** to the *fTrue* parameter in this call.

For more information, see [Power Policy Ownership in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership-in-umdf).

#### Examples

For a code example of how to use the **SetPowerPolicyOwnership** method, see [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)