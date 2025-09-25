# RxSetSrvCallDomainName function

## Description

**RxSetSrvCallDomainName** is called by a network mini-redirector driver to set the domain name associated with any given server (SRV_CALL structure).

## Parameters

### `SrvCall` [in]

A pointer to the SRV_CALL structure.

### `DomainName` [in]

A pointer to a buffer containing a zero-terminated Unicode string that names the domain to which this server belongs.

## Return value

**RxSetSrvCallDomainName** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete this routine. The memory allocation request failed for nonpaged pool memory to store the new domain name. |

## Remarks

The domain name may not be known at the beginning of a network redirector request. The **RxSetSrvCallDomainName** routine allows the domain name to be associated with *SrvCall* once it is known. This routine would normally be used as part of the creation and initialization of a SRV_CALL structure.

If a domain name is already associated with the *SrvCall* parameter, then this domain name will be removed and the memory associated with this entry in *SrvCall* will be freed.

If the *DomainName* parameter is not a **NULL** pointer, and the *DomainName* parameter has a length greater than zero, then **RxSetSrvCallDomainName** allocates space for the **pDomainName** member of *SrvCall* from nonpaged pool with a pool tag of RX_SRVCALL_PARAMS_POOLTAG. The **RxSetSrvCallDomainName** routine sets the **buffer**, **length**, and **MaximumLength** members of the **pDomainName** structure.

## See also

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)