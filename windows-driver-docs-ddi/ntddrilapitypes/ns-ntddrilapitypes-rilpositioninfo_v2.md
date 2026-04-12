# RILPOSITIONINFO_V2 structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents the RILPOSITIONINFO_V2.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwSystemType`

Indicates the system type or types for which serving cell information is valid, a bitmask of one or more [RILSYSTEMTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilsystemtype) values. For example, on an SVLTE system, this could be `RIL_SYSTEMTYPE_LTE|RIL_SYSTEMTYPE_1XRTT`, indicating that both the CDMA cell information (including serving cell(s)) in **rc2kMRL** and **stLTEServingCellInfo** are valid.

### `stGSMServingCellInfo`

GSM serving cell information, a [RILPOSITIONINFOGSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilpositioninfogsm) struct.

### `stUMTSServingCellInfo`

UMTS serving cell information, a [RILPOSITIONINFOUMTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilpositioninfoumts) struct.

### `stTDSCDMAServingCellInfo`

TD-SCDMA serving cell information, a [RILPOSITIONINFOTDSCDMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilpositioninfotdscdma) struct. This field is not present in [RILPOSITIONINFO_V1](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn931134(v=vs.85)).

### `stLTEServingCellInfo`

LTE serving cell information, a [RILPOSITIONINFOLTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilpositioninfolte) struct.

### `dwCntGSMNMR`

The number of GSM network measurement reports in **rgNMR**.

### `rgNMR\[15\]`

GSM network measurement reports, an array of [RILGSMNMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilgsmnmr) structs.

### `dwCntUMTSMRL`

The number of entries in the UMTS measured results list **ruMRL**.

### `ruMRL\[15\]`

UMTS measured results list, an array of [RILUMTSMRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilumtsmrl) structs.

### `dwCntTDSCDMAMRL`

The number of entries in the TD-SCDMA measured results list **rtMRL**. This field is not present in RILPOSITIONINFO_V1.

### `rtMRL\[15\]`

TD-SCDMA measured results list, an array of [RILTDSCDMAMRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-riltdscdmamrl) structs. This field is not present in RILPOSITIONINFO_V1.

### `dwCntEUTRAMRL`

The number of entries in the EUTRAN (LTE) measured results list **reMRL**.

### `reMRL\[15\]`

E-UTRAN (LTE) measured results list, an array of [RILEUTRAMRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rileutramrl) structs.

### `dwCntC2KMRL`

The number of entries in the cdma2000 measured results list **rc2kMRL**.

### `rc2kMRL\[12\]`

The cdma2000 measured results list, an array of [RILC2KMRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilc2kmrl) structs.

## Syntax

```cpp
struct RILPOSITIONINFO_V2 {
  DWORD                  cbSize;
  DWORD                  dwSystemType;
  RILPOSITIONINFOGSM     stGSMServingCellInfo;
  RILPOSITIONINFOUMTS    stUMTSServingCellInfo;
  RILPOSITIONINFOTDSCDMA stTDSCDMAServingCellInfo;
  RILPOSITIONINFOLTE     stLTEServingCellInfo;
  DWORD                  dwCntGSMNMR;
  RILGSMNMR              rgNMR[15];
  DWORD                  dwCntUMTSMRL;
  RILUMTSMRL             ruMRL[15];
  DWORD                  dwCntTDSCDMAMRL;
  RILTDSCDMAMRL          rtMRL[15];
  DWORD                  dwCntEUTRAMRL;
  RILEUTRAMRL            reMRL[15];
  DWORD                  dwCntC2KMRL;
  RILC2KMRL              rc2kMRL[12];
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))