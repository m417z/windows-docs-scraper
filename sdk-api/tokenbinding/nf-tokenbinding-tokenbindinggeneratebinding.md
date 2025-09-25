# TokenBindingGenerateBinding function

## Description

Constructs one token binding that contains the exported public key and signature by using the specified key type for the token binding, a target identifier string for creating and retrieving the token binding key, and the unique data. This function also returns the token binding identifier, if needed.

## Parameters

### `keyType` [in]

The negotiated key type to use. Use a value from the list of key types that you retrieved by calling the [TokenBindingGetKeyTypesClient](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesclient) function.

### `targetURL` [in]

The target string to use in conjunction with the key type to generate or retrieve a token binding key for the NCrypt operations that build the buffer for the *tokenBinding* parameter.

### `bindingType` [in]

The type of token binding that **TokenBindingGenerateBinding** should generate.

### `tlsEKM` [in]

A pointer to the buffer that contains unique data.

### `tlsEKMSize` [in]

The size of the buffer that the *tlsUnique* parameter points to, in bytes.

### `extensionFormat` [in]

The format to use to interpret the data in the *extensionData* parameter. This value must be **TOKENBINDING_EXTENSION_FORMAT_UNDEFINED**.

### `extensionData` [in]

A pointer to a buffer that contains extension data. The value of the *extensionFormat* parameter determines how to interpret this data.

### `tokenBinding` [out]

A pointer that receives the address of the token binding buffer. Use the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function to allocate the memory for this buffer, and the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function to free that memory.

### `tokenBindingSize` [out]

Pointer to a variable that receives the size of the buffer allocated for the *tokenBinding* parameter, in bytes.

### `resultData` [out, optional]

A pointer that receives the address of the buffer that contains result data that includes the token binding identifier of the token binding that **TokenBindingGenerateBinding** generates. Use the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function to allocate the memory for this buffer, and the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function to free that memory. Specify NULL is you do not need this information.

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

You can call **TokenBindingGenerateBinding** from user mode.

## See also

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[TOKENBINDING_EXTENSION_FORMAT](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ne-tokenbinding-tokenbinding_extension_format)

[TOKENBINDING_RESULT_DATA](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_result_data)

[TOKENBINDING_TYPE](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ne-tokenbinding-tokenbinding_type)

[TokenBindingDeleteBinding](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindingdeletebinding)

[TokenBindingGetKeyTypesClient](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesclient)