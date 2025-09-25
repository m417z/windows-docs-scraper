# TokenBindingGenerateID function

## Description

Constructs the token binding identifier by extracting the
signature algorithm from the key type and copying the exported public key.

## Parameters

### `keyType` [in]

The negotiated key type to use. Use a value from the list of key types that you retrieved by calling the [TokenBindingGetKeyTypesClient](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesclient) function.

### `publicKey` [in]

An exported public key blob.

### `publicKeySize` [in]

The size of the exported public key blob.

### `resultData` [out]

A pointer that receives the address of the buffer that is allocated for the token binding result data. The token binding result data contains the token binding identifier.

Use the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function to allocate the memory for this buffer, and the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) method to free that memory.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingGenerateID** from user mode.

## See also

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[TokenBindingVerifyMessage](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindingverifymessage)