# IOpcDigitalSignature::GetNamespaces

## Description

Gets the prefix and namespace mapping of the **Signature** element of the signature markup.

## Parameters

### `prefixes` [out]

A pointer to a buffer of XML prefix strings. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory of each string in the buffer and then to free the memory of the buffer itself.

### `namespaces` [out]

A pointer to a buffer of XML namespace strings. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory of each string in the buffer and then to free the memory of the buffer itself.

### `count` [out]

The size of the *prefixes* and *namespaces* buffers.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *prefixes* parameter is **NULL**. |
| **E_POINTER** | The *namespaces* parameter is **NULL**. |
| **E_POINTER** | The *count* parameter is **NULL**. |

## Remarks

The *prefixes* and *namespaces* buffers are mapped to each other by index.

This method allocates memory used by the buffers returned in *prefixes* and *namespaces* and the strings contained in each buffer.

#### Examples

The following code shows how to use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the memory of the buffers and the strings they contain.

```cpp
// Prepare to call GetNamespaces
LPWSTR* prefixes = NULL;
LPWSTR* namespaces = NULL;
UINT32 count = 0;

// Call to GetNamespaces succeeds
if ( SUCCEEDED( signature->GetNamespaces(&prefixes, &namespaces, &count) ) )
{
    // Process strings in prefixes and namespaces as needed for the application

    // Free memory for each string
    for (UINT32 i = 0; i < count; i++)
    {
        CoTaskMemFree(prefixes[i]);
        CoTaskMemFree(namespaces[i]);
    }
    // Free memory for the buffers
    CoTaskMemFree(prefixes);
    CoTaskMemFree(namespaces);
}
```

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**