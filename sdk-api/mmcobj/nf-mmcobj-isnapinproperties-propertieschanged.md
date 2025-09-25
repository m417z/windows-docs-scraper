# ISnapinProperties::PropertiesChanged

## Description

The
**PropertiesChanged** method is called when a property is added, changed, or deleted. A snap-in can reject the change or deletion by returning E_FAIL.

## Parameters

### `cProperties` [in]

The number of
[MMC_SNAPIN_PROPERTY](https://learn.microsoft.com/windows/desktop/api/mmcobj/ns-mmcobj-mmc_snapin_property) structures provided by *pProperties*.

### `pProperties` [in]

An array of
[MMC_SNAPIN_PROPERTY](https://learn.microsoft.com/windows/desktop/api/mmcobj/ns-mmcobj-mmc_snapin_property) structures.

## Return value

If successful, the return value is **S_OK**; a snap-in can prevent a change or deletion from occurring by returning **E_FAIL**.

## See also

[MMC_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/mmcobj/ne-mmcobj-mmc_property_action)

[MMC_SNAPIN_PROPERTY](https://learn.microsoft.com/windows/desktop/api/mmcobj/ns-mmcobj-mmc_snapin_property)