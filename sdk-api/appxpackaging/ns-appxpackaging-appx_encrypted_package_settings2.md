# APPX_ENCRYPTED_PACKAGE_SETTINGS2 structure

## Description

Encrypted Windows app package settings. This structure expands on [APPX_ENCRYPTED_PACKAGE_SETTINGS](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ns-appxpackaging-appx_encrypted_package_settings).

## Members

### `keyLength`

The key length.

### `encryptionAlgorithm`

The encryption algorithm used.

### `blockMapHashAlgorithm`

The Uri of the block map hash algorithm.

### `options`

Additional options for encrypted packages. Options come from the [APPX_ENCRYPTED_PACKAGE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_encrypted_package_options) enum.