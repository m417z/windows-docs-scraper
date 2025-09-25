# MMC_SNAPIN_PROPERTY structure

## Description

The
**MMC_SNAPIN_PROPERTY** structure is introduced in MMC 2.0.

The
**MMC_SNAPIN_PROPERTY** structure is used by a snap-in when a property is added, changed, or deleted.

## Members

### `pszPropName`

Name of the property.

### `varValue`

The property's value; if the property is being changed, this is the new value.

### `eAction`

The action taking place on the property, as defined in
[MMC_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/mmcobj/ne-mmcobj-mmc_property_action).

## See also

[ISnapinProperties::PropertiesChanged](https://learn.microsoft.com/windows/desktop/api/mmcobj/nf-mmcobj-isnapinproperties-propertieschanged)

[MMC_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/mmcobj/ne-mmcobj-mmc_property_action)