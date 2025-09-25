# RBHITTESTINFO structure

## Description

Contains information specific to a hit test operation. This structure is used with the [RB_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/rb-hittest) message.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that describes the point to be hit tested, in client coordinates.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Member that receives a flag value indicating the rebar band's component located at the point described by **pt**. This member will be one of the following:

| Value | Meaning |
| --- | --- |
| **RBHT_CAPTION** | The point was in the rebar band's caption. |
| **RBHT_CHEVRON** | The point was in the rebar band's chevron (version 5.80 and greater). |
| **RBHT_CLIENT** | The point was in the rebar band's client area. |
| **RBHT_GRABBER** | The point was in the rebar band's gripper. |
| **RBHT_NOWHERE** | The point was not in a rebar band. |
| **RBHT_SPLITTER** | The point was in the rebar band's splitter. |

### `iBand`

Type: **int**

Member that receives the rebar band's index at the point described by **pt**. This value will be the zero-based index of the band, or -1 if no band was at the hit-tested point.