# IInkDivisionResult::ResultByType

## Description

Gets the requested structural units of the analysis results for an [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection.

## Parameters

### `divisionType` [in]

The [InkDivisionType](https://learn.microsoft.com/windows/desktop/api/msinkaut15/ne-msinkaut15-inkdivisiontype) enumeration value that indicates the structural units to return.

### `InkDivisionUnits` [out, retval]

A pointer to the [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection that contains the requested structural units of the analysis results.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contains an invalid pointer. |
| **E_INVALIDARG** | A parameter contains an invalid value. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method returns a new [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection each time the method is called.

If no structural units of the requested type exist in the [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object, then this method returns an empty [IInkDivisionUnits](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits) collection.

If you define a class that implements this interface, the new class will not interact correctly with the Tablet PC application programming interfaces (APIs).

## See also

[IInkDivisionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult)

[IInkDivisionUnits Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunits)

[InkDivisionType Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut15/ne-msinkaut15-inkdivisiontype)