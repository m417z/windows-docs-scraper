# CF_CALLBACK_REGISTRATION structure

## Description

The callbacks to be registered by the sync provider.

## Members

### `Type`

The type of callback to be registered. See [CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type).

### `Callback`

A pointer to the callback function.

## Remarks

This callback registration is how a sync provider communicates to the library which functions to call to execute various requests from the platform.

Note that the sync provider only needs to register implemented callbacks, and **CF_CALLBACK_REGISTRATION** should always end with **CF_CALLBACK_REGISTRATION_END**.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)