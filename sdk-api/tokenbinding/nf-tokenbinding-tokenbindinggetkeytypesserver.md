# TokenBindingGetKeyTypesServer function

## Description

Retrieves a list of the key types that the server supports.

## Parameters

### `keyTypes` [out]

A pointer to a buffer that contains the list of key types that the server supports. **TokenBindingGetKeyTypesServer** returns the string identifiers for well-known algorithms that correspond to the keys that the server supports.

In user mode, use [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) to allocate the memory for the buffer, and [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) to free that memory. In kernel mode, use [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag) to allocate the memory for the buffer, and [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-exfreepool) to free that memory.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingGetKeyTypesServer** from both user mode and kernel mode. To call this function in kernel mode, link to Ksecdd.sys, and use the functions mentioned in the description for the *keyTypes* parameter for allocating and freeing memory.

## See also

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[TOKENBINDING_KEY_TYPES](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_key_types)

[TokenBindingGetKeyTypesClient](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesclient)

[TokenBindingVerifyMessage](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindingverifymessage)