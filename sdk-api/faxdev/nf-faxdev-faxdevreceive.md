# FaxDevReceive function

## Description

The fax service calls the **FaxDevReceive** function to signal an incoming fax transmission to the fax service provider (FSP). Each FSP must export the **FaxDevReceive** function.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

### `CallHandle` [in]

Type: **HCALL**

Specifies a TAPI call handle. Note that the FSP should use this handle for all call operations, but should never close this handle. If *CallHandle* is set to **NULL**, the service requests that the FSP start receiving a fax without receiving a ring on the line. This may occur in the case when you answer the call, then realize that it's a fax call, or when you want to receive a fax during an existing call (fax polling). If the FSP does not support this option, it should return with an error. If the FSP supports this option, it should pick up the device's line and start receiving a fax.

### `FaxReceive` [in, out]

Type: **PFAX_RECEIVE**

Pointer to a [FAX_RECEIVE](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_receive) structure that contains information about an incoming fax document. Upon return, the structure also contains the **ReceiverName** and **ReceiverNumber** members.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service calls the **FaxDevReceive** function after a TAPI line device associated with the FSP rings, and the line is in the *offering* state. For information on call states, see [State](https://learn.microsoft.com/windows/desktop/Tapi/state-ovr) in the TAPI documentation.

The FSP must respond to the **FaxDevReceive** function by receiving the incoming fax document. The FSP must accept the incoming call through TAPI, and then receive the fax data stream. The FSP should store the data stream in the file specified by the **FileName** member of the [FAX_RECEIVE](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_receive) structure that is passed into the **FaxDevReceive** function. This file is a Tagged Image File Format Class F (TIFF Class F) file. For more information, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format).

The FSP should set the **ReceiverName** and **ReceiverNumber** members in the [FAX_RECEIVE](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_receive) structure pointed to by the *FaxReceive* parameter. The fax service allocates the memory for these strings. The size of the memory the service allocates is equal to **sizeof(FAX_RECEIVE) + FAXDEVRECEIVE_SIZE**. The FSP must place the strings in the block of memory that follows the **FAX_RECEIVE** structure. The **ReceiverName** and **ReceiverNumber** members must point to the location of the strings in the memory block. For a code sample and diagram that illustrate how to fill in the memory that the fax service allocates, see **FAX_RECEIVE**.

**Note** The fax service will attempt to restore partially received faxes if the FSP reports any [extended status](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) other than **FS_USER_ABORT**. Otherwise, the fax service will discard partially received faxes.

## See also

[FAX_RECEIVE](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_receive)

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)