# ISnapinAbout::GetSnapinDescription

## Description

The ISnapinAbout::GetSnapinDescription method enables the console to obtain the text for the snap-in's description box.

## Parameters

### `lpDescription` [out]

A pointer to the text for the description box on an **About** property page.

## Return value

This method can return one of these values.

## Remarks

The description should be limited to four lines of text to fit the description windows on the Snap-in Manager property pages.

Memory for out parameters must be allocated using the COM API function
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc).

## See also

[ISnapinAbout](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinabout)