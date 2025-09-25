# IoSetDevicePropertyData function

## Description

The **IoSetDevicePropertyData** routine modifies the current setting for a device property.

## Parameters

### `Pdo` [in]

A pointer to the physical device object (PDO) for the device that is being queried.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that specifies the device property key.

### `Lcid` [in]

A locale identifier. Set this parameter either to a language-specific LCID value or to **LOCALE_NEUTRAL**.

The **LOCALE_NEUTRAL** LCID specifies that the property is language-neutral (that is, not specific to any language).

Do not set this parameter to **LOCALE_SYSTEM_DEFAULT** or **LOCALE_USER_DEFAULT**.

For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags` [in]

Set this parameter to **PLUGPLAY_PROPERTY_PERSISTENT** if the property value set by this routine should persist across computer restarts. Otherwise, set *Flags* to zero.

Windows 8 and Windows Server 2012 and later operating systems treat **Flags** as if **PLUGPLAY_PROPERTY_PERSISTENT** is always passed.

### `Type` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) value that specifies the type of the data that is provided in the *Data* buffer.

### `Size` [in]

The size, in bytes, of the buffer that *Data* points to.

### `Data` [in, optional]

A pointer to the device property data. Set this parameter to **NULL** to delete the specified property. If *Data* is non-**NULL**, the routine stores an internal copy of the property value. The buffer pointed to by *Data* does not need to remain valid after the call returns.

## Return value

**IoSetDevicePropertyData** returns STATUS_SUCCESS if the call was successful, or the appropriate NTSTATUS code on failure.

## Remarks

To see property types available for use by this routine, see [DEVPROP_TYPE_BYTE](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-byte) and adjacent pages for `DEVPROP_TYPE_*`.

Kernel-mode drivers use the **IoSetDevicePropertyData** routine to modify device properties that are defined as part of the unified device property model. For more information about device properties, see [Device Properties](https://learn.microsoft.com/windows-hardware/drivers/image/device-properties).

To delete a property for a specific locale, pass a language-specific LCID value in *Lcid* and **NULL** in *Data*.

To delete a property for all locales, pass **LOCALE_NEUTRAL** in *Lcid* and **NULL** in *Data*.

To modify a property for a specific locale, pass a language-specific LCID value in *Lcid* and non-**NULL** in *Data*.

To modify a property for all locales, pass **LOCALE_NEUTRAL** in *Lcid* and non-**NULL** in *Data*.

Beginning with Windows 8 and Windows Server 2012 passing **LOCALE_NEUTRAL** in *Lcid* is treated like any other locale.

Drivers can use the [IoGetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicepropertydata) routine to obtain the current value for a device property.

Callers of **IoSetDeviceProperty** must be running at IRQL <= APC_LEVEL in the context of a system thread.

## See also

[DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85))

[DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85))

[IoGetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicepropertydata)