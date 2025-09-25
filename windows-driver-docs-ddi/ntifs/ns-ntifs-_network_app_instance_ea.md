# _NETWORK_APP_INSTANCE_EA structure

## Description

An Extended Attribute (EA) structure for processes using Server Message Block (SMB) Cluster Client Failover.

## Members

### `AppInstanceID`

A GUID that identifies a single application instance, or a **NETWORK_APP_INSTANCE_EA** structure when the application additionally contains a flag for **CsvFlags**.

### `CsvFlags`

An optional flag:
`NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR (0x00000001)`

The **NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR** flag is only used when the file is opened directly from CSVFS. This flag is ignored when the file is opened using the SMB protocol. The flag notifies CSVFS that the file only be opened on the coordinating node. If an ‘open’ request is sent to CSVFS and the node is non-coordinating, then the open will fail. Additionally, if the coordinating node is moved while the file is opened, the file open would be invalidated.

## Remarks

A process can register a CCF application ID using [**RegisterAppInstance**](https://learn.microsoft.com/windows/win32/api/smbclnt/nf-smbclnt-registerappinstance), enabling all 'open' operations from the process to have the same ApplicationId. If an ID isn't registered, the ApplicationId will differ for each operation.

To mark individual open operations with a different ApplicationId, first set **AppInstanceID** to a GUID value. you can then append **SMB_CCF_APP_INSTANCE_EA_NAME** to the list of Extended Attributes when calling [NtCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile). If the application also passes the **NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR** flag, then **AppInstanceID** should be **NETWORK_APP_INSTANCE_EA** structure.