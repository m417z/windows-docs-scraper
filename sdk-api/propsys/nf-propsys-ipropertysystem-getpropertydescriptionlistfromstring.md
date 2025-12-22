# IPropertySystem::GetPropertyDescriptionListFromString

## Description

Gets an instance of the subsystem object that implements [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist), to obtain an ordered collection of property descriptions, based on the provided string.

## Parameters

### `pszPropList` [in]

Type: **LPCWSTR**

A pointer to a string that identifies the property list.

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The address of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface pointer.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates interface is obtained. |
| **E_INVALIDARG** | Indicates *ppv* is **NULL**. |

## Remarks

The property description list string ("proplist") syntax consists of a sequence of canonical property names, with flags associated with each property name. The string starts with "prop:". The syntax looks like this: `prop:[flags]propertyname[endflags];`

The flags are optional and can be any of those below. Note: These flags translate to the [PROPDESC_VIEW_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_view_flags) enum.

| Flag | Meaning |
| --- | --- |
| - | Sort in reverse order (PDVF_REVERSESORT). |
| 0 | Show by default in both the primary and secondary lists (PDVF_SHOWBYDEFAULT \| PDVF_SHOWINPRIMARYLIST \| PDVF_SHOWINSECONDARYLIST). |
| 1 | Show in the primary and secondary lists (PDVF_SHOWINPRIMARYLIST \| PDVF_SHOWINSECONDARYLIST). |
| 2 | Show in secondary list (PDVF_SHOWINSECONDARYLIST). |
| ^ | Begin a new group (PDVF_BEGINNEWGROUP). |
| / | Right align (PDVF_RIGHTALIGN). |
| * | Hide if the value is not present. |
| \| | Center align. (PDVF_CENTERALIGN). |
| ~ | Hide the label. (PDVF_HIDELABEL). |
| # | Fill area. (PDVF_FILLAREA). |
| ? | Hide if unsupported by property handler (PDVF_HIDEIFUNSUPPORTED). |
| < | Parse as link (PDVF_PARSEASLINK). |
| & | Show as whole link (PDVF_SHOWASWHOLELINK). |

From the dbfolder and file folder perspective:

|  |  |
| --- | --- |
| 0 | Show as a column in defview, column chooser menu, and column chooser dialog. |
| 1 | Show in the column chooser menu and dialog. |
| 2 | Show in the column chooser dialog. |
| **NULL** | Include in the search results, but hide in the UI. |

The endflags are also optional and can be the following:

| EndFlag | Meaning |
| --- | --- |
| ] | End column (used for extended tiles view). |

It is recommended that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.

For more information about property schemas, see
[Property Schemas](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-schemas).

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)