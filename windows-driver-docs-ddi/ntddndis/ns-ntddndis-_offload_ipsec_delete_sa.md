# _OFFLOAD_IPSEC_DELETE_SA structure

## Description

The OFFLOAD_IPSEC_DELETE_SA structure contains information for each security association (SA) that a
miniport driver deletes from a NIC.

## Members

### `OffloadHandle`

The handle for the SA to be deleted.

## Remarks

The OFFLOAD_IPSEC_DELETE_SA structure is used with the
[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80)) OID.

## See also

[OID_TCP_TASK_IPSEC_DELETE_SA](https://learn.microsoft.com/previous-versions/windows/embedded/gg155485(v=winembedded.80))