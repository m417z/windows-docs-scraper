# EALocationCodeType structure

## Description

The EALocationCodeType structure defines an Emergency Alert (EA) location code, as defined in ANSI/SCTE 28.

## Members

### `LocationCodeScheme`

Identifies the standard that shall be used to interpret the other members of this structure. Currently this value must be SCTE_18, meaning SCTE 18, "Emergency Alert Message for Cable."

### `state_code`

Contains the state_code field.

### `county_subdivision`

Contains the county_subdivision field.

### `county_code`

Contains the county_code field.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)