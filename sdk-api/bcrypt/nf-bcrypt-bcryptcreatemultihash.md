# BCryptCreateMultiHash function

## Description

The **BCryptCreateMultiHash** function creates a multi-hash state that allows for the parallel computation of multiple hash operations. This multi-hash state is used by the [BCryptProcessMultiOperations](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptprocessmultioperations) function. The multi-hash state can be thought of as an array of hash objects, each of which is equivalent to one created by [BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash).

 Parallel computations can greatly increase overall throughput, at the expense of increased latency for individual computations.

 Parallel hash computations are currently only implemented for SHA-256, SHA-384, and SHA-512. Other hash algorithms can be used with the parallel computation API but they run at the throughput of the sequential hash operations. The set of hash algorithms that can benefit from parallel computations might change in future updates.

## Parameters

### `hAlgorithm`

*BCRYPT_ALG_HANDLE* `[in, out]`

The algorithm handle used for all of the hash states in the multi-hash array. The algorithm handle must have been opened with the **BCYRPT_MULTI_FLAG** passed to the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function. Alternatively, the caller can use the pseudo-handles.

### `phHash`

*BCRYPT_HASH_HANDLE** `[out]`

A pointer to a **BCRYPT_HASH_HANDLE** value that receives a handle that represents the multi-hash state. This handle is used in subsequent operations such as [BCryptProcessMultiOperations](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptprocessmultioperations). When you have finished using this handle, release it by passing it to the [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash) function.

### `nHashes`

*ULONG* `[in]`

The number of elements in the array. The multi-hash state that this function creates is able to perform parallel computations on *nHashes* different hash states.

### `pbHashObject`

*PUCHAR* `[out]`

A pointer to a buffer that receives the multi-hash state.

The size can be calculated from the **cbPerObject** and **cbPerElement** members of the [BCRYPT_MULTI_OBJECT_LENGTH_STRUCT](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_multi_object_length_struct) structure. The value is the following: `cbPerObject + (number of hash states) * cbPerElement`.

If *pbHashObject* is `NULL` and *cbHashObject* has a value of zero (`0`), the object buffer is automatically allocated.

### `cbHashObject`

*ULONG* `[in]`

The size of the *pbHashObject* buffer, or zero (`0`) if *pbHashObject* is `NULL`.

### `pbSecret`

*PUCHAR* `[in]`

A pointer to a buffer that contains the key to use for the hash or MAC. The *cbSecret* parameter contains the size of this buffer. This key only applies to hash algorithms opened by the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function by using the **BCRYPT_ALG_HANDLE_HMAC** flag. Otherwise, set this parameter to `NULL`.

The same key is used for all elements of the array.

### `cbSecret`

*ULONG* `[in]`

The size, in bytes, of the *pbSecret* buffer. If no key is used, set this parameter to zero (`0`).

### `dwFlags`

*ULONG* `[in]`

Flags that modify the behavior of the function. This can be zero or the values below. Multi-hash objects are always reusable and always behave as if the **BCRYPT_HASH_REUSABLE_FLAG** was passed. This flag is supported here for consistency.

| Value | Meaning |
|--------|--------|
| **BCRYPT_HASH_REUSABLE_FLAG** | Creates a reusable hashing object. The object can be used for a new hashing operation immediately after calling [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash). For more information, see [Creating a Hash with CNG](https://learn.microsoft.com/windows/win32/SecCNG/creating-a-hash-with-cng). |

## Return value

Returns a status code that indicates the success or failure of the function. If the method succeeds, it will return `STATUS_SUCCESS`. For other **NTSTATUS** values, see [NTSTATUS Values](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55).

## Remarks

 Internally, parallel hash computations are done using single-instruction multiple-data (SIMD) instructions with up to 8 parallel computations at a time, depending on the hash algorithm and the CPU features available. To maximize performance, we recommend that the caller provide at least eight computations that can be processed in parallel.

For computations of unequal length, providing more computations in parallel allows the implementation to schedule the computations better across the CPU registers. This can provide a throughput benefit. For optimal throughput, we recommend that the caller provide between eight and 100 computations. Select a lower value in that range only if all the hash computations are the same length.

Multi-hashing is not supported for HMAC-MD2, HMAC-MD4, and GMAC.

## See also

[BCRYPT_MULTI_OBJECT_LENGTH](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_multi_object_length_struct)

[BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash)

[BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash)

[BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash)

[BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata)

[BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider)

[BCryptProcessMultiOperations](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptprocessmultioperations)

[Creating a Hash with CNG](https://learn.microsoft.com/windows/win32/SecCNG/creating-a-hash-with-cng)