# IOpcPartUri::ComparePartUri

## Description

Returns an integer that indicates whether the URIs represented by the current part URI object and a specified part URI object are equivalent.

## Parameters

### `partUri` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object to compare with the current part URI object.

### `comparisonResult` [out, retval]

Receives an integer that indicates whether the two part URI objects are equivalent.

| Value | Meaning |
| --- | --- |
| <0 | The current part URI object is less than the input part URI object that is passed in *partUri*. |
| 0 | The current part URI object is equivalent to the input part URI object that is passed in *partUri*. |
| >0 | The current part URI object is greater than the input part URI object that is passed in *partUri*. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *partUri*, and *comparisonResult* parameters is **NULL**. |

## Remarks

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**