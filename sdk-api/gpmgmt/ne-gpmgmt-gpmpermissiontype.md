# GPMPermissionType enumeration

## Description

GPMPermissionType defines the categories, permissions included in the categories, and the object to which they can be applied.

## Constants

### `permGPOApply:0x10000`

The trustee can apply the GPO; corresponds to the READ and APPLY Group Policy access rights being set to "Allow" for a user.

### `permGPORead:0x10100`

The trustee can read the GPO; corresponds to the READ Group Policy access right set to "Allow" for a user.

### `permGPOEdit:0x10101`

The trustee can read and edit the policy settings for the GPO; corresponds to the READ, WRITE, CREATE CHILD OBJECT, and DELETE CHILD OBJECT Group Policy access rights set to "Allow" for a user.

### `permGPOEditSecurityAndDelete:0x10102`

The trustee can read, edit and delete the permissions for the GPO; corresponds to the Group Policy access rights specified by **permGPOEdit** plus the DELETE, MODIFY PERMISSIONS, and MODIFY OWNER access rights set to "Allow" for a user.

### `permGPOCustom:0x10103`

The trustee has custom permissions for the GPO.

### `permWMIFilterEdit:0x20000`

The trustee can edit the WMI filter.

### `permWMIFilterFullControl:0x20001`

The trustee has full control over the WMI filter.

### `permWMIFilterCustom:0x20002`

The trustee has custom permissions for the WMI filter.

### `permSOMLink:0x1c0000`

he trustee can link GPOs to the SOM. Applies to sites, domains and OUs.

### `permSOMLogging:0x180100`

The trustee can generate RSoP logging data for the SOM. Applies to domains and OUs.

### `permSOMPlanning:0x180200`

The trustee can generate RSoP planning data for the SOM. Applies to domains and OUs.

### `permSOMWMICreate:0x100300`

The trustee can create WMI filters in the domain. Applies to domains only.

### `permSOMWMIFullControl:0x100301`

The trustee has full control over all WMI filters in the domain. Applies to domains only.

### `permSOMGPOCreate:0x100400`

The trustee can create GPOs in the domain. Applies to domains only.

### `permStarterGPORead:0x30500`

The trustee can read the Starter GPO; corresponds to the READ Group Policy access right set to "Allow" for a user.

### `permStarterGPOEdit:0x30501`

The trustee can read and edit the administrative template policy settings for the Starter GPO; corresponds to the READ, WRITE, CREATE CHILD OBJECT, and DELETE CHILD OBJECT Group Policy access rights set to "Allow" for a user.

### `permStarterGPOFullControl:0x30502`

The trustee has full control for the Starter GPO. Applies to domains only.

### `permStarterGPOCustom:0x30503`

The trustee has custom permissions for the Starter GPO.

### `permSOMStarterGPOCreate:0x100500`

The trustee can create Starter GPOs in the domain. Applies to domains only.