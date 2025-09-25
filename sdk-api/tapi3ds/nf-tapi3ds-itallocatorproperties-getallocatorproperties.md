# ITAllocatorProperties::GetAllocatorProperties

## Description

The
**GetAllocatorProperties** method gets the current values for the allocator properties after connection and provides the negotiated values. This method is invalid before connection. The MST will accept any values suggested by the connected filters.

## Parameters

### `pAllocProperties` [out]

Pointer to current allocator values.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAllocatorProperties](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itallocatorproperties)