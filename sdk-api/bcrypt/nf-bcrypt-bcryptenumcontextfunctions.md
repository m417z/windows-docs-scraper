# BCryptEnumContextFunctions function

## Description

The **BCryptEnumContextFunctions** function obtains the cryptographic functions for a context in the specified configuration table.

## Parameters

### `dwTable` [in]

Identifies the configuration table from which to retrieve the context functions. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | Retrieve the context functions from the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pszContext` [in]

A pointer to a null-terminated Unicode string that contains the identifier of the context to enumerate the functions for.

### `dwInterface` [in]

Identifies the cryptographic interface to retrieve the functions for. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE** | Retrieve the asymmetric encryption functions. |
| **BCRYPT_CIPHER_INTERFACE** | Retrieve the cipher functions. |
| **BCRYPT_HASH_INTERFACE** | Retrieve the hash functions. |
| **BCRYPT_RNG_INTERFACE** | Retrieve the random number generator functions. |
| **BCRYPT_SECRET_AGREEMENT_INTERFACE** | Retrieve the secret agreement functions. |
| **BCRYPT_SIGNATURE_INTERFACE** | Retrieve the signature functions. |
| **NCRYPT_KEY_STORAGE_INTERFACE** | Retrieve the key storage functions. |
| **NCRYPT_SCHANNEL_INTERFACE** | Retrieve the Schannel functions. |

### `pcbBuffer` [in, out]

The address of a **ULONG** variable that, on entry, contains the size, in bytes, of the buffer pointed to by *ppBuffer*. If this size is not large enough to hold the set of context identifiers, this function will fail with **STATUS_BUFFER_TOO_SMALL**.

After this function returns, this value contains the number of bytes that were copied to the *ppBuffer* buffer.

### `ppBuffer` [in, out]

The address of a pointer to a [CRYPT_CONTEXT_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_functions) structure that receives the set of context functions retrieved by this function. The value pointed to by the *pcbBuffer* parameter contains the size of this buffer.

If the value pointed to by this parameter is **NULL**, this function will allocate the required memory. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is **NULL**, this function will place the required size, in bytes, in the variable pointed to by the *pcbBuffer* parameter and return **STATUS_BUFFER_TOO_SMALL**.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The *ppBuffer* parameter is not **NULL**, and the value pointed to by the *pcbBuffer* parameter is not large enough to hold the set of contexts. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_FOUND** | No context functions that match the specified criteria were found. |

## Remarks

**BCryptEnumContextFunctions** can be called only in user mode.

#### Examples

The following example shows how to use the **BCryptEnumContextFunctions** function to enumerate the key storage functions for all contexts in the local-machine configuration table.

```cpp
#include <windows.h>
#include <stdio.h>
#include <Bcrypt.h>
#pragma comment(lib, "Bcrypt.lib")

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

NTSTATUS EnumContextFunctions()
{
    NTSTATUS status;
    ULONG uSize = 0;
    PCRYPT_CONTEXTS pContexts = NULL;

    // Get the contexts for the local machine.
    // CNG will allocate the memory for us.
    status = BCryptEnumContexts(CRYPT_LOCAL, &uSize, &pContexts);
    if(NT_SUCCESS(status))
    {
        // Enumerate the context identifiers.
        for(ULONG uContextIndex = 0;
            uContextIndex < pContexts->cContexts;
            uContextIndex++)
        {
            wprintf(L"Context functions for %s:\n",
                pContexts->rgpszContexts[uContextIndex]);

            // Get the functions for this context.
            // CNG will allocate the memory for us.
            PCRYPT_CONTEXT_FUNCTIONS pContextFunctions = NULL;
            status = BCryptEnumContextFunctions(
                CRYPT_LOCAL,
                pContexts->rgpszContexts[uContextIndex],
                NCRYPT_SCHANNEL_INTERFACE,
                &uSize,
                &pContextFunctions);
            if(NT_SUCCESS(status))
            {
                // Enumerate the functions.
                for(ULONG i = 0;
                    i < pContextFunctions->cFunctions;
                    i++)
                {
                    wprintf(L"\t%s\n",
                        pContextFunctions->rgpszFunctions[i]);
                }

                // Free the context functions buffer.
                BCryptFreeBuffer(pContextFunctions);
            }
        }

        // Free the contexts buffer.
        BCryptFreeBuffer(pContexts);
    }

    return status;
}

```

## See also

[CRYPT_CONTEXT_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_context_functions)