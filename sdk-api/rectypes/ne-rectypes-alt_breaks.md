# ALT_BREAKS enumeration

## Description

Specifiers how to create alternates from a best result string.

## Constants

### `ALT_BREAKS_SAME:0`

An alternate must use the same segment breaks as the best result string. For example, if you ask for an alternate list for the best result string of "together", the recognizer may return "Tunisia" but not "to get her". This is because "to get her" involves different segment breaks.

### `ALT_BREAKS_UNIQUE:1`

An alternate must have different segment breaks than the best result string. Only one such alternate is returned. For example, alternates for the best result string of "to get her" may include "to gather" and "together". However, "to got her" is not returned because it has the same segment break as "to get her".

### `ALT_BREAKS_FULL:2`

The top-rated alternates are returned regardless of segment breaks. Thus "together" may return "Tunisia", "to get her", and "to gather" among others. The alternates are returned in order of their rating, from best to worst.

## Remarks

Check the [dwRecoCapabilityFlags](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_attrs) member of the **RECO_ATTRS** structure to ensure the recognizer supports different alternate breaks.

## See also

[GetAlternateList Function](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms698163(v=vs.85))