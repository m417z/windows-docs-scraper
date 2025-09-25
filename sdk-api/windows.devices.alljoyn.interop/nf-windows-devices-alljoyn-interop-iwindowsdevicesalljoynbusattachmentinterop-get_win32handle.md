# IWindowsDevicesAllJoynBusAttachmentInterop::alljoyn

## Description

Classic COM interface that simply returns a pointer to the underlying **alljoyn_busattachment** instance, so the app can use it directly with the AllJoyn Core C API.

## Parameters

### `value` [out]

The pointer to the underlying alljoyn_busattachment instance.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)

[IWindowsDevicesAllJoynBusAttachmentInterop](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.devices.alljoyn.interop/nn-windows-devices-alljoyn-interop-iwindowsdevicesalljoynbusattachmentinterop)