# tagWNODE_TOO_SMALL structure

## Description

The **WNODE_TOO_SMALL** structure indicates the size of the buffer needed to receive output from a request.

## Members

### `WnodeHeader`

Is a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `SizeNeeded`

Specifies the size of the buffer needed to receive all of the **WNODE_*XXX*** data to be returned.

## Remarks

When the buffer for a WMI request is too small to receive all of the data to be returned, a driver fills in a **WNODE_TOO_SMALL** structure to indicate the required buffer size. WMI can then increase the buffer to the recommended size and issue the request again. A driver is responsible for managing any side effects caused by handling the same request more than once.

## See also

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)