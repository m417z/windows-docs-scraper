# IXpsOMPageReference::SetAdvisoryPageDimensions

## Description

Sets the suggested dimensions of the page.

## Parameters

### `pageDimensions` [in]

The suggested dimensions to be set for the page.

The **height** and **width** members must have the value of –1.0 or a value that is greater than or equal to +1.0.

Size is described in XPS units. There are 96 XPS units per inch. For example, the dimensions of an 8.5" by 11.0" page are 816 by 1,056 XPS units.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Either *pageDimensions* is **NULL** or a field in the [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that is referenced by *pageDimensions* contains a value that is not valid. |
| **XPS_E_INVALID_PAGE_SIZE** | The advisory page size described in *pageDimensions* was not valid. The **height** and **width** members of *pageDimensions* must have the value of –1.0 or a value that is greater than or equal to +1.0. |

## Remarks

The **height** and **width** members of the [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that is referenced by *pageDimensions* must have values that are greater than or equal to +1.0, if those fields' values are to be set, or –1.0 if not. For example, if an advisory dimension were to be set just for the page width, *pageDimensions.width* would have the desired value and *pageDimensions.height* would have the value of –1.0.

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size)