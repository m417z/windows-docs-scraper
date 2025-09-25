# IKsControl::KsMethod (ks.h)

## Description

The **IKsControl::KsMethod** method sends a method to a KS object, together with any other defined support operations available on a method set.

## Parameters

### `Method` [in]

Pointer to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that describes a method and the request type of the method request.

### `MethodLength` [in]

Specifies size, in bytes, of the buffer at *Method*.

### `MethodData` [in, out]

Pointer to a buffer that contains data and buffer space for a KSMETHOD_TYPE_SEND operation, or buffer space that receives data for all other operations.

### `DataLength` [in]

Specifies size, in bytes, of the buffer at *MethodData*.

### `BytesReturned` [out]

Pointer to a variable that receives the size, in bytes, of the data that **KsMethod** stores in the buffer at *MethodData*.

## Return value

The **IKsControl::KsMethod** method returns the same value that would be returned if the method had been sent by IOCTL.

## Remarks

To determine the buffer size that is required for a specific method request, you can call this method with MethodData set to **NULL** and DataLength equal to zero. The method returns HRESULT_FROM_WIN32(ERROR_MORE_DATA and BytesReturned contains the size of the required buffer.

## See also

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[KSMETHOD_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set)