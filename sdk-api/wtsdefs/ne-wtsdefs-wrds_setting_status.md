# WRDS_SETTING_STATUS enumeration

## Description

Specifies the status of a policy setting for various members of the [WRDS_SETTINGS_1](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings_1) structure.

## Constants

### `WRDS_SETTING_STATUS_NOTAPPLICABLE:-1`

The setting status has not been defined.

### `WRDS_SETTING_STATUS_DISABLED`

The setting is disabled.

### `WRDS_SETTING_STATUS_ENABLED`

The setting is enabled.

### `WRDS_SETTING_STATUS_NOTCONFIGURED`

The setting is not configured.

## Remarks

The three primary values (disabled, enabled, and not configured) correspond to the states that are available when defining rules in the group policy editor. When the setting status is enabled, the value of the setting can be changed by the corresponding value member within the [WRDS_SETTINGS_1](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings_1) structure. For example, if that structure's **WRdsColorDepthStatus** member has a value of **WRDS_SETTING_STATUS_ENABLED**, the **WRdsColorDepthValue** member will go into effect. Otherwise, the value member is not used in processing.