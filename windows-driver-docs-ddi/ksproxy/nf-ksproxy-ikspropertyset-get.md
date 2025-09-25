## Description

The **Get** method retrieves a property identified by a property-set GUID and a property identifier.

## Parameters

### `PropSet` [in]

GUID that identifies the property set.

### `Id` [in]

Identifier of the property within the property set.

### `InstanceData` [in]

Pointer to instance data for the property.

### `InstanceLength` [in]

Size, in bytes, of the buffer at *InstanceData*.

### `PropertyData` [out]

Pointer to a buffer that receives the value of the property.

### `DataLength` [in]

Size, in bytes, of the buffer at *PropertyData*.

### `BytesReturned` [out]

Pointer to a variable that receives the size, in bytes, of the data that **Get** stores in the buffer at *PropertyData*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

To retrieve a property, allocate a buffer, which **Get** fills with the property. To determine the necessary buffer size, specify **NULL** for *PropertyData* and zero for *DataLength*. The **Get** method returns the required buffer size in *BytesReturned*.

> [!WARNING]
> Header files *ksproxy.h* and *dsound.h* define similar but incompatible versions of the **IKsPropertySet** interface. Applications that require the KS proxy module should use the version defined in *ksproxy.h*. If an application must include both *ksproxy.h* and *dsound.h*, whichever header file the compiler scans first is the one whose definition of **IKsPropertySet** is used by the compiler.

## See also

[IKsPropertySet::Set](https://learn.microsoft.com/windows-hardware/drivers/ddi/dsound/nf-dsound-ikspropertyset-set)