## Description

The **wiasValidateItemProperties** function validates a list of simple item properties against their current valid values.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `nPropSpec`

Specifies the number of properties to validate.

### `pPropSpec` [in]

Pointer to the first element of an array of PROPSPEC structures indicating the properties to validate.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

This function validates simple property values of the following types grouped by attribute.

| Attributes | Supported Types |
|---|---|
| WIA_PROP_FLAG | VT_UI1, VT_UI2, VT_UI4, VT_UI8, VT_I1, VT_I2, VT_I4 |
| WIA_PROP_RANGE | VT_UI1, VT_UI2, VT_UI4, VT_UI8, VT_I1, VT_I2, VT_I4, VT_R4, VT_R8 |
| WIA_PROP_LIST | VT_UI1, VT_UI2, VT_UI4, VT_UI8, VT_I1, VT_I2, VT_I4, VT_R4, VT_R8, VT_BSTR |

The PROPSPEC structure is defined in the Windows SDK documentation.