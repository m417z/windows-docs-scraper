# IWSDiscoveryPublisherNotify::ProbeHandler

## Description

Is called when a [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) is received by the discovery publisher.

## Parameters

### `pSoap` [in]

Pointer to a [WSD_SOAP_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_message) structure that contains the Probe message received by the discovery publisher.

### `pMessageParameters` [in]

Pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) interface that contains transport information associated with the received message.

## Return value

The return value is not meaningful. An implementer should return S_OK.

## Remarks

**ProbeHandler** is called whenever a [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) is received by the discovery publisher. It is the responsibility of the callback interface to then call [MatchProbe](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-matchprobe) or [MatchProbeEx](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-matchprobeex) with host information to determine whether or not the received Probe matches the host.

The body of the Probe message passed to *pSoap* can be cast to a [WSD_PROBE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_probe) structure.

## See also

[IWSDiscoveryPublisherNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublishernotify)