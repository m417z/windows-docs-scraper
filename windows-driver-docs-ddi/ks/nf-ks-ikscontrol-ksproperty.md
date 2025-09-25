# IKsControl::KsProperty (ks.h)

## Description

The **IKsControl::KsProperty** method sets a property or retrieves property information, together with any other defined support operations available on a property set.

## Parameters

### `Property` [in]

Pointer to a structure that describes a property and the request type of the property request. This structure must be either a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) or a structure that contains a **KSPROPERTY** structure as its first member. An example of a structure that can be pointed to by this member is the [KSPROPERTY_VIDEOPROCAMP_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videoprocamp_s) structure.

### `PropertyLength` [in]

Specifies size, in bytes, of the buffer at *Property*.

### `PropertyData` [in, out]

Pointer to a buffer that contains data for a KSPROPERTY_TYPE_SET, KSPROPERTY_TYPE_UNSERIALIZESET, or KSPROPERTY_TYPE_UNSERIALIZERAW operation, or buffer space that receives data for all other operations.

### `DataLength` [in]

Specifies size, in bytes, of the buffer at *PropertyData*.

### `BytesReturned` [out]

Pointer to a variable that receives the size, in bytes, of the data that **KsProperty** stores in the buffer at *PropertyData*. If no data is stored, the size is zero.

## Return value

The **IKsControl::KsProperty** method returns the same value that would be returned if the property had been sent by IOCTL.

## Remarks

To determine the buffer size that is required for a specific property request, you can call this method with *PropertyData* set to **NULL** and *DataLength* equal to zero. The method returns HRESULT_FROM_WIN32(ERROR_MORE_DATA), and *BytesReturned* contains the size of the required buffer.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set)