# IRequiredExtensions::GetNextExtension

## Description

The **IRequiredExtensions::GetNextExtension** method enables the snap-in to specify the next extension snap-in in its list of required extension snap-ins.

## Parameters

### `pExtCLSID` [out]

A pointer to the CLSID of the next snap-in in the list of required extension snap-ins.

## Return value

This method can return one of these values.

## Remarks

MMC calls the method for the first time if
[IRequiredExtensions::GetFirstExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getfirstextension) returns an S_OK value. MMC iterates the list of required extensions to add by calling **IRequiredExtensions::GetNextExtension** until it returns a value other than S_OK.

If this method returns S_OK, MMC adds the extension snap-in specified by pExtCLSID and then calls **IRequiredExtensions::GetNextExtension** again to get the next extension snap-in in the list.

If another value is returned, MMC considers the return an indicator of the end of the list. In this case, MMC does not add the extension snap-in specified by pExtCLSID and stops calling **IRequiredExtensions::GetNextExtension**.

## See also

[IRequiredExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-irequiredextensions)

[IRequiredExtensions::GetFirstExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getfirstextension)