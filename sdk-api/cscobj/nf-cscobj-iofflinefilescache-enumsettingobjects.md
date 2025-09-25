# IOfflineFilesCache::EnumSettingObjects

## Description

Creates an enumerator of instances of [IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting). This allows the caller to enumerate all of the available settings that affect the behavior of Offline Files.

## Parameters

### `ppEnum` [out]

On success, receives the address of an instance of [IEnumOfflineFilesSettings](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-ienumofflinefilessettings).

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

A known setting may be retrieved by name using [IOfflineFilesCache::GetSettingObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-getsettingobject).

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)