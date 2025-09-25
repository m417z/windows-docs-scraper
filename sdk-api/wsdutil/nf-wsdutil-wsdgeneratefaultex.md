# WSDGenerateFaultEx function

## Description

Generates a SOAP fault.

## Parameters

### `pCode` [in]

A SOAP fault code.

The list of possible fault codes follows. For a description of each fault code, see the

[SOAP Version 1.2 specification](https://www.w3.org/TR/2003/REC-soap12-part1-20030624/#faultcodes).

#### VersionMismatch

#### MustUnderstand

#### DataEncodingUnknown

#### Sender

#### Receiver

### `pSubCode` [in]

A fault subcode.

### `pReasons` [in]

A [WSD_LOCALIZED_STRING_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_localized_string_list) structure that contains a list of localized reason codes.

### `pszDetail` [in]

Contains application-specific error information pertaining to the fault.

### `ppFault` [out]

A [WSD_SOAP_FAULT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault) structure that contains the generated fault. *ppFault* must be freed with a call to [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszCode* or *pReasons* is **NULL**. |
| **E_POINTER** | *ppFault* is **NULL**. |

## Remarks

SOAP faults provide a way to communicate error information on failed SOAP messages. Different Web Services protocols extend faults to provide contextual error information, and in some cases, like in WS-Eventing, faults are an expected part of specific message patterns as the client determines whether or not the device supports specific features.

The following fault subcodes are not implemented by WSDAPI:

* InvalidMessageInformationHeader
* MessageInformationHeaderRequired
* UnsupportedExpirationType
* InvalidMessage
* FilteringNotSupported