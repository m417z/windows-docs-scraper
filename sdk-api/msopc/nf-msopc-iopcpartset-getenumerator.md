# IOpcPartSet::GetEnumerator

## Description

Gets an enumerator of [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointers in the set.

## Parameters

### `partEnumerator` [out, retval]

A pointer to the [IOpcPartEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartenumerator) interface of the enumerator of [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointers in the set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partEnumerator* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**