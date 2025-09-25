# SwDeviceInterfaceRegister function

## Description

Registers a device interface for a software device and optionally sets properties on that interface.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to the software device to register a device interface for.

### `pInterfaceClassGuid` [in]

A pointer to the [interface class GUID](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) that names the contract that this interface implements.

### `pszReferenceString` [in, optional]

An optional reference string that differentiates multiple interfaces of the same class for this device. This pointer can be **NULL**.

### `cPropertyCount` [in]

The number of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures in the *pProperties* array.

### `pProperties` [in, optional]

An optional array of [DEVPROPERTY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315030(v=vs.85)) structures for the properties to set on the interface. This pointer can be **NULL**.

Set these properties on the interface after it is created but before a notification that the interface has been created are sent. For more info, see Remarks. This pointer can be **NULL**.

### `fEnabled` [in]

A Boolean value that indicates whether to either enable or disable the interface. **TRUE** to enable; **FALSE** to disable.

### `ppszDeviceInterfaceId` [out, optional]

A pointer to a variable that receives a pointer to the device interface ID for the interface. The caller must free this value with [SwMemFree](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swmemfree). This value can be **NULL** if the client app doesn't need to retrieve the name.

## Return value

S_OK is returned if **SwDeviceInterfaceRegister** successfully registered the interface; otherwise, an appropriate error value.

## Remarks

You can call **SwDeviceInterfaceRegister** only after the operating system has called your client app's [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function to notify the client app that device enumeration completed.

You can't call **SwDeviceInterfaceRegister** for software devices that specify the [SWDeviceCapabilitiesDriverRequired](https://learn.microsoft.com/windows/desktop/api/swdevicedef/ns-swdevicedef-sw_device_create_info) capability.

## See also

[SwMemFree](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swmemfree)