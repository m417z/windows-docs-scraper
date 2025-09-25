# DBPARAMETER structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBPARAMETER** structure is used to define values for scalar parameters.

## Members

### `pwszName`

parameter name

### `pTypeInfo`

if not a null pointer, type is described
by the ITypeInfo

### `pNum`

 Structure describing the
precision, scale and value of the numeric value.

### `cbMaxLength`

the maximum length of the parameter

### `dwFlags`

bitmask describing parameter characteristics

### `wType`

type of the parameter

## Remarks

Note that there is no entry for the ordinal position of the parameter. The assumption is that the ordinal position will be determined by the provider after evaluating the tree as a whole, and not by assigning a specific value to an individual member within the tree. Data consumers can determine the ordinal position based on the name using **ICommandWithParameters::MapParameterNames**. For more information about the interface, see [ICommandWithParameters](https://learn.microsoft.com/previous-versions/windows/desktop/ms712937(v=vs.85)).