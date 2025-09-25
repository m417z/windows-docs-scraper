# NetConfigurationQueryString function

## Description

Retrieves the specified string value from the adapter configuration object and assigns the string to a specified framework string object.

## Parameters

### `Configuration` [_In_]

Handle to a NETCONFIGURATION object that represents an opened registry key.

### `ValueName` [_In_]

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a name for string value.

### `StringAttributes` [_In_opt_]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new WDFSTRING object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `WdfString` [_Out_]

A handle to a framework string object. NetAdapterCx will assign the registry value's string data to this object.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

By default, the framework string object is parented to the collection object. The client driver can change this by setting the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

## See also