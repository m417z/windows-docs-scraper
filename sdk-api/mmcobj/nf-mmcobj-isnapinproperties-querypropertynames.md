# ISnapinProperties::QueryPropertyNames

## Description

The
**QueryPropertyNames** method returns the names of the properties used for the snap-in's configuration.

## Parameters

### `pCallback` [in]

A pointer to the
[ISnapinPropertiesCallback](https://learn.microsoft.com/windows/desktop/api/mmcobj/nn-mmcobj-isnapinpropertiescallback) interface; the snap-in can call
[ISnapinPropertiesCallback::AddPropertyName](https://learn.microsoft.com/windows/desktop/api/mmcobj/nf-mmcobj-isnapinpropertiescallback-addpropertyname) to add the properties.

## Return value

If successful, the return value is S_OK; otherwise, the return value is an error code.