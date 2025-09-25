# KsLoadResource function

## Description

Copies (loads) a resource from the given image.

## Parameters

### `ImageBase` [in]

Pointer to the image base

### `PoolType` [in]

Pool type to use when copying resource

### `ResourceName` [in]

Resource name.

### `ResourceType` [in]

Resource type

### `Resource` [out]

Pointer to resultant resource memory.

### `ResourceSize` [out, optional]

Pointer to ULONG value to receive the size of the resource.

## Return value

STATUS_SUCCESS if successful, STATUS_INSUFFICIENT_RESOURCES if memory cannot be allocated, otherwise an appropriate error code.