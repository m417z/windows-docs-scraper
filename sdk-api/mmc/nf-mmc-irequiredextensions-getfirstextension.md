# IRequiredExtensions::GetFirstExtension

## Description

The **IRequiredExtensions::GetFirstExtension** method enables the snap-in to specify the first extension snap-in its list of required extension snap-ins.

## Parameters

### `pExtCLSID` [out]

A pointer to the CLSID of the first snap-in in the list of required extension snap-ins.

## Return value

This method can return one of these values.

## Remarks

MMC calls this method if
[IRequiredExtensions::EnableAllExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-enableallextensions) returns a value that is not S_OK.

If this method returns S_OK, MMC adds the extension snap-in specified by pExtCLSID and then calls
[IRequiredExtensions::GetNextExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getnextextension) to get the next extension snap-in in the list. If any other value is returned, MMC treats the required list as if it were empty by not adding the extension snap-in specified by pExtCLSID and not calling **IRequiredExtensions::GetNextExtension**.

## See also

[IRequiredExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-irequiredextensions)

[IRequiredExtensions::EnableAllExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-enableallextensions)

[IRequiredExtensions::GetNextExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getnextextension)