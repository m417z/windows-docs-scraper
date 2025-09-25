# SMMCObjectTypes structure

## Description

The
**SMMCDynamicExtensions** structure is introduced in MMC 1.1.

The
**SMMCDynamicExtensions** structure defines the format of the data for the
[CCF_MMC_DYNAMIC_EXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-mmc-dynamic-extensions) clipboard format, which specifies the non-namespace extension snap-ins that should extend a scope or result item.

## Members

### `count`

The count of GUIDs in the array specified by **guid**.

### `guid`

An array of GUIDs that represent the CLSIDs of the snap-ins that you want to extend the item represented by an **IDataObject** object.

## Remarks

For a snap-in to support dynamic extension of its items with non-namespace extensions (that is, context menu, toolbar, property sheet, or taskpad extensions), the clipboard format CCF_MMC_DYNAMIC_EXTENSIONS must be handled in the snap-in's **IDataObject** implementation. For more information, see
[Dynamic Non-Namespace Extensions](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/dynamic-non-namespace-extensions).

Be aware that the extension snap-in must be a non-namespace extension and the MMC registry entries for the snap-in to be extended as well as the extension snap-in must be set correctly. For details on setting MMC registry entries for extensions, see
[Registration Requirements for Extension Snap-ins](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/registration-requirements-for-extension-snap-ins).

The CCF_MMC_DYNAMIC_EXTENSIONS clipboard format extends only non-namespace extensions. To dynamically add namespace extensions, the snap-in must use the
[IConsoleNameSpace2::AddExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace2-addextension) method. For more information, see
[Dynamic Namespace Extensions](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/dynamic-namespace-extensions).

Just before MMC must use an extensible feature (that is, just before creating and that displays a context menu, property sheet, toolbar, or taskpad), MMC calls **IDataObject::GetDataHere** on the data object for the selected item and asks for dynamic extensions to add through the CCF_MMC_DYNAMIC_EXTENSIONS clipboard format. Based on CLSIDs passed in the
**SMMCDynamicExtensions** structure, MMC attempts to add the specified extensions to the extensible feature. If an extension is unavailable or unregistered, MMC skips that extension and continues to the next CLSID passed in the structure.

## See also

[CCF_MMC_DYNAMIC_EXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-mmc-dynamic-extensions)

[IConsoleNameSpace2::AddExtension](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace2-addextension)

[SMMCObjectTypes](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-smmcobjecttypes)