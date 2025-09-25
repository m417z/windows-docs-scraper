# wiasGetPropertyAttributes function

## Description

The **wiasGetPropertyAttributes** function retrieves the access flags and valid values for a set of properties.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `cPropSpec`

Specifies the number of properties.

### `pPropSpec` [in]

Pointer to a [PROPSPEC](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propspec) structure indicating the properties for which to get valid values and access flags.

### `pulAccessFlags`

Pointer to an array that contains the access flags for the properties.

### `pPropVar` [out]

Pointer to an array of [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant) structures that contains the valid values for the properties.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function fills each element of the *pPropVar* array with a PROPVARIANT structure that specifies the valid values for the corresponding property. Properties with the access rights flag WIA_PROP_NONE have no valid values for that property. The data type for the valid values of these properties is VT_EMPTY.

One or more of the [WIA_PROP_Xxx property attributes](https://learn.microsoft.com/windows/win32/wia/-wia-property-attributes) and access flags can be returned in each element of the *pulAccessFlags* array.

If the property has a range of valid values, the values can be determined through the *pPropVar* parameter upon completion of this function. The *pPropVar* parameter specifies an array of PROPVARIANT structures.

Valid integer and floating-point values in a range are accessed using the following index constants.

| Valid value index | Description |
| --- | --- |
| WIA_RANGE_MIN | Minimum value |
| WIA_RANGE_NOM | Nominal value |
| WIA_RANGE_MAX | Maximum value |
| WIA_RANGE_STEP | Increment value |

Valid list values are accessed using the following index constants.

| Valid value index | Description |
| --- | --- |
| WIA_LIST_COUNT | Count of valid list values, not counting the nominal value |
| WIA_LIST_NOM | Nominal value |
| WIA_LIST_VALUES | Index to first valid value |

Valid bitwise flag values are accessed using the following index constants.

| Valid value index | Description |
| --- | --- |
| WIA_FLAG_NOM | Nominal value |
| WIA_FLAG_VALUES | All valid flags are joined together by an OR operator |