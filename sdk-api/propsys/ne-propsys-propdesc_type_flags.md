# PROPDESC_TYPE_FLAGS enumeration

## Description

Describes attributes of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## Constants

### `PDTF_DEFAULT:0`

The property uses the default values for all attributes.

### `PDTF_MULTIPLEVALUES:0x1`

The property can have multiple values. These values are stored as a VT_VECTOR in the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. This value is set by the *multipleValues* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_ISINNATE:0x2`

This flag indicates that a property is read-only, and cannot be written to. This value is set by the *isInnate* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_ISGROUP:0x4`

The property is a group heading. This value is set by the *isGroup* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_CANGROUPBY:0x8`

The user can group by this property. This value is set by the *canGroupBy* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_CANSTACKBY:0x10`

The user can stack by this property. This value is set by the *canStackBy* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_ISTREEPROPERTY:0x20`

This property contains a hierarchy. This value is set by the *isTreeProperty* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_INCLUDEINFULLTEXTQUERY:0x40`

**Deprecated in Windows 7 and later**. Include this property in any full text query that is performed. This value is set by the *includeInFullTextQuery* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_ISVIEWABLE:0x80`

This property is meant to be viewed by the user. This influences whether the property shows up in the "Choose Columns" dialog box, for example. This value is set by the *isViewable* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_ISQUERYABLE:0x100`

**Deprecated in Windows 7 and later**. This property is included in the list of properties that can be queried. A queryable property must also be viewable. This influences whether the property shows up in the query builder UI. This value is set by the *isQueryable* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

### `PDTF_CANBEPURGED:0x200`

**Windows Vista with Service Pack 1 (SP1) and later**. Used with an innate property (that is, a value calculated from other property values) to indicate that it can be deleted. This value is used by the **Remove Properties** UI to determine whether to display a check box next to a property that enables that property to be selected for removal. Note that a property that is not innate can always be purged regardless of the presence or absence of this flag.

### `PDTF_SEARCHRAWVALUE:0x400`

**Windows 7 and later**. The unformatted (raw) property value should be used for searching.

### `PDTF_DONTCOERCEEMPTYSTRINGS:0x800`

### `PDTF_ALWAYSINSUPPLEMENTALSTORE:0x1000`

### `PDTF_ISSYSTEMPROPERTY:0x80000000`

This property is owned by the system.

### `PDTF_MASK_ALL:0x80001fff`

A mask used to retrieve all flags.

## Remarks

These values are defined in propsys.h and propsys.idl.