# ENHANCED_STORAGE_PASSWORD_SILO_INFORMATION structure

## Description

The **ENHANCED_STORAGE_PASSWORD_SILO_INFORMATION** structure contains data that defines the capabilities and requirements of a password silo.

## Members

### `CurrentAdminFailures`

This is the current number of consecutive unsuccessful authentication attempts using administrator password. This value is reset to 0 after a successful authentication.

### `CurrentUserFailures`

This is the current number of consecutive unsuccessful authentication attempts using user password. This value is reset to 0 after a successful authentication.

### `TotalUserAuthenticationCount`

Total number of authentication attempts attempted on this silo using the user password.

### `TotalAdminAuthenticationCount`

Total number of authentication attempts attempted on this silo using the administrator password.

### `FipsCompliant`

**TRUE** if the silo claims compliance with the Federal Information Processing Standard (FIPS); otherwise, **FALSE**.

### `SecurityIDAvailable`

**TRUE** if a device-unique security identifier provided by the manufacturer is available; otherwise, **FALSE**.

### `InitializeInProgress`

**TRUE** if an initialization is in progress; otherwise, **FALSE**.

### `ITMSArmed`

**TRUE** if the silo is set to prepare for initialization to the default state set by the manufacturer; otherwise, **FALSE**.

### `ITMSArmable`

**TRUE** if the silo is capable of initializing to the default state set by the manufacturer; otherwise, **FALSE**.

### `UserCreated`

**TRUE** if the user account has been created in the password silo; otherwise, **FALSE**.

### `ResetOnPORDefault`

**TRUE** if the silo resets Administrator authentication failure count to zero upon power cycle. This is the default behavior for the silo.
If **FALSE**, the silo will not reset Administrator authentication failure count to zero upon power cycle.

### `ResetOnPORCurrent`

**TRUE** if the silo is currently set to reset Administrator authentication failure count to zero upon power cycle; Otherwise **FALSE**.
This configuration is affected by changes introduced by the host or the implementation of factory default settings.

### `MaxAdminFailures`

This is the maximum number of consecutive unsuccessful authentication attempts using administrator password allowed by the silo before it will block the administrator.

### `MaxUserFailures`

This is the maximum number of consecutive unsuccessful authentication attempts using user password allowed by the silo before it will block user.

### `TimeToCompleteInitialization`

Estimated time (in milliseconds) for the device to complete the initialize to manufacturing function.

### `TimeRemainingToCompleteInitialization`

Time remaining (in milliseconds) for the silo to complete the initialize to manufacturing function. The value of this field is zero if the silo is currently not in the process of initialization.

### `MinTimeToAuthenticate`

Minimum time (in milliseconds) the silo will require to complete an authentication operation.

### `MaxAdminPasswordSize`

This is the maximum number of bytes that the silo supports for administrator password.

### `MinAdminPasswordSize`

This is the minimum number of bytes that the silo requires for administrator password.

### `MaxAdminHintSize`

This is the maximum number of bytes that the silo supports for administrator password hint.

### `MaxUserPasswordSize`

This is the maximum number of bytes that the silo supports for user password.

### `MinUserPasswordSize`

This is the minimum number of bytes that the silo requires for user password.

### `MaxUserHintSize`

This is the maximum number of bytes that the silo supports for user password hint.

### `MaxUserNameSize`

This is the maximum number of bytes that the silo supports for friendly user name.

### `MaxSiloNameSize`

The maximum number of bytes that the silo supports for the silo name.

### `MaxChallengeSize`

The maximum number of bytes that the device supports for challenge.

## See also

[Enhanced Storage Portable Device Commands](https://learn.microsoft.com/previous-versions/windows/desktop/enstor/enhanced-storage-portable-device-commands)