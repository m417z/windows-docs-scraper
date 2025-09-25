# IKsControl::KsMethod (ksproxy.h)

## Description

The **KsMethod** method sends a method to a KS object, along with any other defined support operations available on a method set.

## Parameters

### `Method` [in]

Pointer to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that describes a method and the request type of the method request.

### `MethodLength` [in]

Size, in bytes, of the buffer at *Method*.

### `MethodData` [in, out]

Pointer to a buffer that contains data and buffer space for a KSMETHOD_TYPE_SEND operation, or buffer space that receives data for all other operations.

### `DataLength` [in]

Size, in bytes, of the buffer at *MethodData*.

### `BytesReturned` [in, out]

Pointer to a variable that receives the size, in bytes, of the data that **KsMethod** stores in the buffer at *MethodData*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

This is a synchronous call. It will not complete until the method is completed from kernel-mode.

To determine the buffer size that is required for a specific method request, you can call this method with MethodData set to **NULL** and DataLength equal to zero. The method returns HRESULT_FROM_WIN32(ERROR_MORE_DATA and BytesReturned contains the size of the required buffer.

## See also

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)