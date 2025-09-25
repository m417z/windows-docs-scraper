# RTM_PREF_INFO structure

## Description

The
**RTM_PREF_INFO** structure contains the information used when comparing any two routes. The value of the **Preference** member is given more weight than the value of the **Metric** member.

## Members

### `Metric`

Specifies a metric. The metric is specific to a particular routing protocol.

### `Preference`

Specifies a preference. The preference is determined by the router policy.

## Remarks

Preference is more important than metric. The metric is only checked if the preferences are equal.

## See also

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)