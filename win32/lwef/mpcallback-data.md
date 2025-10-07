# MPCALLBACK\_DATA structure

Data passed to the callback function.

## Members

**Notify**

Type: **[**MPNOTIFY**](https://learn.microsoft.com/windows/win32/lwef/mpnotify)**

Change notification to report.

**hResult**

Type: **HRESULT**

Error code, in case of an internal failure.

**TimeStamp**

Type: **ULARGE\_INTEGER**

Current timestamp.

**Type**

Type: **[**MPCALLBACK\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-type)**

Callback special data type.

**Data**

Callback special data. The pointer to the appropriate structure depends on the value of **Type**.

**pStatusData**

Type: **PMPSTATUS\_DATA**

When **Type** == **MPCALLBACK\_STATUS**. See [**MPSTATUS\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-data).

**pScanData**

Type: **PMPSCAN\_DATA**

When **Type** == **MPCALLBACK\_SCAN**. See [**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data).

**pCleanData**

Type: **PMPCLEAN\_DATA**

When **Type** == **MPCALLBACK\_CLEAN**. See [**MPCLEAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpclean-data).

**pPrecheckData**

Type: **PMPCLEAN\_PRECHECK\_DATA**

When **Type** == **MPCALLBACK\_PRECHECK**. See [**MPCLEAN\_PRECHECK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpclean-precheck-data).

**pThreatData**

Type: **PMPTHREAT\_DATA**

When **Type** == **MPCALLBACK\_THREAT**. See [**MPTHREAT\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-data).

**pSigUpdateData**

Type: **PMPSIGUPDATE\_DATA**

When **Type** == **MPCALLBACK\_SIGUPDATE**. See [**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data).

**pSampleData**

Type: **PMPSAMPLE\_DATA**

When **Type** == **MPCALLBACK\_SAMPLE**. See [**MPSAMPLE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsample-data).

**pReservedData**

Type: **PMPRESERVED\_DATA**

When **Type** == **MPCALLBACK\_RESERVED**. See [**MPRESERVED\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpreserved-data).

**pConfigurationData**

Type: **PMPCONFIGURATION\_DATA**

When **Type** == **MPCALLBACK\_CONFIGURATION\_NOTIFICATION**. See [**MPCONFIGURATION\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpconfiguration-data).

**pFastPathData**

Type: **PMPFASTPATH\_DATA**

When **Type** == **MPCALLBACK\_FASTPATH**. See [**MPFASTPATH\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpfastpath-data).

**pExpirationData**

Type: **PMPEXPIRATION\_DATA**

When **Type** == **MPCALLBACK\_PRODUCT\_EXPIRATION**. See [**MPEXPIRATION\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpexpiration-data).

**pNISPrivateData**

Type: **PMPNIS\_PRIVATE\_DATA**

When **Type** == **MPCALLBACK\_NIS\_PRIVATE**. See [**MPNIS\_PRIVATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpnis-private-data).

**pHealthData**

Type: **PMPHEALTH\_DATA**

When **Type** == **MPCALLBACK\_HEALTH**. See [**MPHEALTH\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mphealth-data).

**pEndOfLifeData**

Type: **PMPENDOFLIFE\_DATA**

When **Type** == **MPCALLBACK\_ENDOFLIFE**. See [**MPENDOFLIFE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpendoflife-data).

**pMalwareToastData**

Type: **PMPMALWARETOAST\_DATA**

When **Type** == **MPCALLBACK\_MALWARETOAST**. See [**MPMALWARETOAST\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpmalwaretoast-data).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPCALLBACK\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-type)

[**MPCLEAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpclean-data)

[**MPCLEAN\_PRECHECK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpclean-precheck-data)

[**MPCONFIGURATION\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpconfiguration-data)

[**MPENDOFLIFE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpendoflife-data)

[**MPEXPIRATION\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpexpiration-data)

[**MPFASTPATH\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpfastpath-data)

[**MPHEALTH\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mphealth-data)

[**MPMALWARETOAST\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpmalwaretoast-data)

[**MPNIS\_PRIVATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpnis-private-data)

[**MPNOTIFY**](https://learn.microsoft.com/windows/win32/lwef/mpnotify)

[**MPRESERVED\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpreserved-data)

[**MPSAMPLE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsample-data)

[**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data)

[**MPSIGUPDATE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsigupdate-data)

[**MPSTATUS\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-data)

[**MPTHREAT\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-data)

