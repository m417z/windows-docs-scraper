# IASDOMAINTYPE enumeration

## Description

The values of the
**IASDOMAINTYPE** enumeration type specify whether the SDO computer is part of a domain, and if so, what type of domain.

## Constants

### `DOMAIN_TYPE_NONE:0`

The SDO computer is running in stand-alone mode.

### `DOMAIN_TYPE_NT4`

Not supported.

### `DOMAIN_TYPE_NT5`

The SDO computer is part of a Windows domain running in native mode.

### `DOMAIN_TYPE_MIXED`

The SDO computer is part of a Windows domain running in mixed mode.

## See also

[IASOSTYPE](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iasostype)

[ISdoMachine::GetDomainType](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getdomaintype)