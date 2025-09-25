# wiasSetPropertyAttributes function

## Description

The **wiasSetPropertyAttributes** function sets the access flags and valid values for a set of properties.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `cPropSpec`

Specifies the number of properties.

### `pPropSpec` [in]

Pointer to a PROPSPEC structure indicating the properties for which to set valid values and access flags.

### `pulAccessFlags` [in]

Pointer to an array that contains the access flags to be written.

### `pPropVar` [out]

Pointer to an array of PROPVARIANT structures that contains the valid values to be written.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

Minidrivers should use the function [wiasSetItemPropAttribs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropattribs) to initialize groups of simple properties.

The minidriver can set the WIA_PROP_CACHEABLE flag on a property that does not change over time. By setting this flag on a property, the minidriver indicates that the WIA service can cache the property value. See the Windows SDK documentation for a list of all property attributes.

The PROPSPEC and PROPVARIANT structures are defined in the Windows SDK documentation.

## See also

[wiasSetItemPropAttribs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropattribs)