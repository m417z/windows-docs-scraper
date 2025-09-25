# WSD_PROBE_MATCHES structure

## Description

Represents a [ProbeMatches](https://learn.microsoft.com/windows/desktop/WsdApi/probematches-message) message.

## Members

### `ProbeMatch`

Reference to a [WSD_PROBE_MATCH_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_probe_match_list) structure that contains the list of matches to the [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) message.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.

## See also

[Probe Message](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message)

[ProbeMatches Message](https://learn.microsoft.com/windows/desktop/WsdApi/probematches-message)

[WSD_PROBE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_probe)

[WSD_PROBE_MATCH](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_probe_match)

[WSD_PROBE_MATCH_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_probe_match_list)