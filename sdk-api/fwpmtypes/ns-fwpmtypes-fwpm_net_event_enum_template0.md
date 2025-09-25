## Description

The **FWPM_NET_EVENT_ENUM_TEMPLATE0** structure is used for enumerating net events.

## Members

### `startTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the start time of the period to be checked for net events.

### `endTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the end time of the period to be checked for net events. It must be greater than or equal to **startTime**.

### `numFilterConditions`

Indicates the number of filter conditions in the **filterCondition** member. If this field is 0, all events will be returned.

### `filterCondition`

An array of [FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0) structures that contain distinct filter conditions (duplicated filter conditions will generate an error). All conditions must be true for the action to be
performed. In other words, the conditions are AND'ed together. If no
conditions are specified, the action is always performed.

Supported filtering conditions.

| Value | Meaning |
| --- | --- |
| **FWPM_CONDITION_IP_PROTOCOL** | The IP protocol number, as specified in RFC 1700. |
| **FWPM_CONDITION_IP_LOCAL_ADDRESS** | The local IP address. |
| **FWPM_CONDITION_IP_REMOTE_ADDRESS** | The remote IP address. |
| **FWPM_CONDITION_IP_LOCAL_PORT** | The local transport protocol port number. For ICMP, the message type. |
| **FWPM_CONDITION_IP_REMOTE_PORT** | The remote transport protocol port number. For ICMP, the message code. |
| **FWPM_CONDITION_SCOPE_ID** | The interface IPv6 scope identifier. Reserved for internal use. |
| **FWPM_CONDITION_ALE_APP_ID** | The full path of the application. |
| **FWPM_CONDITION_ALE_USER_ID** | The identification of the local user. |
| **FWPM_CONDITION_NET_EVENT_TYPE** | The 32-bit event type to be notified of, as defined in the [FWPM_NET_EVENT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_net_event_type) enumeration. |

## Remarks

**FWPM_NET_EVENT_ENUM_TEMPLATE0** is a specific implementation of FWPM_NET_EVENT_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)

[Filtering Condition Identifiers](https://learn.microsoft.com/windows/desktop/FWP/filtering-condition-identifiers-)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)