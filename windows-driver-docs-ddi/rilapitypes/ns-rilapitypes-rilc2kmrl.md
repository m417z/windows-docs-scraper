# RILC2KMRL structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `dwParams`

### `fServing`

### `dwNID`

### `dwSID`

### `dwBaseStationID`

### `dwBaseLat`

### `dwBaseLong`

### `dwRefPN`

### `dwGPSSeconds`

### `dwPilotStrength`

## Syntax

```cpp
typedef struct _RILC2KMRL {
  DWORD  dwParams;
  BOOL   fServing;
  DWORD  dwNID;
  DWORD  dwSID;
  DWORD  dwBaseStationID;
  DWORD  dwBaseLat;
  DWORD  dwBaseLong;
  DWORD  dwRefPN;
  DWORD  dwGPSSeconds;
  DWORD  dwPilotStrength;
} RILC2KMRL, RILC2KMRL;
```