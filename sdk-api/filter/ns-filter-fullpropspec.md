# FULLPROPSPEC structure

## Description

Specifies a property set and a property within the property set.

## Members

### `guidPropSet`

The globally unique identifier (GUID) that identifies the property set.

### `psProperty`

A pointer to the [PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec) structure that specifies a property either by its property identifier (propid) or by the associated string name (**lpwstr**).

## See also

[IFilter::Init](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-init)