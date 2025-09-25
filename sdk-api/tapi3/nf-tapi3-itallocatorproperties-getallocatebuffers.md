# ITAllocatorProperties::GetAllocateBuffers

## Description

The
**GetAllocateBuffers** method determines whether the current allocator buffers can be retrieved. If it returns **FALSE**, the sample that the MST allocated doesn't have any buffers and they must be supplied before **Update** is called on the samples.

## Parameters

### `pbAllocBuffers` [out]

Indicates whether allocator buffers have been set.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAllocatorProperties](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itallocatorproperties)