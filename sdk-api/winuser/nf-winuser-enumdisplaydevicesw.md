# EnumDisplayDevicesW function

## Description

The **EnumDisplayDevices** function lets you obtain information about the display devices in the current session.

## Parameters

### `lpDevice` [in]

A pointer to the device name. If **NULL**, function returns information for the display adapter(s) on the machine, based on *iDevNum*.

For more information, see Remarks.

### `iDevNum` [in]

An index value that specifies the display device of interest.

The operating system identifies each display device in the current session with an index value. The index values are consecutive integers, starting at 0. If the current session has three display devices, for example, they are specified by the index values 0, 1, and 2.

### `lpDisplayDevice` [out]

A pointer to a [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea) structure that receives information about the display device specified by *iDevNum*.

Before calling **EnumDisplayDevices**, you must initialize the **cb** member of [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea) to the size, in bytes, of **DISPLAY_DEVICE**.

### `dwFlags` [in]

Set this flag to EDD_GET_DEVICE_INTERFACE_NAME (0x00000001) to retrieve the device interface name for GUID_DEVINTERFACE_MONITOR, which is registered by the operating system on a per monitor basis. The value is placed in the DeviceID member of the [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea) structure returned in *lpDisplayDevice*. The resulting device interface name can be used with [SetupAPI functions](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi) and serves as a link between GDI monitor devices and SetupAPI monitor devices.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. The function fails if *iDevNum* is greater than the largest device index.

## Remarks

To query all display devices in the current session, call this function in a loop, starting with *iDevNum* set to 0, and incrementing *iDevNum* until the function fails. To select all display devices in the desktop, use only the display devices that have the DISPLAY_DEVICE_ATTACHED_TO_DESKTOP flag in the [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea) structure.

To get information on the display adapter, call **EnumDisplayDevices** with *lpDevice* set to **NULL**. For example, [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea).**DeviceString** contains the adapter name.

To obtain information on a display monitor, first call **EnumDisplayDevices** with *lpDevice* set to **NULL**. Then call **EnumDisplayDevices** with *lpDevice* set to [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea).**DeviceName** from the first call to **EnumDisplayDevices** and with *iDevNum* set to zero. Then **DISPLAY_DEVICE**.**DeviceString** is the monitor name.

To query all monitor devices associated with an adapter, call **EnumDisplayDevices** in a loop with *lpDevice* set to the adapter name, *iDevNum* set to start at 0, and *iDevNum* set to increment until the function fails. Note that **DISPLAY_DEVICE.DeviceName** changes with each call for monitor information, so you must save the adapter name. The function fails when there are no more monitors for the adapter.

> [!NOTE]
> The winuser.h header defines EnumDisplayDevices as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa)

[ChangeDisplaySettingsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsexa)

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa)