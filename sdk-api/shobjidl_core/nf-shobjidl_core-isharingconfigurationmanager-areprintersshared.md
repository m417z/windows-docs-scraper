# ISharingConfigurationManager::ArePrintersShared

## Description

Determines whether any printers connected to this computer are shared.

## Return value

Type: **HRESULT**

Returns standard HRESULT values, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Shared printers were detected. |
| **S_FALSE** | No shared printers were found. |
| **ERROR_FILE_NOT_FOUND** | No printers capable of being shared were found. |