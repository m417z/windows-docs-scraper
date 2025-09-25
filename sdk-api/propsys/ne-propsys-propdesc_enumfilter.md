# PROPDESC_ENUMFILTER enumeration

## Description

Describes the filtered list of property descriptions that is returned.

## Constants

### `PDEF_ALL:0`

The list contains all property descriptions in the system.

### `PDEF_SYSTEM:1`

The list contains system property descriptions only. It excludes third-party property descriptions that are registered on the computer.

### `PDEF_NONSYSTEM:2`

The list contains only third-party property descriptions that are registered on the computer.

### `PDEF_VIEWABLE:3`

The list contains only viewable properties, where <typeInfo isViewable="true">.

### `PDEF_QUERYABLE:4`

Deprecated in **Windows 7 and later**. The list contains only queryable properties, where <typeInfo isViewable="true" isQueryable="true">.

### `PDEF_INFULLTEXTQUERY:5`

**Deprecated in Windows 7 and later**. The list contains only properties to be included in full-text queries.

### `PDEF_COLUMN:6`

The list contains only properties that are columns.

## Remarks

These values are defined in propsys.h and propsys.idl.