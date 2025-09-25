# GPMSearchProperty enumeration

## Description

**GPMSearchProperty** defines the property of the search criteria.

The property of the search criteria.

```cpp
typedef enum {gpoPermissions, gpoEffectivePermissions, gpoDisplayName, gpoWMIFilter, gpoID,
              gpoComputerExtensions, gpoUserExtensions, somLinks, gpoDomain, backupMostRecent,
              starterGPOPermissions, starterGPOEffectivePermissions, starterGPODisplayName, starterGPOID,
              starterGPODomain} GPMSearchProperty;
```

## Constants

### `gpoPermissions:0`

The specified level of permission for a Group Policy Object.

### `gpoEffectivePermissions`

A specific set of permissions, whether the permissions are explicitly set or derived as a result of group membership.

### `gpoDisplayName`

Display name of a Group Policy object.

### `gpoWMIFilter`

Display name of a WMI filter.

### `gpoID`

GUID of a Group Policy object.

### `gpoComputerExtensions`

Computer client-side extension

### `gpoUserExtensions`

user client-side extension

### `somLinks`

Scope of Management (SOM) that link to a Group Policy object.

### `gpoDomain`

domain name

### `backupMostRecent`

The most recent backup

### `starterGPOPermissions`

The specified level of permission for a Starter Group Policy Object.

### `starterGPOEffectivePermissions`

A specific set of permissions, whether the permissions are explicitly set or derived as a result of group membership.

### `starterGPODisplayName`

Display name of a Starter Group Policy object.

### `starterGPOID`

GUID of a Starter Group Policy object.

### `starterGPODomain`

domain name