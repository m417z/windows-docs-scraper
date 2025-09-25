# ISnapinAbout::GetSnapinVersion

## Description

The ISnapinAbout::GetSnapinVersion method enables the console to obtain the snap-in's version number.

## Parameters

### `lpVersion` [out]

A pointer to the text of the snap-in version number.

## Return value

This method can return one of these values.

## Remarks

Memory for out parameters must be allocated using the COM function
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).

## See also

[ISnapinAbout](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinabout)