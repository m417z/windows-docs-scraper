# ISnapinPropertiesCallback::AddPropertyName

## Description

The
**AddPropertyName** method adds a property, by name, for the snap-in to use.

## Parameters

### `pszPropName` [in]

The property name.

### `dwFlags` [in]

This parameter can be one or more of the following flags.

#### MMC_PROP_CHANGEAFFECTSUI

If modified, the property affects the user interface.

#### MMC_PROP_MODIFIABLE

The property can be modified.

#### MMC_PROP_REMOVABLE

The property can be deleted.

#### MMC_PROP_PERSIST

The property can be saved.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.