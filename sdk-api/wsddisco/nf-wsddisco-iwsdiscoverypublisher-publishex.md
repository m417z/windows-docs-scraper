# IWSDiscoveryPublisher::PublishEx

## Description

Announces the presence of a network host by sending a [Hello](https://learn.microsoft.com/windows/desktop/WsdApi/hello-message) message with extended information.

## Parameters

### `pszId` [in]

The logical or physical address of the device, which is used as the device endpoint address. A logical address is of the form `urn:uuid:{guid}`. A physical address can be a URI prefixed by http or https, or simply a URI prefixed by `uri`. Whenever possible, use a logical address.

### `ullMetadataVersion` [in]

Current metadata version.

**Note** For compatibility with the WS-Discovery specification, this value must be less than or equal to UINT_MAX (4294967295).

### `ullInstanceId` [in]

Identifier for the current instance of the device being published. This identifier must be incremented whenever the service is restarted. For more information about instance identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

**Note** For compatibility with the WS-Discovery specification, this value must be less than or equal to UINT_MAX (4294967295).

### `ullMessageNumber` [in]

Counter within the scope of the instance identifier for the current message. The message number must be incremented for each message.

**Note** For compatibility with the WS-Discovery specification, this value must be less than or equal to UINT_MAX (4294967295).

### `pszSessionId` [in, optional]

Unique identifier within the scope of the instance identifier for the current session. This parameter corresponds to the sequence identifier in the AppSequence block in the Probe message. For more information about sequence identifiers, see Appendix I of the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

This parameter may be **NULL**.

### `pTypesList` [in, optional]

Pointer to a [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list) structure that represents the list of types supported by the publishing host. May be **NULL**.

### `pScopesList` [in, optional]

Pointer to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that represents the list of matching scopes supported by the publishing host. The list contains hash values in string form. May be **NULL**.

### `pXAddrsList` [in, optional]

Pointer to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that represents the list of transport addresses supported by the publishing host. Each transport address string contains an address and port number which can be used for connection by a remote host. May be **NULL**.

### `pHeaderAny` [in, optional]

Pointer to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains an XML element to be inserted in the "ANY" section of the header.

### `pReferenceParameterAny` [in, optional]

Pointer to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains an XML element to be inserted in the "ANY" section of the reference parameter properties.

### `pPolicyAny` [in, optional]

Not used.

### `pEndpointReferenceAny` [in, optional]

Pointer to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains an XML element to be inserted in the "ANY" section of the endpoint.

### `pAny` [in, optional]

Pointer to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains an XML element to be inserted in the "ANY" section of the message body.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more of the following conditions is true:<br><br>* *pszId* is **NULL**.<br>* The length in characters of *pszId* exceeds WSD_MAX_TEXT_LENGTH (8192).<br>* The length in characters of *pszSessionId* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **HRESULT_FROM_WIN32(ERROR_NO_CALLBACK_ACTIVE)** | There is no registered notification sink. To attach a sink, call [RegisterNotificationSink](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-registernotificationsink). |
| **E_ABORT** | The publisher has not been started. Attaching a notification sink starts the publisher. To attach a sink, call [RegisterNotificationSink](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-registernotificationsink). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

If successful, **PublishEx** will send a WS-Discovery Hello message to the local subnet with the provided information.

The parameters referring to [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structures can be used to extend the contents of the Hello message being sent with custom information.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)