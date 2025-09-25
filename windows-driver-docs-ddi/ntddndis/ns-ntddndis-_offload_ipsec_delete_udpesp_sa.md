# _OFFLOAD_IPSEC_DELETE_UDPESP_SA structure

## Description

The OFFLOAD_IPSEC_DELETE_UDPESP_SA structure contains information for each security association (SA)
and parser entry that a miniport driver deletes from a NIC.

## Members

### `OffloadHandle`

The handle for the SA to be deleted.

### `EncapTypeEntryOffldHandle`

When **NULL**, the miniport does not have to delete a parser entry in addition to the specified SA.
When non-**NULL**, this member specifies the handle for the parser entry to be deleted.

## Remarks

The OFFLOAD_IPSEC_DELETE_UDPESP_SA structure is used with the
[OID_TCP_TASK_IPSEC_DELETE_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa) OID.

## See also

[OID_TCP_TASK_IPSEC_DELETE_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-add-udpesp-sa)