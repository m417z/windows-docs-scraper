# IWDFUsbInterface::SelectSetting

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SelectSetting** method selects the specified alternate setting on a USB interface.

## Parameters

### `SettingNumber` [in]

The setting to select on the USB interface.

## Return value

**SelectSetting** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [SelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-selectsetting) successfully selected the setting that the *SettingNumber* parameter specified. |
| **E_OUTOFMEMORY** | [SelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-selectsetting) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

The framework automatically selects configuration zero, its interface zero, and the alternate setting zero. To change the alternate setting, the driver can call **SelectSetting**.

For more info [USB Configuration Descriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

#### Examples

```
hr = pIWDFUsbInterface->SelectSetting(SettingNumber);
```

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)