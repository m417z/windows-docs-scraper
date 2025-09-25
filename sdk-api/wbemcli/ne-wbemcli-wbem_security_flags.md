# WBEM_SECURITY_FLAGS enumeration

## Description

Contains flags used for setting security access levels.

## Constants

### `WBEM_ENABLE:1`

Enables the account and grants the user read permissions. This is a default access right for all users and corresponds to the Enable Account permission on the Security tab of the [WMI Control](https://learn.microsoft.com/windows/desktop/WmiSdk/gloss-w). For more information, see [Setting Namespace Security with the WMI Control](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-namespace-security-with-the-wmi-control).

### `WBEM_METHOD_EXECUTE:2`

Allows the execution of methods.

 Providers can perform additional access checks. This is a default access right for all users and corresponds to the Execute Methods permission on the Security tab of the WMI Control.

### `WBEM_FULL_WRITE_REP:4`

Allows a user account to write to classes in the WMI repository as well as instances. A user cannot write to system classes. Only members of the Administrators group have this permission. **WBEM_FULL_WRITE_REP** corresponds to the Full Write permission on the Security tab of the WMI Control.

### `WBEM_PARTIAL_WRITE_REP:8`

Allows you to write data to instances only, not classes. A user cannot write classes to the [WMI repository](https://learn.microsoft.com/windows/desktop/WmiSdk/gloss-w). Only members of the Administrators group have this right. **WBEM_PARTIAL_WRITE_REP** corresponds to the Partial Write permission on the Security tab of the WMI Control.

### `WBEM_WRITE_PROVIDER:0x10`

Allows writing classes and instances to providers. Note that providers can do additional access checks when impersonating a user. This is a default access right for all users and corresponds to the Provider Write permission on the Security tab of the WMI Control.

### `WBEM_REMOTE_ACCESS:0x20`

Allows a user account to remotely perform any operations allowed by the permissions described above. Only members of the Administrators group have this right. **WBEM_REMOTE_ACCESS** corresponds to the Remote Enable permission on the Security tab of the WMI Control.

### `WBEM_RIGHT_SUBSCRIBE:0x40`

Specifies that a consumer can subscribe to the events delivered to a sink. Used in [IWbemEventSink::SetSinkSecurity](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventsink-setsinksecurity).

### `WBEM_RIGHT_PUBLISH:0x80`

Specifies that the account can publish events to the instance of [__EventFilter](https://learn.microsoft.com/windows/desktop/WmiSdk/--eventfilter) that defines the event filter for a permanent consumer. Available in wbemcli.h.

## See also

[Event Security Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/event-security-constants)

[Namespace Access Rights Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/namespace-access-rights-constants)