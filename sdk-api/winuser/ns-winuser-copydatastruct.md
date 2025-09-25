# COPYDATASTRUCT structure

## Description

Contains data to be passed to another application by the [WM_COPYDATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-copydata) message.

## Members

### `dwData`

Type: **ULONG_PTR**

The type of the data to be passed to the receiving application. The receiving application defines the valid types.

### `cbData`

Type: **DWORD**

The size, in bytes, of the data pointed to by the **lpData** member.

### `lpData`

Type: **PVOID**

The data to be passed to the receiving application. This member can be **NULL**.

## See also

[WM_COPYDATA](https://learn.microsoft.com/windows/desktop/dataxchg/wm-copydata)