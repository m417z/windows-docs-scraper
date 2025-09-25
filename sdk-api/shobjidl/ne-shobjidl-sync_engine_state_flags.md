# SYNC_ENGINE_STATE_FLAGS enumeration

## Description

Specifies values used by any sync engine to expose their internal engine states to the Property Store's PKEY_StorageProviderStatus value in the File Indexer

To update the property, first call [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) with the [GPS_EXTRINSICPROPERTIES](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) flag. Next, call the [IPropertyStore::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761475(v=vs.85)) method of the returned object, specifying the PKEY_StorageProviderStatus key, to set the property's bitmask value using these SYNC_ENGINE_STATE_FLAGS.

## Constants

### `SESF_NONE:0`

No state.

### `SESF_SERVICE_QUOTA_NEARING_LIMIT:0x1`

The user's cloud storage quota is nearing capacity. This is dependent on the user's total quota space.

### `SESF_SERVICE_QUOTA_EXCEEDED_LIMIT:0x2`

The user's cloud storage quota is filled.

### `SESF_AUTHENTICATION_ERROR:0x4`

The user's account credentials are invalid.

### `SESF_PAUSED_DUE_TO_METERED_NETWORK:0x8`

The sync engine is paused because of metered network settings.

### `SESF_PAUSED_DUE_TO_DISK_SPACE_FULL:0x10`

The drive that contains the sync engine's content has reached the maximum allowed space.

### `SESF_PAUSED_DUE_TO_CLIENT_POLICY:0x20`

The user has exceeded their daily limit of requests or data transfers to the service.

### `SESF_PAUSED_DUE_TO_SERVICE_POLICY:0x40`

The service has requested the system to throttle requests.

### `SESF_SERVICE_UNAVAILABLE:0x80`

The service can't be reached at this time.

### `SESF_PAUSED_DUE_TO_USER_REQUEST:0x100`

### `SESF_ALL_FLAGS`

A bitmask value for all valid SYNC_ENGINE_STATE_FLAGS flags.