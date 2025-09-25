# IoOpenDriverRegistryKey function

## Description

The **IoOpenDriverRegistryKey** routine returns a handle to a driver-specific registry key for a particular driver.

## Parameters

### `DriverObject` [in]

A pointer to a [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. This structure must be the driver object for the calling driver.

### `RegKeyType` [in]

An enumeration of type [**DRIVER_REGKEY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-driver_regkey_type) that indicates the type of the requested registry key.

### `DesiredAccess` [in]

Specifies the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the access rights needed for the key. See [**ZwCreateKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) for a description of each KEY_XXX access right.

### `Flags` [in]

Set to zero.

### `DriverRegKey` [out]

A pointer to the HANDLE variable that, on successful return, contains a handle to the requested registry key.

## Return value

**IoOpenDriverRegistryKey** returns STATUS_SUCCESS if the call successfully opened a handle to the requested registry key.

## Remarks

The driver must call [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose) to close the handle returned from this routine when access is no longer needed.

The registry keys opened by this routine are nonvolatile.

To provision keys and values under the immutable **DriverRegKeyParameters** registry key, use an [AddReg directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addreg-directive) from a *service-install-section* to reference an *add-registry-section* section that contains entries with a reg-root of `HKR` and a subkey of `Parameters`.

Callers of **IoOpenDriverRegistryKey** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose)

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**DRIVER_REGKEY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-driver_regkey_type)