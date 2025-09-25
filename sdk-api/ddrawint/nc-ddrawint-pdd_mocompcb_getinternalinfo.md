## Description

The **DdMoCompGetInternalInfo** callback function allows the driver to report that it internally allocates display memory to perform motion compensation.

## Parameters

### `unnamedParam1`

Points to a [DD_GETINTERNALMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getinternalmocompdata) structure that contains the internal memory requirements.

## Return value

**DdMoCompGetInternalInfo** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompGetInternalInfo**.

This function allows the decoder and DirectShow to make better-informed decisions regarding what GUID to choose.

## See also

[DD_GETINTERNALMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getinternalmocompdata)