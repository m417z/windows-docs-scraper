# WBEM_FLAVOR_TYPE enumeration

## Description

Lists qualifier flavors.

## Constants

### `WBEM_FLAVOR_DONT_PROPAGATE:0`

The qualifier is not propagated to instances or derived classes.

### `WBEM_FLAVOR_FLAG_PROPAGATE_TO_INSTANCE:0x1`

The qualifier is propagated to instances.

### `WBEM_FLAVOR_FLAG_PROPAGATE_TO_DERIVED_CLASS:0x2`

The qualifier is propagated to derived classes. This flavor is only appropriate for qualifiers defined for a class and cannot be attached to a qualifier describing a class instance.

### `WBEM_FLAVOR_MASK_PROPAGATION:0xf`

### `WBEM_FLAVOR_OVERRIDABLE:0`

When propagated to a derived class or instance, the value of the qualifier can be overridden. Setting EnableOverride is optional because being able to override the qualifier value is the default functionality for propagated qualifiers.

### `WBEM_FLAVOR_NOT_OVERRIDABLE:0x10`

The qualifier cannot be overridden in a derived class or instance. Note that being able to override a propagated qualifier is the default.

### `WBEM_FLAVOR_MASK_PERMISSIONS:0x10`

### `WBEM_FLAVOR_ORIGIN_LOCAL:0`

For a class: the property belongs to the derived-most class.

For an instance: the property is modified at the instance level (that is, either a value was supplied or a qualifier was added/modified).

### `WBEM_FLAVOR_ORIGIN_PROPAGATED:0x20`

For a class: The property was inherited from the parent class.

For an instance: The property, while inherited from the parent class, has not been modified at the instance level.

### `WBEM_FLAVOR_ORIGIN_SYSTEM:0x40`

The property is a standard system property.

### `WBEM_FLAVOR_MASK_ORIGIN:0x60`

### `WBEM_FLAVOR_NOT_AMENDED:0`

### `WBEM_FLAVOR_AMENDED:0x80`

The qualifier is not required in the basic class definition and can be moved to the amendment to be localized.

### `WBEM_FLAVOR_MASK_AMENDED:0x80`

## See also

[IWbemQualifierSet::Put](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-put)

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)