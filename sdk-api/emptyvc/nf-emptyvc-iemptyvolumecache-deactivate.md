# IEmptyVolumeCache::Deactivate

## Description

Notifies the handler that the disk cleanup manager is shutting down.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

A flag that can be set to return information to the disk cleanup manager. It can have the following value.

#### EVCF_REMOVEFROMLIST

If this flag is set, the disk cleanup manager will delete the handler's registry subkey.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | This value should always be returned. |

## Remarks

If the **EVCF_REMOVEFROMLIST** flag is set, the handler will not be run again unless the registry entries are reestablished. This flag is typically used for a handler that will only run once.