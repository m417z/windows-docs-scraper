# VariantGetElem function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure from a specified variant element.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `iElem` [in]

Type: **ULONG**

Specifies index of source variant structure element. If source structure is empty, then this parameter is not used.

### `pvar` [out]

Type: **VARIANT***

Pointer to the values specified from the source variant structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.