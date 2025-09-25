# BCryptEnumContexts function

## Description

[**BCryptEnumContexts** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **BCryptEnumContexts** function obtains the identifiers of the contexts in the specified configuration table.

## Parameters

### `dwTable` [in]

Identifies the configuration table from which to retrieve the contexts. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_LOCAL** | Retrieve the contexts from the local-machine configuration table. |
| **CRYPT_DOMAIN** | This value is not available for use. |

### `pcbBuffer` [in, out]

The address of a **ULONG** variable that, on entry, contains the size, in bytes, of the buffer pointed to by *ppBuffer*. If this size is not large enough to hold the set of context identifiers, this function will fail with **STATUS_BUFFER_TOO_SMALL**.

After this function returns, this value contains the number of bytes that were copied to the *ppBuffer* buffer.

### `ppBuffer` [in, out]

The address of a pointer to a [CRYPT_CONTEXTS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_contexts) structure that receives the set of contexts retrieved by this function. The value pointed to by the *pcbBuffer* parameter contains the size of this buffer.

If the value pointed to by this parameter is **NULL**, this function will allocate the required memory. This memory must be freed when it is no longer needed by passing this pointer to the [BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer) function.

If this parameter is **NULL**, this function will place the required size, in bytes, in the variable pointed to by the *pcbBuffer* parameter and return **STATUS_BUFFER_TOO_SMALL**.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_BUFFER_TOO_SMALL** | The *ppBuffer* parameter is not **NULL**, and the value pointed to by the *pcbBuffer* parameter is not large enough to hold the set of contexts. |

## Remarks

**BCryptEnumContexts** can be called only in user mode.

#### Examples

The following example shows how to use the **BCryptEnumContexts** function to allocate the memory for the *ppBuffer* buffer.

```cpp
#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

NTSTATUS EnumContexts_SystemAlloc()
{
    NTSTATUS status;
    ULONG uSize = 0;
    PCRYPT_CONTEXTS pContexts = NULL;

    // Get the contexts for the local computer.
    // CNG allocates the memory.
    status = BCryptEnumContexts(CRYPT_LOCAL, &uSize, &pContexts);
    if(NT_SUCCESS(status))
    {
        // Enumerate the context identifiers.
        for(ULONG i = 0; i < pContexts->cContexts; i++)
        {
            wprintf(pContexts->rgpszContexts[i]);
            wprintf(L"\n");
        }

        // Free the buffer.
        BCryptFreeBuffer(pContexts);
    }

    return status;
}

```

The following example shows how to use the **BCryptEnumContexts** function to allocate your own memory for the *ppBuffer* buffer.

```cpp
#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

NTSTATUS EnumContexts_SelfAlloc()
{
    NTSTATUS status;
    ULONG uSize = 0;

    // Get the required size of the buffer.
    status = BCryptEnumContexts(CRYPT_LOCAL, &uSize, NULL);
    if(STATUS_BUFFER_TOO_SMALL == status)
    {
        // Allocate the buffer.
        PCRYPT_CONTEXTS pContexts = (PCRYPT_CONTEXTS)HeapAlloc(
            GetProcessHeap(),
            HEAP_ZERO_MEMORY,
            uSize);
        if(pContexts)
        {
            // Get the contexts for the local machine.
            status = BCryptEnumContexts(
                CRYPT_LOCAL,
                &uSize,
                &pContexts);
            if(NT_SUCCESS((status))
            {
                // Enumerate the context identifiers.
                for(ULONG i = 0; i < pContexts->cContexts; i++)
                {
                    wprintf(pContexts->rgpszContexts[i]);
                    wprintf(L"\n");
                }
            }

            // Free the buffer.
            HeapFree(GetProcessHeap(), 0, pContexts);
            pContexts = NULL;
        }
        else
        {
            status = STATUS_NO_MEMORY;
        }
    }

    return status;
}

```

## See also

[BCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfreebuffer)

[CRYPT_CONTEXTS](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-crypt_contexts)