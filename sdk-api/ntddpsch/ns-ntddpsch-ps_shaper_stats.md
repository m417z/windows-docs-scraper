# PS_SHAPER_STATS structure

## Description

The
**PS_SHAPER_STATS** structure provides statistical packet shaper information about the computer's packet shaper component. Note that the
**PS_SHAPER_STATS** structure is used in conjunction with the
[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats) structure.

## Members

### `MaxPacketsInShaper`

Maximum number of packets that have been in the packet shaper for the flow or interface.

### `AveragePacketsInShaper`

Average number of packets that have been in the packet shaper for the flow or interface.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats)