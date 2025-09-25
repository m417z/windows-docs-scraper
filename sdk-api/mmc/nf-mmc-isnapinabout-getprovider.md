# ISnapinAbout::GetProvider

## Description

The **ISnapinAbout::GetProvider** method enables the console to obtain the snap-in provider name.

## Parameters

### `lpName` [out]

A pointer to the text of the snap-in provider name.

## Return value

This method can return one of these values.

## Remarks

Memory for out parameters must be allocated using the COM API function
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).

## See also

[ISnapinAbout](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinabout)