## Description

The **Set** method sets a property identified by a property-set GUID and a property identifier.

## Parameters

### `PropSet` [in]

GUID that identifies the property set.

### `Id` [in]

Identifier of the property within the property set.

### `InstanceData` [in]

Pointer to instance data for the property.

### `InstanceLength` [in]

Size, in bytes, of the buffer at *InstanceData*.

### `PropertyData` [in]

Pointer to a buffer that contains the value of the property to set.

### `DataLength` [in]

Size, in bytes, of the buffer at *PropertyData*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

> [!WARNING]
> Header files *ksproxy.h* and *dsound.h* define similar but incompatible versions of the **IKsPropertySet** interface. Applications that require the KS proxy module should use the version defined in *ksproxy.h*. If an application must include both *ksproxy.h* and *dsound.h*, whichever header file the compiler scans first is the one whose definition of **IKsPropertySet** is used by the compiler.

## See also

[IKsPropertySet::Get](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspropertyset-get)