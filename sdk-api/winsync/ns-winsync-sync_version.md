# SYNC_VERSION structure

## Description

Represents a version for an item or a change unit.

## Members

### `dwLastUpdatingReplicaKey`

The replica key that is associated with the version.

### `ullTickCount`

The tick count that is associated with the version.

## Remarks

A change that is made directly to a replica, such as a change that is made by a local application, will not have a version for the change in the synchronization metadata. A version that is created for such a change must contain the following elements:

* The replica key of the local replica. This will typically be zero.
* The current value of the tick count of the local replica.

## See also

[IEnumClockVector::Next Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-ienumclockvector-next)

[IForgottenKnowledge::ForgetToVersion Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iforgottenknowledge-forgettoversion)

[ISyncChange::GetChangeVersion Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchange-getchangeversion)

[ISyncChange::GetCreationVersion Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchange-getcreationversion)

[ISyncChangeBatchBase::AddItemMetadataToGroup Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebatchbase-additemmetadatatogroup)

[ISyncChangeBuilder::AddChangeUnitMetadata Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebuilder-addchangeunitmetadata)

[ISyncChangeUnit::GetChangeUnitVersion Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangeunit-getchangeunitversion)

[ISyncKnowledge::ContainsChange Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-containschange)

[ISyncKnowledge::ContainsChangeUnit Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-containschangeunit)

[ISyncKnowledge::ConvertVersion Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-convertversion)

[Windows Sync Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-structures)