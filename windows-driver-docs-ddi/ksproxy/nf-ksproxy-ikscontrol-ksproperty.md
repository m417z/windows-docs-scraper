# IKsControl::KsProperty (ksproxy.h)

## Description

The **KsProperty** method sets a property or retrieves property information, along with any other defined support operations available on a property set.

## Parameters

### `Property` [in]

Pointer to a structure that describes a property and the request type of the property request. This structure must be either a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) or a structure that contains a **KSPROPERTY** structure as its first member. An example of a structure that can be pointed to by this member is the [KSPROPERTY_VIDEOPROCAMP_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videoprocamp_s) structure.

### `PropertyLength` [in]

Size, in bytes, of the buffer at *Property*.

### `PropertyData` [in, out]

Pointer to a buffer that contains data for a KSPROPERTY_TYPE_SET, KSPROPERTY_TYPE_UNSERIALIZESET, or KSPROPERTY_TYPE_UNSERIALIZERAW operation, or buffer space that receives data for all other operations.

### `DataLength` [in]

Size, in bytes, of the buffer at *PropertyData*.

### `BytesReturned` [in, out]

Pointer to a variable that receives the size, in bytes, of the data that **KsProperty** stores in the buffer at *PropertyData*. If no data is stored, the size is zero.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

To determine the buffer size that is required for a specific property request, you can call this method with *PropertyData* set to **NULL** and *DataLength* equal to zero. The method returns HRESULT_FROM_WIN32(ERROR_MORE_DATA), and *BytesReturned* contains the size of the required buffer.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOPROCAMP_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videoprocamp_s)