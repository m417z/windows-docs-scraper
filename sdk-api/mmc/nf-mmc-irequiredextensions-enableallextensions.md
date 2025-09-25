# IRequiredExtensions::EnableAllExtensions

## Description

The **IRequiredExtensions::EnableAllExtensions** method enables the snap-in to specify that all extension snap-ins registered for the snap-in are required.

## Return value

This method can return one of these values.

## Remarks

If this method returns S_OK, MMC adds all registered extensions. If any other value is returned, MMC calls
[IRequiredExtensions::GetFirstExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getfirstextension) to attempt to add the first required extension of the snap-in's list of required extensions.

If one of the required extensions can't be loaded, MMC skips it and continues to query the snap-in for the rest of them. There is no indication back to the snap-in when an extension fails to load.

If all extensions are requested, they are loaded in the order in which they are found in the registry. First, all the registered node types for the snap-in are read. Then, for each node type, all the extensions are read in the following order: namespace, context menu, toolbar, property sheet, taskpad.

## See also

[IRequiredExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-irequiredextensions)

[IRequiredExtensions::GetFirstExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-irequiredextensions-getfirstextension)