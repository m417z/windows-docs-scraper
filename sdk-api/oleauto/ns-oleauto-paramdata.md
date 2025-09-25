# PARAMDATA structure

## Description

Describes a parameter accepted by a method or property.

## Members

### `szName`

The parameter name. Names should follow standard conventions for programming language access; that is, no embedded spaces or control characters, and 32 or fewer characters. The name should be localized because each type description provides names for a particular locale.

### `vt`

The parameter type. If more than one parameter type is accepted, VT_VARIANT should be specified.