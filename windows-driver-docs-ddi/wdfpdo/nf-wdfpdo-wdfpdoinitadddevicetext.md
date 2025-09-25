# WdfPdoInitAddDeviceText function

## Description

[Applies to KMDF only]

The **WdfPdoInitAddDeviceText** method adds a device description and device location to a device, for a specified locale.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceDescription` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a device description, formatted for the given locale. The driver can allocate the string's buffer from paged pool.

### `DeviceLocation` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a description of the location on the bus where the parent device found the child. The driver can allocate the string's buffer from paged pool.

### `LocaleId` [in]

A locale identifier (LCID) that represents the locale of the Unicode strings. For more information, see [Locale Identifiers](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver is initializing an FDO instead of a PDO. |
| **STATUS_INSUFFICIENT_RESOURCES** | The driver could not allocate space to store the strings. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The framework stores the specified device text and passes it to the PnP manager in response to an [IRP_MN_QUERY_DEVICE_TEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-text) request. The text that you supply should help the user to identify the device. The PnP manager sometimes displays the text while attempting to install additional drivers for the device.

You can call **WdfPdoInitAddDeviceText** multiple times, adding device text for multiple locales. When the system displays the text, it chooses the text that matches the current locale, if available. Otherwise, it will use the string for the default locale. The driver can specify the driver's default locale by calling [WdfPdoInitSetDefaultLocale](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitsetdefaultlocale).

The driver must call **WdfPdoInitAddDeviceText** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example provides Unicode strings for a device's location and description. The description includes an instance number. For a complete example that uses **WdfPdoInitAddDeviceText**, see the [KbFiltr](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver.

```cpp
DECLARE_CONST_UNICODE_STRING(deviceLocation,L"Keyboard Filter\0" );
DECLARE_UNICODE_STRING_SIZE(buffer, MAX_ID_LEN);

status = RtlUnicodeStringPrintf(
                                &buffer,
                                L"Keyboard_Filter_%02d",
                                InstanceNo
                                );
if (!NT_SUCCESS(status)) {
    goto Cleanup;
}
status = WdfPdoInitAddDeviceText(
                                 pDeviceInit,
                                 &buffer,
                                 &deviceLocation,
                                 0x409
                                 );
if (!NT_SUCCESS(status)) {
    goto Cleanup;
}
```

## See also

[WdfPdoInitSetDefaultLocale](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitsetdefaultlocale)