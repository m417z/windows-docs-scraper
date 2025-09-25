# IOpcPartSet::PartExists

## Description

Gets a value that indicates whether a specified part is represented as a part object in the set.

## Parameters

### `name` [in]

A pointer to an [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) that represents the part name of the part.

### `partExists` [out, retval]

One of the following values:

| Value | Meaning |
| --- | --- |
| **TRUE** | A part that has the specified part name is represented in the set. |
| **FALSE** | A part that has the specified part name is not represented in the set. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partExists* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

To retrieve the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer of the part object that represents a specific part, call the **PartExists** method and pass in the part name to confirm that the part is represented in the set. If it is, call the [GetPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcpartset-getpart) method and pass in the part name to retrieve the **IOpcPart** interface pointer.

If the represented part name is the name of a Relationships part, *partExists* is receives **FALSE** because Relationships parts are not included in the set.

If a part is represented in the set, the part exists in the package being read or the package to be written.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

**Reference**