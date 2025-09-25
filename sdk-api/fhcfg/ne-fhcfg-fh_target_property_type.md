# FH_TARGET_PROPERTY_TYPE enumeration

## Description

Specifies the type of a property of a backup target.

## Constants

### `FH_TARGET_NAME:0`

The property is a string that contains the backup target’s friendly name. The friendly name is set during target provisioning by calling the [IFhConfigMgr::ProvisionAndSetNewTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-provisionandsetnewtarget) method.

### `FH_TARGET_URL`

The property is a string that contains a path to the backup target.

### `FH_TARGET_DRIVE_TYPE`

The property is a numeric property that specifies the target type of the backup target. See the [FH_TARGET_DRIVE_TYPES](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_drive_types) enumeration for the list of possible backup target types.

### `MAX_TARGET_PROPERTY`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## Remarks

To query a backup target property, call the [IFhTarget::GetStringProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getstringproperty) method or the [IFhTarget::GetNumericalProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getnumericalproperty) method.

For local disks, the **FH_TARGET_URL** property contains the drive letter. This path must end with a trailing backslash (for example, "X:\\").

For network shares, the **FH_TARGET_URL** property contains the full path of the share. This path must end with a trailing backslash (for example, "\\\\myserver\myshare\\").

## See also

[FH_TARGET_DRIVE_TYPES](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_drive_types)

[IFhConfigMgr::ProvisionAndSetNewTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-provisionandsetnewtarget)

[IFhTarget::GetNumericalProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getnumericalproperty)

[IFhTarget::GetStringProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getstringproperty)