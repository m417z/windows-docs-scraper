# IWSDiscoveryPublisher::MatchResolve

## Description

Determines whether a [Resolve](https://learn.microsoft.com/windows/desktop/WsdApi/resolve-message) message matches the specified host and sends a WS-Discovery [ResolveMatches](https://learn.microsoft.com/windows/desktop/WsdApi/resolvematches-message) message if the match is made.

## Parameters

### `pResolveMessage` [in]

Pointer to a [WSD_SOAP_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_message) structure that represents the Resolve message passed in to the notification sink's [ResolveHandler](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublishernotify-resolvehandler).

### `pMessageParameters` [in]

Pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) object that represents the transmission parameters passed in to the notification sink's [ResolveHandler](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublishernotify-resolvehandler).

### `pszId` [in]

The logical or physical address of the device, which is used as the device endpoint address. A logical address is of the form `urn:uuid:{guid}`. A physical address can be a URI prefixed by http or https, or simply a URI prefixed by `uri`. Whenever possible, use a logical address.

### `ullMetadataVersion` [in]

Current metadata version.

**Note** For compatibility with the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf), this value must be less than or equal to UINT_MAX (4294967295).

### `ullInstanceId` [in]

Identifier for the current instance of the device being published. This identifier must be incremented whenever the service is restarted. For more information about instance identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

**Note** For compatibility with the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf), this value must be less than or equal to UINT_MAX (4294967295).

### `ullMessageNumber` [in]

Counter within the scope of the instance identifier for the current message. The message number must be incremented for each message.

**Note** For compatibility with the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf), this value must be less than or equal to UINT_MAX (4294967295).

### `pszSessionId` [in, optional]

Unique identifier within the scope of the instance identifier for the current session. This parameter corresponds to the sequence identifier in the AppSequence block in the Probe message. For more information about sequence identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

This parameter may be **NULL**.

### `pTypesList` [in, optional]

Pointer to a [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list) structure that represents the list of types supported by the publishing host. May be **NULL**. If *pTypesList* is specified, **MatchResolve** will use WS-Discovery matching logic to verify that the types match those specified in *pResolveMessage*.

### `pScopesList` [in, optional]

Pointer to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that represents the list of matching scopes supported by the publishing host. The list contains hash values in string form. May be **NULL**. If *pScopesList* is specified, **MatchResolve** will use WS-Discovery matching logic to verify that the scopes match those specified in *pResolveMessage*.

### `pXAddrsList` [in, optional]

Pointer to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that represents the list of transport addresses supported by the publishing host. Each transport address string contains an address and port number which can be used for connection by a remote host.*pXAddrsList* and *pXAddrsList->Element* may not be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more of the following conditions is true:<br><br>* *pszId* is **NULL**.<br>* The length in characters of *pszId* exceeds WSD_MAX_TEXT_LENGTH (8192).<br>* The length in characters of *pszSessionId* exceeds WSD_MAX_TEXT_LENGTH (8192).<br>* *pProbeMessage* is **NULL**. |
| **E_ABORT** | The publisher has not been started. Attaching a notification sink starts the publisher. To attach a sink, call [RegisterNotificationSink](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-registernotificationsink). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

**MatchResolve** should be called only when the discovery publisher has issued a [ResolveHandler](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublishernotify-resolvehandler) callback. *pResolveMessage* and *pMessageParameters* are passed directly from the callback into **MatchResolve**. The **ResolveHandler** also passes information required by the publisher to determine if the supplied Resolve message matches and, if so, to issue a ResolveMatches response if appropriate.

**MatchResolve** sends ResolveMatches messages on all bound adapters and automatically issues message retransmissions when required by WS-Discovery.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)