## Description

The **KsPeekAllocator** method returns a pointer to an **IMemAllocator** interface for a pin's assigned allocator.

## Parameters

### `Operation` [in]

A value that specifies the type of operation. This value can be one of the following values from the KSPEEKOPERATION enumerated type.

| Value | Description |
|---|---|
| **KsPeekOperation_PeekOnly** | **IKsPin::KsPeekAllocator** does not increment the reference count for the allocator. |
| **KsPeekOperation_AddRef** | **IKsPin::KsPeekAllocator** increments the reference count for the allocator (calls AddRef). |

## Return value

Returns a pointer to an **IMemAllocator** interface if successful; otherwise, returns **NULL**.

## Remarks

For more information about **IMemAllocator**, see the Microsoft Windows SDK documentation.

This method is for proxy use and is not recommended for application use.

## See also

[IKsPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspin)