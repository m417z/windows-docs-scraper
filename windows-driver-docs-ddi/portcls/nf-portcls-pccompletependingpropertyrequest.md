# PcCompletePendingPropertyRequest function

## Description

The **PcCompletePendingPropertyRequest** function is called to complete a pending property request.

## Parameters

### `PropertyRequest` [in]

Pointer to the property request that was passed to the property handler. The request is a structure of type [PCPROPERTY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcproperty_request).

### `NtStatus` [in]

Specifies the completion status of the request. See the list of NTSTATUS values defined in header file ntstatus.h.

## Return value

**PcCompletePendingPropertyRequest** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

If a miniport driver returns STATUS_PENDING from a property handler, it is obliged to keep a pointer to the property-request structure and to complete the request at some later time by calling this function.

The driver should call **PcCompletePendingPropertyRequest** only when the request is no longer pending. Never call this function with an *NtStatus* value of STATUS_PENDING.

## See also

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[PCPROPERTY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcproperty_request)