# WS_FAULT_DETAIL_DESCRIPTION structure

## Description

A description of the detail element of a fault message.

## Members

### `action`

The action associated with the fault message.

If the message does not have an action, this field can be **NULL**.

### `detailElementDescription`

The description of the fault detail of the fault. This
field must be specified (it may not be **NULL**).

## Remarks

The fault description defines the action of the fault message
along with a description of the detail element that is
contained within the fault.

The fault description can be used to set and get the
fault detail element stored within a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object
using [WsSetFaultErrorDetail](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetfaulterrordetail) and [WsGetFaultErrorDetail](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetfaulterrordetail).