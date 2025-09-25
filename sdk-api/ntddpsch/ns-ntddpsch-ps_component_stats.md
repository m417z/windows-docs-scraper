# PS_COMPONENT_STATS structure

## Description

The
**PS_COMPONENT_STATS** structure enables applications to get statistical information regarding their TC-enabled flow. This structure obtains information from GUID_QOS_STATISTICS_BUFFER GUID. This GUID actually is an array of
**PS_COMPONENT_STATS**, with each element of that array (each
**PS_COMPONENT_STATS** structure) containing one of the five PS_* structure types explained subsequently.

## Members

### `Type`

Indicates the type of PS_* structure contained in the **Stats** member.

This member must contain one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_ADAPTER_STATS (1)** | **Stats** is a pointer to a [PS_ADAPTER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_adapter_stats) structure. |
| **PS_FLOW_STATS (2)** | **Stats** is a pointer to a [PS_FLOW_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_flow_stats) structure. |
| **PS_CONFORMER_STATS (3)** | **Stats** is a pointer to a [PS_CONFORMER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_conformer_stats) structure. |
| **PS_SHAPER_STATS (4)** | **Stats** is a pointer to a [PS_SHAPER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_shaper_stats) structure. |
| **PS_DRRSEQ_STATS (5)** | **Stats** is a pointer to a [PS_DRRSEQ_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_drrseq_stats) structure. |

### `Length`

Length of the **Stats** member, in bytes.

### `Stats`

Array of structures of the type indicated in the **Type** member.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[PS_ADAPTER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_adapter_stats)

[PS_CONFORMER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_conformer_stats)

[PS_DRRSEQ_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_drrseq_stats)

[PS_FLOW_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_flow_stats)

[PS_SHAPER_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_shaper_stats)