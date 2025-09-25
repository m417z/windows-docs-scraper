# RILUICCSUBSCRIBERNUMBERS structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwNumSubscribers`

### `rsiInfo`

## Syntax

```cpp
typedef struct _RILUICCSUBSCRIBERNUMBERS {
  DWORD                 cbSize;
  DWORD                 dwNumSubscribers;
  RILSUBSCRIBERINFO [1] rsiInfo;
} RILUICCSUBSCRIBERNUMBERS, RILUICCSUBSCRIBERNUMBERS;
```