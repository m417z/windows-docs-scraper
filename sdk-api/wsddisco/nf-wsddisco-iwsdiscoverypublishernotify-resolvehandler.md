# IWSDiscoveryPublisherNotify::ResolveHandler

## Description

Is called when a [Resolve](https://learn.microsoft.com/windows/desktop/WsdApi/resolve-message) is received by the discovery publisher.

## Parameters

### `pSoap` [in]

Pointer to a [WSD_SOAP_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_message) structure that contains the Resolve message received by the discovery publisher.

### `pMessageParameters` [in]

Pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) interface that contains transport information associated with the received message.

## Return value

The return value is not meaningful. An implementer should return S_OK.

## Remarks

**ResolveHandler** is called whenever a Resolve is received by the discovery publisher. It is the responsibility of the callback interface to then call [MatchResolve](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-matchresolve) or [MatchResolveEx](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-matchresolveex) with host information to determine whether or not the received Resolve matches the host.

## See also

[IWSDiscoveryPublisherNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublishernotify)