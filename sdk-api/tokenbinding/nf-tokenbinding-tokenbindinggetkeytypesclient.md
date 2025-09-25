# TokenBindingGetKeyTypesClient function

## Description

Retrieves a list of the key types that the client device supports.

## Parameters

### `keyTypes` [out]

A pointer to a buffer that contains the list of key types that the client device supports. **TokenBindingGetKeyTypesClient** returns the string identifiers for well-known algorithms that correspond to the keys that the client device supports. Use [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) to allocate the memory for the buffer, and [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) to free that memory.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingGetKeyTypesClient** from user mode.

## See also

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[TOKENBINDING_KEY_TYPES](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_key_types)

[TokenBindingGetKeyTypesServer](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesserver)