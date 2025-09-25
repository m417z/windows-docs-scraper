# TokenBindingVerifyMessage function

## Description

Validates the token binding message and verifies the token bindings that the message contains.

## Parameters

### `tokenBindingMessage` [in]

A pointer to the buffer that contains the token binding message.

### `tokenBindingMessageSize` [in]

The size of the buffer that the *tokenBindingMessage* parameter points to, in bytes.

### `keyType` [in]

The negotiated key algorithm to use. Use a value from the list of key types that you retrieved by calling the [TokenBindingGetKeyTypesServer](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesserver) function.

### `tlsEKM` [in]

A pointer to a buffer that contains unique data.

### `tlsEKMSize` [in]

The size of the buffer that the *tlsUnique* parameter points to, in bytes.

### `resultList` [out]

A pointer that receives the address for the buffer that contains the results for each of the token bindings that **TokenBindingVerifyMessage** verifies.

In user mode, use [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) to allocate the memory for the buffer, and [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) to free that memory. In kernel mode, use [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag) to allocate the memory for the buffer, and [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-exfreepool) to free that memory.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingVerifyMessage** from both user mode and kernel mode. o call this function in kernel mode, link to Ksecdd.sys, and use the functions mentioned in the description for the *resultList* parameter for allocating and freeing memory.

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-exfreepool)

[TOKENBINDING_RESULT_LIST](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_result_list)

[TokenBindingGenerateMessage](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggeneratemessage)

[TokenBindingGetKeyTypesServer](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesserver)