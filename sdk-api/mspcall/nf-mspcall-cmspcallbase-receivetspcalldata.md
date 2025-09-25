# CMSPCallBase::ReceiveTSPCallData

## Description

The
**ReceiveTSPCallData** method is called by the MSP address object's
[ReceiveTSPData](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-receivetspdata) method to dispatch TSP data to the correct call. The call object should override this method to handle the TSP data according to whatever semantics have been defined for communication between this particular MSP and its corresponding TSP. The default implementation simply returns S_OK, which is sufficient for an MSP that does not handle any per-call TSP data.

## Parameters

### `pBuffer`

Pointer to buffer containing TSP data.

### `dwSize`

Size of the buffer, in bytes.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)