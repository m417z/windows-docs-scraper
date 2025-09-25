# IWSDiscoveryPublisher::UnPublish

## Description

Announces the departure of a network host by sending a [Bye](https://learn.microsoft.com/windows/desktop/WsdApi/bye-message) message.

## Parameters

### `pszId` [in]

The logical or physical address of the device, which is used as the device endpoint address. A logical address is of the form `urn:uuid:{guid}`. A physical address can be a URI prefixed by http or https, or simply a URI prefixed by `uri`. Whenever possible, use a logical address.

### `ullInstanceId` [in]

Identifier for the current instance of the device being published. This identifier must be incremented whenever the service is restarted. For more information about instance identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

**Note** For compatibility with the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf), this value must be less than or equal to UINT_MAX (4294967295).

### `ullMessageNumber` [in]

Counter within the scope of the instance identifier for the current message. The message number must be incremented for each message.

**Note** For compatibility with the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf), this value must be less than or equal to UINT_MAX (4294967295).

### `pszSessionId` [in, optional]

Unique identifier within the scope of the instance identifier for the current session. This parameter corresponds to the sequence identifier in the AppSequence block in the Probe message. For more information about sequence identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

This parameter may be **NULL**.

### `pAny` [in, optional]

Pointer to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains an XML element to be inserted in the "ANY" section of the message body.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more of the following conditions is true:<br><br>* *pszId* is **NULL**.<br>* The length of *pszId* exceeds WSD_MAX_TEXT_LENGTH (8192).<br>* The length of *pszSessionId* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_ABORT** | The publisher has not been started. Attaching a notification sink starts the publisher. To attach a sink, call [RegisterNotificationSink](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-registernotificationsink). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

If successful, **UnPublish** will send a WS-Discovery Bye message to the local subnet with the provided information.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)