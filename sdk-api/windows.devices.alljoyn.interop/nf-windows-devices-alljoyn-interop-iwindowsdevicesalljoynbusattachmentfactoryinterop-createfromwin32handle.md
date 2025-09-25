# IWindowsDevicesAllJoynBusAttachmentFactoryInterop::alljoyn

## Description

Constructs an **AllJoynBusAttachment** over an existing **alljoyn_busattachment** instance without taking ownership.

## Parameters

### `win32handle` [in]

The Win32 handle for the existing instance.

### `enableAboutData` [in]

Toggle to enable AboutData.

### `riid` [in]

The ID of the **IAllJoynBusAttachment** interface.

### `ppv` [out]

Out parameter through which the **AllJoynBusAttachment** is returned.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)

[IWindowsDevicesAllJoynBusAttachmentFactoryInterop](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.devices.alljoyn.interop/nn-windows-devices-alljoyn-interop-iwindowsdevicesalljoynbusattachmentfactoryinterop)