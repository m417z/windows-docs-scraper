# ITAllocatorProperties::SetAllocateBuffers

## Description

The
**SetAllocateBuffers** method determines whether the current allocator buffers must be set. This property is **TRUE** by default. If set **FALSE**, the sample that the MST allocated doesn't have any buffers and they must be supplied before Update is called on the samples.

## Parameters

### `bAllocBuffers` [in]

Boolean indicator of whether allocator buffers must be set.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAllocatorProperties](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itallocatorproperties)