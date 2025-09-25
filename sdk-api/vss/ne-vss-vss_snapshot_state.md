# VSS_SNAPSHOT_STATE enumeration

## Description

The **VSS_SNAPSHOT_STATE** enumeration is returned by a
provider to specify the state of a given shadow copy operation.

## Constants

### `VSS_SS_UNKNOWN:0`

Reserved for system use.

Unknown shadow copy state.

### `VSS_SS_PREPARING`

Reserved for system use.

Shadow copy is being prepared.

### `VSS_SS_PROCESSING_PREPARE`

Reserved for system use.

Processing of the shadow copy preparation is in progress.

### `VSS_SS_PREPARED`

Reserved for system use.

Shadow copy has been prepared.

### `VSS_SS_PROCESSING_PRECOMMIT`

Reserved for system use.

Processing of the shadow copy precommit is in process.

### `VSS_SS_PRECOMMITTED`

Reserved for system use.

Shadow copy is precommitted.

### `VSS_SS_PROCESSING_COMMIT`

Reserved for system use.

Processing of the shadow copy commit is in process.

### `VSS_SS_COMMITTED`

Reserved for system use.

Shadow copy is committed.

### `VSS_SS_PROCESSING_POSTCOMMIT`

Reserved for system use.

Processing of the shadow copy postcommit is in process.

### `VSS_SS_PROCESSING_PREFINALCOMMIT`

Reserved for system use.

Processing of the shadow copy file commit operation is underway.

### `VSS_SS_PREFINALCOMMITTED`

Reserved for system use.

Processing of the shadow copy file commit operation is done.

### `VSS_SS_PROCESSING_POSTFINALCOMMIT`

Reserved for system use.

Processing of the shadow copy following the final commit and prior to shadow copy create is underway.

### `VSS_SS_CREATED`

Shadow copy is created.

### `VSS_SS_ABORTED`

Reserved for system use.

Shadow copy creation is aborted.

### `VSS_SS_DELETED`

Reserved for system use.

Shadow copy has been deleted.

### `VSS_SS_POSTCOMMITTED`

### `VSS_SS_COUNT`

Reserved value.

## Remarks

The shadow copy state is contained in the **m_eStatus** member of a
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) object, which can be obtained for a
single shadow copy by calling
[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties).

Because
[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties)
fails during shadow copy creation with **VSS_E_OBJECT_NOT_FOUND**, a requester cannot obtain
any **VSS_SNAPSHOT_STATE** value other than
**VSS_SS_CREATED**.

Calls to [IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query) can
also be used to obtain the shadow copy state.
**IVssBackupComponents::Query** is used to return
lists of shadow copies, which may be iterated over by means of the
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface to obtain
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) objects for each shadow copy that
have completed on a given system. This means that, like
[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties),
the **IVssBackupComponents::Query** method can
return only a shadow copy state of **VSS_SS_CREATED**.

## See also

[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties)

[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)

[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)