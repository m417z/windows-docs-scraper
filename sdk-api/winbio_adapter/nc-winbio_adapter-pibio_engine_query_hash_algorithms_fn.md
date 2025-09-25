# PIBIO_ENGINE_QUERY_HASH_ALGORITHMS_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve an array of object identifiers (OIDs) that represent the hash algorithms supported by the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `AlgorithmCount` [out]

Pointer to a value that receives the number of algorithm OID strings in the buffer specified by the *AlgorithmBuffer* parameter.

### `AlgorithmBufferSize` [out]

Pointer to a value that contains the size, in bytes, of the buffer specified by the *AlgorithmBuffer* parameter. The size includes the two **NULL** values that terminate the buffer.

### `AlgorithmBuffer` [out]

Address of a variable that receives a pointer to a buffer that contains packed, **NULL**-terminated ANSI strings. Each string represents an OID for a hash algorithm. The final string in the buffer must be terminated by two successive **NULL** values.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **E_NOTIMPL** | The engine adapter does not support template hash generation. |

## Remarks

Only the SHA1 hash algorithm is used by the Windows Biometric Framework. Therefore, this OID must be included in the buffer. Other OID strings are optional and can be included for future Windows versions. In Wincrypt.h, included with the Windows SDK, the symbol for the SHA1 algorithm is szOID_OIWSEC_sha1 and the associated string value is "1.3.14.3.2.26". This string value must be in the buffer. See Wincrypt.h for other OID values.

The following example shows how to create an OID buffer. The SHA1 algorithm ("1.3.14.3.2.26") is included first although the order of inclusion is not important. Another algorithm, szOID_OIWSEC_shaRSA with a value of "1.3.14.3.2.15" is also included. Note that a single **NULL** value identifies the end of each OID string and that an additional **NULL** value after the end of the last string identifies the end of the buffer.

```cpp
char OidBuffer[] =
{
    '1','.','3','.','1','4','.','3','.','2','.','2','6','\0',
    '1','.','3','.','1','4','.','3','.','2','.','1','5','\0','\0'
};

```

If this function succeeds, return the address of the start of this buffer in the *AlgorithmBuffer* argument. The engine adapter owns the buffer. Because the Windows Biometric Framework reads the buffer, the address must remain valid as long as the engine adapter is attached to the biometric unit.

Typically, you compile the table of OID strings into the engine adapter as a static data block.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterQueryHashAlgorithms
//
//      Retrieves an array of object identifiers (OIDs) that represent the
//      hash algorithms supported by the engine adapter.
//
// Parameters:
//      Pipeline            - Pointer to a WINBIO_PIPELINE structure associated
//                            with the biometric unit performing the operation.
//      AlgorithmCount      - Pointer to a value that receives the number of
//                            algorithm OID strings specified by the
//                            AlgorithmBuffer parameter.
//      AlgorithmBufferSize - Pointer to a value that contains the size,
//                            in bytes, of the buffer specified by the
//                            AlgorithmBuffer parameter.
//      AlgorithmBuffer     - Address of a variable that receives a pointer to
//                            a buffer that contains packed, NULL-terminated ANSI
//                            strings. Each string represents an OID for a hash
//                            algorithm. The final string in the buffer must be
//                            terminated by two successive NULL values.
//
// Note:
//      The following algorithm table contains the SHA1 OID. Only
//      the SHA1 hash algorithm is supported by the Windows Biometric Framework.
//      The algorithm table must be defined in global scope for the engine adapter.
//

static char g_HashAlgorithmOidTable[] =
{
    '1','.','3','.','1','4','.','3','.','2','.','2','6','\0','\0'
};

static HRESULT
WINAPI
EngineAdapterQueryHashAlgorithms(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PSIZE_T AlgorithmCount,
    __out PSIZE_T AlgorithmBufferSize,
    __out PUCHAR *AlgorithmBuffer
    )
{
    ////////////////////////////////////////////////////////////////////////////
    // Return E_NOTIMPL here if your adapter does not support template hashing.
    ////////////////////////////////////////////////////////////////////////////

    HRESULT hr = S_OK;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(AlgorithmCount) ||
        !ARGUMENT_PRESENT(AlgorithmBufferSize) ||
        !ARGUMENT_PRESENT(AlgorithmBuffer))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Pass the address and size of the static algorithm table and the number
    // of algorithms to the caller. If your adapter does not support template
    // hashing, return E_NOTIMPL.
    *AlgorithmCount = 1;
    *AlgorithmBufferSize = sizeof(g_HashAlgorithmOidTable);
    *AlgorithmBuffer = g_HashAlgorithmOidTable;

cleanup:

    return hr;
}

```

## See also

[EngineAdapterSetHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_hash_algorithm_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)