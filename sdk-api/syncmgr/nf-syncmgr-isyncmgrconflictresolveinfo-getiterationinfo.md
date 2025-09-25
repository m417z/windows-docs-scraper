# ISyncMgrConflictResolveInfo::GetIterationInfo

## Description

Gets information about which conflict in a set of conflicts is being resolved.

## Parameters

### `pnCurrentConflict` [out]

Type: **UINT***

When this method returns, contains a pointer to the index of the conflict in the set that is being resolved.

### `pcConflicts` [out]

Type: **UINT***

When this method returns, contains a pointer to the number of conflicts that are being resolved.

### `pcRemainingForApplyToAll` [out]

Type: **UINT***

When this method returns, contains a pointer to the number of the remaining conflicts to which an "apply to all" response would be applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.