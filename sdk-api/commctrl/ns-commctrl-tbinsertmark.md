# TBINSERTMARK structure

## Description

Contains information on the insertion mark in a toolbar control.

## Members

### `iButton`

Type: **int**

Zero-based index of the insertion mark. If this member is -1, there is no insertion mark.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Defines where the insertion mark is in relation to
**iButton**. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **0** | The insertion mark is to the left of the specified button. |
| **TBIMHT_AFTER** | The insertion mark is to the right of the specified button. |
| **TBIMHT_BACKGROUND** | The insertion mark is on the background of the toolbar. This flag is only used with the [TB_INSERTMARKHITTEST](https://learn.microsoft.com/windows/desktop/Controls/tb-insertmarkhittest) message. |