# WBEM_UNSECAPP_FLAG_TYPE enumeration

## Description

Used to control access checks on callbacks when using the [IWbemUnsecuredApartment::CreateSinkStub](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemunsecuredapartment-createsinkstub) method.

## Constants

### `WBEM_FLAG_UNSECAPP_DEFAULT_CHECK_ACCESS:0`

Unsecapp.exe reads the registry key UnsecAppAccessControlDefault to determine if it should authenticate callbacks.

### `WBEM_FLAG_UNSECAPP_CHECK_ACCESS:1`

Unsecapp.exe authenticates callbacks regardless of the setting of the registry key UnsecAppAccessControlDefault.

### `WBEM_FLAG_UNSECAPP_DONT_CHECK_ACCESS:2`

Unsecapp.exe does not authenticate callbacks regardless of the setting of the registry key UnsecAppAccessControlDefault.