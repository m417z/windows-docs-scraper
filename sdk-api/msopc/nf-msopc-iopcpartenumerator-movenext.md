# IOpcPartEnumerator::MoveNext

## Description

Moves the current position of the enumerator to the next [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer.

## Parameters

### `hasNext` [out, retval]

A Boolean value that indicates the status of the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer at the current position.

The value of *hasNext* is only valid when the method succeeds.

| Value | Meaning |
| --- | --- |
| TRUE | The current position of the enumerator has been advanced to the next pointer and that pointer is valid. |
| FALSE | The current position of the enumerator has been advanced past the end of the collection and is no longer valid. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *hasNext* parameter is **NULL**. |
| **OPC_E_ENUM_CANNOT_MOVE_NEXT**<br><br>0x80510051 | The current position is already past the last item of the enumerator. |
| **OPC_E_ENUM_COLLECTION_CHANGED**<br><br>0x80510050 | The enumerator is invalid because the underlying set has changed. |

## Remarks

When an enumerator is created, the current position precedes the first pointer. To set the current position to the first pointer of the enumerator, call the **MoveNext** method after creating the enumerator.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartenumerator)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**