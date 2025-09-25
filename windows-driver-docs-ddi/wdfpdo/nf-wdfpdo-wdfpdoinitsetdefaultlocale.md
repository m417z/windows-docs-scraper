# WdfPdoInitSetDefaultLocale function

## Description

[Applies to KMDF only]

The **WdfPdoInitSetDefaultLocale** method sets a device's default locale.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `LocaleId` [in]

A locale identifier (LCID) that represents the default locale. For more information, see [Locale Identifiers](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Remarks

When the system requests device description text from a driver, it specifies a locale. If text for the specified locale is not available, the framework returns device text for the driver's default locale.

The driver must call **WdfPdoInitSetDefaultLocale** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example sets a device's default locale to United States English (0x409).

```cpp
WdfPdoInitSetDefaultLocale(
                           pDeviceInit,
                           0x409
                           );
```

## See also

[WdfPdoInitAddDeviceText](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitadddevicetext)