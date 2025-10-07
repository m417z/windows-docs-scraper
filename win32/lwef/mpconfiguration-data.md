# MPCONFIGURATION\_DATA structure

Contains data about configuration changes, including the old and new values.

## Members

**ConfigurationName**

Type: **MP\_MIDL\_STRING LPWSTR**

Name of the configuration that changed.

**DataType**

Type: **DWORD**

The type of data used.

**PreviousDataSize**

Type: **DWORD**

Size of previous data, in bytes.

**pPreviousData**

Type: **BYTE\***

Pointer to previous data.

**CurrentDataSize**

Type: **DWORD**

Size of new data, in bytes.

**pCurrentData**

Type: **BYTE\***

Pointer to new data.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

