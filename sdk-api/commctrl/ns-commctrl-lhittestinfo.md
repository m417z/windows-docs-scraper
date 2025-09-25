# LHITTESTINFO structure

## Description

Used to get information about the link corresponding to a given location.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Location for the hit-test, in client coordinates (not screen coordinates).

### `item`

Type: **[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem)**

Receives information about the link corresponding to **pt**.

## Remarks

To convert from screen coordinates to client coordinates, use [ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient).

**Note** If the [LM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/lm-hittest) message succeeds, the system fills in [LITEM.iLink](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem) and **LITEM.szID**. If the **LM_HITTEST** message fails, do not assume that any information in **LITEM** is valid.

## See also

[LM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/lm-hittest)

**Other Resources**

**Reference**

[ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient)