# TokenBindingGenerateMessage function

## Description

Assembles the list of token bindings and generates the final message for the client device to the server.

## Parameters

### `tokenBindings` [in]

Pointer to an array of token binding structures.

### `tokenBindingsSize` [in]

An array that contains the sizes of the corresponding token binding structures that the array in the *tokenBindings* parameter contains, in bytes.

### `tokenBindingsCount` [in]

The number of elements that the array in the *tokenBindings* parameter contains. This value cannot be 0.

### `tokenBindingMessage` [out]

A pointer that receives the address of the buffer that is allocated for the token binding message. Use the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function to allocate the memory for this buffer, and the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) method to free that memory.

### `tokenBindingMessageSize` [out]

A pointer to a variable that contains the size of the buffer allocated for the *tokenBindingMessage* parameter.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingGenerateMessage** from user mode.

## See also

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[TokenBindingVerifyMessage](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindingverifymessage)