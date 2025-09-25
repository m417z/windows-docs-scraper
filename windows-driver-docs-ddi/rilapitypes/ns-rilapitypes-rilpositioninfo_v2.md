# RILPOSITIONINFO_V2 structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwSystemType`

### `stGSMServingCellInfo`

### `stUMTSServingCellInfo`

### `stTDSCDMAServingCellInfo`

### `stLTEServingCellInfo`

### `dwCntGSMNMR`

### `rgNMR`

### `dwCntUMTSMRL`

### `ruMRL`

### `dwCntTDSCDMAMRL`

### `rtMRL`

### `dwCntEUTRAMRL`

### `reMRL`

### `dwCntC2KMRL`

### `rc2kMRL`

## Syntax

```cpp
typedef struct _RILPOSITIONINFO_V2 {
  DWORD                                       cbSize;
  DWORD                                       dwSystemType;
  RILPOSITIONINFOGSM                          stGSMServingCellInfo;
  RILPOSITIONINFOUMTS                         stUMTSServingCellInfo;
  RILPOSITIONINFOTDSCDMA                      stTDSCDMAServingCellInfo;
  RILPOSITIONINFOLTE                          stLTEServingCellInfo;
  DWORD                                       dwCntGSMNMR;
  RILGSMNMR [MAX_GSMPOS_COUNT_OF_NMR]         rgNMR;
  DWORD                                       dwCntUMTSMRL;
  RILUMTSMRL [MAX_UMTSPOS_COUNT_OF_MRL]       ruMRL;
  DWORD                                       dwCntTDSCDMAMRL;
  RILTDSCDMAMRL [MAX_TDSCDMAPOS_COUNT_OF_MRL] rtMRL;
  DWORD                                       dwCntEUTRAMRL;
  RILEUTRAMRL [MAX_EUTRAPOS_COUNT_OF_MRL]     reMRL;
  DWORD                                       dwCntC2KMRL;
  RILC2KMRL [MAX_C2KPOS_COUNT_OF_MRL]         rc2kMRL;
} RILPOSITIONINFO_V2, RILPOSITIONINFO_V2;
```