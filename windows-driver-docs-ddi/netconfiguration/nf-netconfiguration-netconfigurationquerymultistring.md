# NetConfigurationQueryMultiString function

## Description

Retrieves the MultiString-valued registry entry associated with a value name in the specified configuration object.

## Parameters

### `Configuration` [_In_]

Handle to a NETCONFIGURATION object that represents an opened registry key.

### `ValueName` [_In_]

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name in the device's software key.

### `StringsAttributes` [_In_opt_]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new WDFSTRING objects. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Collection` [_Inout_]

A handle to a driver-supplied collection object. If the function succeeds, contains a WDFSTRING object for each string assigned to *ValueName*.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. If the registry value is NULL, **NetConfigurationQueryMultiString** returns **STATUS_OBJECT_NAME_NOT_FOUND**.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

By default, the strings are parented to the collection object. The client driver can change this by setting the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

## See also